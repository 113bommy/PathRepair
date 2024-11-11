#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<numeric>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>

#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define rp(i,c) rep(i,(c).size())
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf=1<<28;
const double INF=1e12,EPS=1e-9;

int n;
bool market[365][16];
bool V[366][2401][9];

bool check(int day,int y,int x)
{
	rep(i,2)rep(j,2)if(market[day][(y+i)*4+x+j])return 0;
	return 1;
}
bool visit(int day,int y,int x,int r0,int r1,int r2,int r3)
{
	bool &v=V[day][343*r0+49*r1+7*r2+r3][y*3+x];
	if(v)return 1;
	
	v=1;
	return 0;
}
bool dfs(int day,int cy,int cx,int r0,int r1,int r2,int r3)
{
	if(day>=n)return 1;
	
	for(int ny=cy-2;ny<=cy+2;ny++)for(int nx=cx-2;nx<=cx+2;nx++)
	if(ny==cy||nx==cx)
	if(0<=ny&&ny<3&&0<=nx&&nx<3)
	{
		if(!check(day,ny,nx))continue;
		int nr0=r0,nr1=r1,nr2=r2,nr3=r3;
		if(ny==0&&nx==0)nr0=0; else nr0++;
		if(ny==0&&nx==2)nr1=0; else nr1++;
		if(ny==2&&nx==0)nr2=0; else nr2++;
		if(ny==2&&nx==2)nr3=0; else nr3++;
		
		if(nr0>=7||nr1>=7||nr2>=7||nr3>=7)continue;
		if(visit(day+1,ny,nx,nr0,nr1,nr2,nr3))continue;
		if(dfs(day+1,ny,nx,nr0,nr1,nr2,nr3))return 1;
	}
	return 0;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		rep(i,n)rep(j,16)scanf("%d",market[i]+j);
		rep(i,n+1)rep(j,2401)fill_n(V[i][j],9,0);
		
		if(!check(0,1,1))
		{
			cout<<0<<endl; continue;
		}
		cout<<dfs(1,1,1,1,1,1,1)<<endl;
	}
	return 0;
}