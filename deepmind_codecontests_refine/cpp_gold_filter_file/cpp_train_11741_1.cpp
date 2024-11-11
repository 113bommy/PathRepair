#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int n,a[N],v[N];
signed main(){
	scanf("%lld",&n);
	for (int i=0;i<=n;i++)scanf("%lld",&a[i]);
	if (n==0){
		if (a[0]==1){
			puts("1");
			return 0;
		}
		else {
			puts("-1");
			return 0;
		}
	}
	if (a[0]){
		puts("-1");
		return 0;
	}
	int Max=1,s=0;
	for (int i=1;i<=n;i++)
		if (a[i]>Max*2){
			puts("-1");
			return 0;
		}
		else v[i-1]=Max,Max=min(1000000000000000ll,Max*2-a[i]);
	int ans=0;
	for (int i=0;i<=n;i++)ans+=a[i];
	for (int i=n-1;i>=0;i--)v[i]=min(v[i],v[i+1]+a[i+1]),ans+=v[i];
	printf("%lld\n",ans+s);
}
