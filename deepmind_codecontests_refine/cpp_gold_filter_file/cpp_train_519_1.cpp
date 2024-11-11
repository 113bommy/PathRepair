#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iomanip>
#include<complex>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<map>
#include<set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;
typedef pair<int,int> PII;
typedef long long LL;

#define d(x)  cout<<#x<<" = "<<(x)<<endl;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define EMP empty()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define REACH(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c,n) sort(c,c+n)
#define VSORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define DFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define DREP(i,n) DFOR(i,n,0)
#define INF 1000000000
#define PI  acos(-1.0)
////////////////////////////////////////////////
struct Rect{int h;int p;};
int lgstrec(int size,int buffer[])
{
	stack<Rect> S;
	int maxv=0;
	buffer[size]=0;
	for(int i=0;i<=size;i++)
	{
		Rect rect;
		rect.h=buffer[i];
		rect.p=i;
		if(S.empty())
		{
			S.push(rect);
		}
		else
		{
			if(S.top().h<rect.h)
			{
				S.push(rect);
			}
			else if(S.top().h>rect.h)
			{
				int tgt=i;
				while(!S.empty()&&S.top().h>=rect.h)
				{
					Rect pre=S.top();S.pop();
					int area=pre.h*(i-pre.p);
					maxv=max(maxv,area);
					tgt=pre.p;
				}
				rect.p=tgt;
				S.push(rect);
			}
		}
	}
	return maxv;
}
int H,W;
int buffer[1400][1400];
int T[1400][1400];
int lgstrec()
{
	REP(j,W)
	{
		REP(i,H)
		{
			if(buffer[i][j])
			{
				T[i][j]=0;
			}
			else
			{
				T[i][j]=(i>0)?T[i-1][j]+1:1;
			}
		}
	}
	int maxv=0;
	REP(i,H)
	{
		maxv=max(maxv,lgstrec(W,T[i]));
	}
	return maxv;
}
int main()
{
	scanf("%d%d",&H,&W);
	REP(i,H)
	{
		REP(j,W)
		{
			scanf("%d",&buffer[i][j]);
		}
	}
	cout<<lgstrec()<<endl;
	return 0;
}