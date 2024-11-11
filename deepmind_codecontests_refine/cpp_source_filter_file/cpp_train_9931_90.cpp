#include<iostream>
#include<stdio.h> 
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<assert.h>
#include<limits.h>
#define tr(i) for(typeof(i.begin()) it=i.begin(); it!=i.end();it++)
#define pb push_back
#define mp make_pair
#define REP(i,n) for(long long i=0;i<n;i++)
#define rep(i,s,n) for(long long i=s;i<n;i++)
#define s(n) scanf("%d",&n)
#define XX first
#define X first
#define Y second
#define all(a) a.begin(),a.end()
#define YY second.first
#define ZZ second.second
#define fill(a,b) memset(a,b,sizeof(a))
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MN 1600
#define DB 150
#define OFF 100
bool gr[MN][MN],proc[MN][MN],next[MN][MN],con2[MN][MN];
int con[MN][MN];
int rays[500];
int h,w,cc;
void dfs(int i,int j,int val)
{
	if(i<0||j<0||i>=h||j>=w) return;
	if(!gr[i][j]) return;
	if(con[i][j]!=-1) return;
	con[i][j]=val;
	dfs(i-1,j,val);
	dfs(i,j-1,val);
	dfs(i+1,j,val);
	dfs(i,j+1,val); //going only to four sides right 
	dfs(i-1,j-1,val);
	dfs(i+1,j-1,val);
	dfs(i+1,j+1,val);
	dfs(i-1,j+1,val); 
}
void dfsn(int i,int j)
{
	if(i<0||j<0||i>=h||j>=w) return;
	if(!next[i][j]) return;
	if(con2[i][j]) return;
	con2[i][j]=true;
	dfsn(i-1,j);
	dfsn(i,j-1);
	dfsn(i+1,j);
	dfsn(i,j+1); //going only to four sides right 
	dfsn(i-1,j-1);
	dfsn(i+1,j-1);
	dfsn(i+1,j+1);
	dfsn(i-1,j+1); 
}
void input()
{
	s(h); s(w); cc=0;
	REP(i,h) REP(j,w) {cin>>gr[i][j]; proc[i][j]=gr[i][j]; }
	fill(con,-1); fill(rays,0); fill(con2,0);
	REP(i,h) REP(j,w) if(gr[i][j]&&con[i][j]==-1) dfs(i,j,cc++);
}
void debug()
{
	REP(i,h) { REP(j,w) cout<<next[i][j]; cout<<endl; }
}
bool check(int i, int j) //see if blank
{
	if(i<0||j<0||i>=h||j>=w) return false;
	return !proc[i][j];
}
bool check2(int i, int j)
{
	if(i<0||j<0||i>=h||j>=w) return false;
	return proc[i][j];
}
void erode()
{
	REP(i,h)
	REP(j,w)
	{
		if(!proc[i][j]) next[i][j]=proc[i][j];
		else if(check(i-1,j)||check(i,j-1)||check(i+1,j)||check(i,j+1)) next[i][j]=0;
		else next[i][j]=proc[i][j];
	}
	REP(i,h) REP(j,w) proc[i][j]=next[i][j];
}
void dilate()
{
	REP(i,h)
	REP(j,w)
	{
		if(proc[i][j]) next[i][j]=proc[i][j];
		else if(check2(i-1,j)||check2(i,j-1)||check2(i+1,j)||check2(i,j+1)) next[i][j]=1;
		else next[i][j]=proc[i][j];
	}
	REP(i,h) REP(j,w) proc[i][j]=next[i][j];
}
int main()
{
	input();
	cout<<cc<<endl;
	REP(i,3) erode();
	REP(i,5) dilate();
	REP(i,h) REP(j,w) if(gr[i][j]&&(!proc[i][j])) next[i][j]=1; else next[i][j]=0;
	REP(i,h) REP(j,w) if(next[i][j]&&(!con2[i][j])) { dfsn(i,j); rays[con[i][j]]++; }
	sort(rays,rays+cc);
	REP(i,cc) cout<<rays[i]<<" ";
	cout<<endl;
	//debug();
}
