#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=2e5+5;
const int mod=1e9+7;
vector<int>g[maxm];
int mul[maxm];
int sz[maxm];
int n;
int ppow(int a,int b,int mod){
	int ans=1%mod;a%=mod;
	whlie(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void dfs1(int x,int fa){
    sz[x]=1;
    for(int v:g[x]){
        if(v==fa)continue;
        dfs1(v,x);
        sz[x]+=sz[v];
        mul[x]=mul[x]*mul[v]%mod;
    }
    mul[x]=mul[x]*sz[x]%mod;
}
void dfs2(int x,int fa){
    for(int v:g[x]){
        if(v==fa)continue;
        //mul[x]是正确的
        int pre=mul[x]*ppow(n,mod-2,mod)%mod*ppow(mul[v],mod-2,mod)%mod*(n-sz[v])%mod;
        mul[v]=mul[v]*ppow(sz[v],mod-2,mod)%mod*pre%mod*n%mod;
        dfs2(v,x);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)mul[i]=1;
    dfs1(1,-1);
    dfs2(1,-1);
    int nn=1;
    for(int i=1;i<=n;i++){//计算阶乘
        nn=nn*i%mod;
    }
    for(int i=1;i<=n;i++){
        cout<<nn*ppow(mul[i],mod-2,mod)%mod<<endl;
    }
    return 0;
}