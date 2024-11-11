#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=998244353;
int N,M,i,inv[1000005],jc[1000005],rjc[1000005],ans,;
int C(int n,int m)
{
	return 1ll*jc[n]*rjc[m]%md*rjc[n-m]%md;
}
int main()
{
	inv[1]=1;
	for(i=2;i<=1000000;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	jc[0]=rjc[0]=1;
	for(i=1;i<=1000000;++i)
		jc[i]=1ll*jc[i-1]*i%md,rjc[i]=1ll*rjc[i-1]*inv[i]%md;
	scanf("%d%d",&N,&M);
	if(N<M)
		swap(N,M);
	ans=N;
	for(i=1;i<=M;++i)
		ans=(ans+1ll*inv[2]*jc[N]%md*rjc[i]%md*jc[M]%md*rjc[i]%md*rjc[N+M]%md*jc[2*i]%md*C(N-i+M-i,M-i)%md)%md;
	printf("%d",ans);
	return 0;
}
