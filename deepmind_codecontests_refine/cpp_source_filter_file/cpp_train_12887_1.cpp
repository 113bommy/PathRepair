#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
signed main()
{
    
	int n;
	long long ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans=ans+max(0,lower_bound(a+1,a+n+1,a[i]+a[j])-a-1-j);
	printf("%lld",ans);
	return 0;
}