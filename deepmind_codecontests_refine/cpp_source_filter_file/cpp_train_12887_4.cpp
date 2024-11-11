#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e3+10;
int n,a[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=max(0,lower_bound(a+1+j,a+1+n,a[i]+a[j])-upper_bound(a+1+j,a+1+n,a[j]-a[i]));
	printf("%d",ans);
	return 0;
}