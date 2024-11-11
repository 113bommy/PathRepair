#include <bits/stdc++.h>
#define N 200005
#define p 1000000007
using namespace std;

int n,m,ct,tmp_ct,x[N],y[N],a[N];
pair <int,int>P[N];
long long sum[N];
vector<int>Ve[N];

inline int lowbit(int x){return x&-x;}

inline void add(int x,int y){for(int i=x;i<=tmp_ct+1;i+=lowbit(i))(sum[i]+=y)%=p;}

inline long long ask(int x){long long tmp=0;for(int i=x;i;i-=lowbit(i))(tmp+=sum[i])%=p;return tmp;}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&y[i]);
	for(int i=1;i<=n;i++)
	{
		if(x[i]<y[1]||x[i]>y[m])continue;
		int pos=upper_bound(y+1,y+1+m,x[i])-y;
		P[++ct]=make_pair(y[pos]-x[i],x[i]-y[pos-1]);
	}
	sort(P+1,P+1+ct);
	for(int i=1;i<=ct;i++)
		a[2*i-1]=P[i].first,a[2*i]=P[i].second;
	sort(a+1,a+1+2*ct);
	tmp_ct=unique(a+1,a+1+2*ct)-a-1;
	for(int i=1;i<=ct;i++)
	{
		P[i].first=lower_bound(a+1,a+1+tmp_ct,P[i].first)-a;
		P[i].second=lower_bound(a+1,a+1+tmp_ct,P[i].second)-a;
		Ve[P[i].first].push_back(P[i].second);
	}
	add(1,1);
	for(int i=1;i<=tmp_ct;i++)
	{
		int las=0;
		for(vector<int>::reverse_iterator it=Ve[i].rbegin();it!=Ve[i].rend();it++)
			if(*it!=las)add(*it+1,ask(*it)),las=*it;
	}
	printf("%lld",ask(tmp_ct+1));
}
