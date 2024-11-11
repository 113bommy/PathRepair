#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int M=2e5+5;
int h[M],a[M];

LL bit[M];
inline int lowbit(int x)
{
	return x&(-x);
}
void upd(int p,LL v)
{
	for(;p<M;p+=lowbit(p))
		bit[p]=max(bit[p],v);
}
LL getmx(int p)
{
	LL mx=0;
	for(;p;p-=lowbit(p))
		mx=max(mx,bit[p]);
	return mx;
}

int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		int id=h[i];
		LL dp=getmx(id-1)+a[i];
		ans=max(ans,dp);
		upd(id,dp);
	}
	printf("%lld\n",ans);
	return 0;
}