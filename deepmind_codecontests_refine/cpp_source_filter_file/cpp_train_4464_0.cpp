#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define mod 1000000007
#define N 4050
#define m 2001
#define M 200050
typedef long long ll;
int f[N][N],n;
struct A {
	int x,y;
}a[M];
ll fac[M],inv[M];
const ll inv2=(mod+1)/2;
ll qp(ll x,ll y) {
	ll re=1;
	for(;y;y>>=1,x=x*x%mod) if(y&1) re=re*x%mod; return re;
}
ll C(int x,int y) {
	if(x<y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main() {
	scanf("%d",&n);
	int i,j;
	for(fac[0]=i=1;i<M;i++) fac[i]=fac[i-1]*i%mod;
	inv[M-1]=qp(fac[M-1],mod-2);
	for(i=M-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i].x,&a[i].y);
		f[m-a[i].x][m-a[i].y]++;
	}
	ll ans=0;
	int lim=m<<1;
	for(i=1;i<=lim;i++) {
		for(j=1;j<=lim;j++) {
			f[i][j]=(ll(f[i][j])+f[i-1][j)+f[i][j-1])%mod;
		}
	}
	for(i=1;i<=n;i++) {
		ans=(ans+f[m+a[i].x][m+a[i].y])%mod;
		ans=(ans-C(a[i].x*2+a[i].y*2,a[i].x*2))%mod;
	}
	ans=ans*inv2%mod;
	printf("%lld\n",(ans%mod+mod)%mod);
}
