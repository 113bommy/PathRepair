#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<Cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 510;
const int maxm = 210000;

int n,m;
struct edge{int x,y;}a[maxm];
bitset<maxn>S[maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&a[i].x,&a[i].y);
	
	for(int i=1;i<=n;i++)
	{
		S[i][i]=1;
		for(int j=m;j>=1;j--)
		{
			int x=a[j].x,y=a[j].y;
			if(S[i][x]&&S[i][y]) { S[i].set(); break; }
			if(!S[i][x]&&!S[i][y]) continue;
			if(S[i][x]) S[i][y]=1;
			else S[i][x]=1;
		}
	}
	
	int ans=0;
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) if((S[i]&S[j]).count()==0)
		ans++;
	printf("%d\n",ans);
	
	return 0;
}
