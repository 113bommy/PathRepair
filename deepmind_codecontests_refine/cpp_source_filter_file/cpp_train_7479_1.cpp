#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;
typedef long long LL;
#define x first
#define y second

int n;
LL k;
LL a[maxn];
pair<LL,int> sum[maxn];
int rank[maxn];
LL ans,bit[maxn];

int lowbit(int p)
{
	return p&(-p);
}

LL search(int p)
{
	LL ans=0;
	while(p>0)
	{
		ans+=bit[p];
		p-=lowbit(p);
	}
	return ans;
}

void add(int p)
{
	while(p<=n)
	{
		bit[p]++;
		p+=lowbit(p);
	}
	return;
}

int main()
{
	scanf("%d%lld",&n,&k);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a[i]);
		a[i]-=k;
		sum[i].x=sum[i-1].x+a[i];
		sum[i].y=i;
		if (sum[i].x>0) ans++; 
	}
	sort(sum+1,sum+n+1);
	
	for(int i=1;i<=n;i++)
	    rank[sum[i].y]=i;
	
	for(int i=1;i<=n;i++)
	{
		ans+=search(rank[i]-1);
		add(rank[i]);
	}
	printf("%lld\n",ans);
	return 0;
}