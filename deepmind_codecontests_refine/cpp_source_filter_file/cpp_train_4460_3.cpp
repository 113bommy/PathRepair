#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
ll dp[maxn],n,a[maxn],anss,l[maxn],r[maxn],id,ans[maxn],tail;
int main()
{
	scanf("%lld",&n);
	dp[0]=-0x3f3f3f3f;
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]),dp[i]=a[i];
	for(int i=1;i<=n;++i) 
	for(int j=1;j<i;++j) 
	{
		if((i-j)%2==0)
		if(dp[j]+a[i]>dp[i]) dp[i]=max(dp[i],dp[j]+a[i]),l[i]=j;
	}
	for(int i=1;i<=n;++i) if(dp[i]>dp[id]) id=i;
	
	ll ans1=0;
	for(int i=1;i<=n;i+=2)
		if(a[i]>0) ans1+=a[i];
		
	ll ans2=0;
	for(int i=2;i<=n;i+=2)
		if(a[i]>0) ans2+=a[i];
	
	if(ans1==0 && ans2==0){
		ans1=-inf;
		for(int i=1;i<=n;i++)
			ans1=max(ans1,a[i]);
	}
	else ans1=max(ans1,ans2);
	cout<<ans1<<endl;

	for(int i=n;i>id;--i) ans[++tail]=i;
	while(l[id]!=0){
		int mid=(id+l[id])>>1;
		for(int i=mid;i>l[id];--i)
		ans[++tail]=i;
		id=l[id];
	}
	for(int i=1;i<id;++i) ans[++tail]=1;
	printf("%lld\n",tail);
	for(int i=1;i<=tail;++i) printf("%lld\n",ans[i]);
	
	return 0;
}
