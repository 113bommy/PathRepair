#include<cstdio>
using namespace std;
const int N=2e5+5;
const int mo=1e9+7;
int n,ans,a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n-1;i;i--) b[i]=(b[i+1]+a[i])%mo;
	for (int i=1;i<n;i++) ans=(ans+(long long)a[i]*b[i+1])%mo;
	printf("%d",ans);
	return 0;
}