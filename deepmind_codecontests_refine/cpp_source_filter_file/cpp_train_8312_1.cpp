#include<cstdio>
#include<algorithm>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
using namespace std;
const int mod=924844033;
const int N=5011
int n,k,tot,ans;
int f[N][N][2],fac[N];
bool vis[N][2];
int ed[N];
int main(){
	scanf("%d%d",&n,&k);
	f[1][0][0]=1;
	rep(i,1,n)
		rep(j,0,1)
			if(!vis[i][j]){
				for(register int x=i,y=j;x<=n;x+=k,y^=1)
					vis[x][y]=1,++tot;
				ed[tot]=1;
			}
	rep(i,1,tot)
		rep(j,0,n){
			f[i+1][j][0]=(f[i][j][0]+f[i][j][1])%mod;
			if(!ed[i])f[i+1][j+1][1]=f[i][j][0];
		}
	fac[0]=1;
	rep(i,1,n)
		fac[i]=1ll*i*fac[i-1]%mod;
	rep(i,0,n){
		int s=i&1;
		if(s)s=-1;
		else s=1;
		ans=(ans+1ll*s*(f[tot][i][0]+f[tot][i][1])*fac[n-i]%mod)%mod;
		ans=(ans+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}