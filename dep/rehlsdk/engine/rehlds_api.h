/*
*
*    This program is free software; you can redistribute it and/or modify it
*    under the terms of the GNU General Public License as published by the
*    Free Software Foundation; either version 2 of the License, or (at
*    your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but
*    WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software Foundation,
*    Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*    In addition, as a special exception, the author gives permission to
*    link the code of this program with the Half-Life Game Engine ("HL
*    Engine") and Modified Game Libraries ("MODs") developed by Valve,
*    L.L.C ("Valve").  You must obey the GNU General Public License in all
*    respects for all of the code used other than the HL Engine and MODs
*    from Valve.  If you modify this file, you may extend this exception
*    to your version of the file, but you are not obligated to do so.  If
*    you do not wish to do so, delete this exception statement from your
*    version.
*
*/
#pragma once
#include "archtypes.h"
#include "cmd_rehlds.h"
#include "rehlds_interfaces.h"
#include "hookchains.h"
#include "FlightRecorder.h"
#include "interface.h"
#include "model.h"

#define REHLDS_API_VERSION_MAJOR 2
#define REHLDS_API_VERSION_MINOR 4

//Steam_NotifyClientConnect hook
typedef IHookChain<qboolean, IGameClient*, const void*, unsigned int> IRehldsHook_Steam_NotifyClientConnect;
typedef IHookChainRegistry<qboolean, IGameClient*, const void*, unsigned int> IRehldsHookRegistry_Steam_NotifyClientConnect;

//SV_ConnectClient hook
typedef IVoidHookChain<> IRehldsHook_SV_ConnectClient;
typedef IVoidHookChainRegistry<> IRehldsHookRegistry_SV_ConnectClient;

//SV_GetIDString hook
typedef IHookChain<char*, USERID_t*> IRehldsHook_SV_GetIDString;
typedef IHookChainRegistry<char*, USERID_t*> IRehldsHookRegistry_SV_GetIDString;

//SV_SendServerinfo hook
typedef IVoidHookChain<sizebuf_t*, IGameClient*> IRehldsHook_SV_SendServerinfo;
typedef IVoidHookChainRegistry<sizebuf_t*, IGameClient*> IRehldsHookRegistry_SV_SendServerinfo;

//SV_CheckProtocol hook
typedef IHookChain<int, netadr_t*, int> IRehldsHook_SV_CheckProtocol;
typedef IHookChainRegistry<int, netadr_t*, int> IRehldsHookRegistry_SV_CheckProtocol;

//SVC_GetChallenge_mod hook
typedef IVoidHookChain<char*, int> IRehldsHook_SVC_GetChallenge_mod;
typedef IVoidHookChainRegistry<char*, int> IRehldsHookRegistry_SVC_GetChallenge_mod;

//SV_CheckKeyInfo hook
typedef IHookChain<int, netadr_t*, char*, uint16*, int*, char*, char*> IRehldsHook_SV_CheckKeyInfo;
typedef IHookChainRegistry<int, netadr_t*, char*, uint16*, int*, char*, char*> IRehldsHookRegistry_SV_CheckKeyInfo;

//SV_CheckIPRestrictions hook
typedef IHookChain<int, netadr_t*, int> IRehldsHook_SV_CheckIPRestrictions;
typedef IHookChainRegistry<int, netadr_t*, int> IRehldsHookRegistry_SV_CheckIPRestrictions;

//SV_FinishCertificateCheck hook
typedef IHookChain<int, netadr_t*, int, char*, char*> IRehldsHook_SV_FinishCertificateCheck;
typedef IHookChainRegistry<int, netadr_t*, int, char*, char*> IRehldsHookRegistry_SV_FinishCertificateCheck;

//Steam_NotifyBotConnect hook
typedef IHookChain<qboolean, IGameClient*> IRehldsHook_Steam_NotifyBotConnect;
typedef IHookChainRegistry<qboolean, IGameClient*> IRehldsHookRegistry_Steam_NotifyBotConnect;

//SerializeSteamId
typedef IVoidHookChain<USERID_t*> IRehldsHook_SerializeSteamId;
typedef IVoidHookChainRegistry<USERID_t*> IRehldsHookRegistry_SerializeSteamId;

//SV_CompareUserID hook
typedef IHookChain<qboolean, USERID_t*, USERID_t*> IRehldsHook_SV_CompareUserID;
typedef IHookChainRegistry<qboolean, USERID_t*, USERID_t*> IRehldsHookRegistry_SV_CompareUserID;

//Steam_NotifyClientDisconnect
typedef IVoidHookChain<IGameClient*> IRehldsHook_Steam_NotifyClientDisconnect;
typedef IVoidHookChainRegistry<IGameClient*> IRehldsHookRegistry_Steam_NotifyClientDisconnect;

//PreProcessPacket
typedef IHookChain<bool, uint8*, unsigned int, const netadr_t&> IRehldsHook_PreprocessPacket;
typedef IHookChainRegistry<bool, uint8*, unsigned int, const netadr_t&> IRehldsHookRegistry_PreprocessPacket;

//ValidateCommand
typedef IHookChain<bool, const char*, cmd_source_t, IGameClient*> IRehldsHook_ValidateCommand;
typedef IHookChainRegistry<bool, const char*, cmd_source_t, IGameClient*> IRehldsHookRegistry_ValidateCommand;

//ExecuteServerStringCmd
typedef IVoidHookChain<const char*, cmd_source_t, IGameClient*> IRehldsHook_ExecuteServerStringCmd;
typedef IVoidHookChainRegistry<const char*, cmd_source_t, IGameClient*> IRehldsHookRegistry_ExecuteServerStringCmd;

//ClientConnected
typedef IVoidHookChain<IGameClient*> IRehldsHook_ClientConnected;
typedef IVoidHookChainRegistry<IGameClient*> IRehldsHookRegistry_ClientConnected;

//HandleNetCommand
typedef IVoidHookChain<IGameClient*, int8> IRehldsHook_HandleNetCommand;
typedef IVoidHookChainRegistry<IGameClient*, int8> IRehldsHookRegistry_HandleNetCommand;

//Mod_LoadBrushModel
typedef IVoidHookChain<model_t*, void*> IRehldsHook_Mod_LoadBrushModel;
typedef IVoidHookChainRegistry<model_t*, void*> IRehldsHookRegistry_Mod_LoadBrushModel;

//Mod_LoadStudioModel
typedef IVoidHookChain<model_t*, void*> IRehldsHook_Mod_LoadStudioModel;
typedef IVoidHookChainRegistry<model_t*, void*> IRehldsHookRegistry_Mod_LoadStudioModel;

//SV_EmitEvents hook
typedef IVoidHookChain<IGameClient *, struct packet_entities_s *, sizebuf_t *> IRehldsHook_SV_EmitEvents;
typedef IVoidHookChainRegistry<IGameClient *, struct packet_entities_s *, sizebuf_t *> IRehldsHookRegistry_SV_EmitEvents;

//EV_PlayReliableEvent hook
typedef IVoidHookChain<IGameClient *, int, short unsigned int, float, struct event_args_s *> IRehldsHook_EV_PlayReliableEvent;
typedef IVoidHookChainRegistry<IGameClient *, int, short unsigned int, float, struct event_args_s *> IRehldsHookRegistry_EV_PlayReliableEvent;

//SV_StartSound hook
typedef IVoidHookChain<int , edict_t *, int, const char *, int, float, int, int> IRehldsHook_SV_StartSound;
typedef IVoidHookChainRegistry<int , edict_t *, int, const char *, int, float, int, int> IRehldsHookRegistry_SV_StartSound;

//PF_Remove_I hook
typedef IVoidHookChain<edict_t *> IRehldsHook_PF_Remove_I;
typedef IVoidHookChainRegistry<edict_t *> IRehldsHookRegistry_PF_Remove_I;

//PF_BuildSoundMsg_I hook
typedef IVoidHookChain<edict_t *, int, const char *, float, float, int, int, int, int, const float *, edict_t *> IRehldsHook_PF_BuildSoundMsg_I;
typedef IVoidHookChainRegistry<edict_t *, int, const char *, float, float, int, int, int, int, const float *, edict_t *> IRehldsHookRegistry_PF_BuildSoundMsg_I;

//SV_WriteFullClientUpdate hook
typedef IVoidHookChain<IGameClient *, char *, size_t, sizebuf_t *, IGameClient *> IRehldsHook_SV_WriteFullClientUpdate;
typedef IVoidHookChainRegistry<IGameClient *, char *, size_t, sizebuf_t *, IGameClient *> IRehldsHookRegistry_SV_WriteFullClientUpdate;

//SV_CheckConsistencyResponse hook
typedef IHookChain<bool, IGameClient *, resource_t *, uint32> IRehldsHook_SV_CheckConsistencyResponse;
typedef IHookChainRegistry<bool, IGameClient *, resource_t *, uint32> IRehldsHookRegistry_SV_CheckConsistencyResponse;

//SV_DropClient hook
typedef IVoidHookChain<IGameClient*, bool, const char*> IRehldsHook_SV_DropClient;
typedef IVoidHookChainRegistry<IGameClient*, bool, const char*> IRehldsHookRegistry_SV_DropClient;

//SV_ActivateServer hook
typedef IVoidHookChain<int> IRehldsHook_SV_ActivateServer;
typedef IVoidHookChainRegistry<int> IRehldsHookRegistry_SV_ActivateServer;

//SV_WriteVoiceCodec hook
typedef IVoidHookChain<sizebuf_t *> IRehldsHook_SV_WriteVoiceCodec;
typedef IVoidHookChainRegistry<sizebuf_t *> IRehldsHookRegistry_SV_WriteVoiceCodec;

class IRehldsHookchains {
public:
	virtual ~IRehldsHookchains() { }

	virtual IRehldsHookRegistry_Steam_NotifyClientConnect* Steam_NotifyClientConnect() = 0;
	virtual IRehldsHookRegistry_SV_ConnectClient* SV_ConnectClient() = 0;
	virtual IRehldsHookRegistry_SV_GetIDString* SV_GetIDString() = 0;
	virtual IRehldsHookRegistry_SV_SendServerinfo* SV_SendServerinfo() = 0;
	virtual IRehldsHookRegistry_SV_CheckProtocol* SV_CheckProtocol() = 0;
	virtual IRehldsHookRegistry_SVC_GetChallenge_mod* SVC_GetChallenge_mod() = 0;
	virtual IRehldsHookRegistry_SV_CheckKeyInfo* SV_CheckKeyInfo() = 0;
	virtual IRehldsHookRegistry_SV_CheckIPRestrictions* SV_CheckIPRestrictions() = 0;
	virtual IRehldsHookRegistry_SV_FinishCertificateCheck* SV_FinishCertificateCheck() = 0;
	virtual IRehldsHookRegistry_Steam_NotifyBotConnect* Steam_NotifyBotConnect() = 0;
	virtual IRehldsHookRegistry_SerializeSteamId* SerializeSteamId() = 0;
	virtual IRehldsHookRegistry_SV_CompareUserID* SV_CompareUserID() = 0;
	virtual IRehldsHookRegistry_Steam_NotifyClientDisconnect* Steam_NotifyClientDisconnect() = 0;
	virtual IRehldsHookRegistry_PreprocessPacket* PreprocessPacket() = 0;
	virtual IRehldsHookRegistry_ValidateCommand* ValidateCommand() = 0;
	virtual IRehldsHookRegistry_ClientConnected* ClientConnected() = 0;
	virtual IRehldsHookRegistry_HandleNetCommand* HandleNetCommand() = 0;
	virtual IRehldsHookRegistry_Mod_LoadBrushModel* Mod_LoadBrushModel() = 0;
	virtual IRehldsHookRegistry_Mod_LoadStudioModel* Mod_LoadStudioModel() = 0;
	virtual IRehldsHookRegistry_ExecuteServerStringCmd* ExecuteServerStringCmd() = 0;
	virtual IRehldsHookRegistry_SV_EmitEvents* SV_EmitEvents() = 0;
	virtual IRehldsHookRegistry_EV_PlayReliableEvent* EV_PlayReliableEvent() = 0;
	virtual IRehldsHookRegistry_SV_StartSound* SV_StartSound() = 0;
	virtual IRehldsHookRegistry_PF_Remove_I* PF_Remove_I() = 0;
	virtual IRehldsHookRegistry_PF_BuildSoundMsg_I* PF_BuildSoundMsg_I() = 0;
	virtual IRehldsHookRegistry_SV_WriteFullClientUpdate* SV_WriteFullClientUpdate() = 0;
	virtual IRehldsHookRegistry_SV_CheckConsistencyResponse* SV_CheckConsistencyResponse() = 0;
	virtual IRehldsHookRegistry_SV_DropClient* SV_DropClient() = 0;
	virtual IRehldsHookRegistry_SV_ActivateServer* SV_ActivateServer() = 0;
	virtual IRehldsHookRegistry_SV_WriteVoiceCodec* SV_WriteVoiceCodec() = 0;
};

struct RehldsFuncs_t {
	void(*DropClient)(IGameClient* cl, bool crash, const char* fmt, ...);
	void(*RejectConnection)(netadr_t *adr, char *fmt, ...);
	qboolean(*SteamNotifyBotConnect)(IGameClient* cl);
	sizebuf_t*(*GetNetMessage)();
	IGameClient*(*GetHostClient)();
	int*(*GetMsgReadCount)();
	qboolean(*FilterUser)(USERID_t*);
	void(*NET_SendPacket)(unsigned int length, void *data, const netadr_t &to);
	void(*TokenizeString)(char* s);
	bool(*CheckChallenge)(const netadr_t& adr, int challenge);
	void(*SendUserReg)(sizebuf_t* msg);
	void(*WriteDeltaDescriptionsToClient)(sizebuf_t* msg);
	void(*SetMoveVars)();
	void(*WriteMovevarsToClient)(sizebuf_t* msg);
	char*(*GetClientFallback)();
	int*(*GetAllowCheats)();
	bool(*GSBSecure)();
	int(*GetBuildNumber)();
	double(*GetRealTime)();
	int*(*GetMsgBadRead)();
	cmd_source_t*(*GetCmdSource)();
	void(*Log)(const char* prefix, const char* msg);
	DLL_FUNCTIONS *(*GetEntityInterface)();
	void(*EV_PlayReliableEvent)(IGameClient *cl, int entindex, short unsigned int eventindex, float delay, struct event_args_s *pargs);
	int(*SV_LookupSoundIndex)(const char *sample);
	void(*MSG_StartBitWriting)(sizebuf_t *buf);
	void(*MSG_WriteBits)(uint32 data, int numbits);
	void(*MSG_WriteBitVec3Coord)(const float *fa);
	void(*MSG_EndBitWriting)(sizebuf_t *buf);
	void*(*SZ_GetSpace)(sizebuf_t *buf, int length);
	cvar_t*(*GetCvarVars)();
	int (*SV_GetChallenge)(const netadr_t& adr);
	void (*SV_AddResource)(resourcetype_t type, const char *name, int size, unsigned char flags, int index);
	int(*MSG_ReadShort)(void);
	int(*MSG_ReadBuf)(int iSize, void *pbuf);
	void(*MSG_WriteBuf)(sizebuf_t *sb, int iSize, void *buf);
	void(*MSG_WriteByte)(sizebuf_t *sb, int c);
	void(*MSG_WriteShort)(sizebuf_t *sb, int c);
	void(*MSG_WriteString)(sizebuf_t *sb, const char *s);
	void*(*GetPluginApi)(const char *name);
	void(*RegisterPluginApi)(const char *name, void *impl);
};

class IRehldsApi {
public:
	virtual ~IRehldsApi() {	}

	virtual int GetMajorVersion() = 0;
	virtual int GetMinorVersion() = 0;
	virtual const RehldsFuncs_t* GetFuncs() = 0;
	virtual IRehldsHookchains* GetHookchains() = 0;
	virtual IRehldsServerStatic* GetServerStatic() = 0;
	virtual IRehldsServerData* GetServerData() = 0;
	virtual IRehldsFlightRecorder* GetFlightRecorder() = 0;
};

#define VREHLDS_HLDS_API_VERSION "VREHLDS_HLDS_API_VERSION001"
