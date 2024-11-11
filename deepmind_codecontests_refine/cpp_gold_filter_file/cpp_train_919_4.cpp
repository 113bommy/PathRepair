#include<cstdio>
#include<algorithm>
using std::max;
const int N=1e5+3;
int i,n,k,a[N];
long long x,r,l[N],s[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
		l[i]=l[i-1]+max(0,a[i]);
	}
	for(i=n;i>=k;x+=max(0,a[i--]))
		r=max(r,x+l[i-k]+max(0ll,s[i]-s[i-k]));
	printf("%lld",r);
}