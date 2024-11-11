#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int x[252521];
int ne[252521][20],rne[252521][20];
int dp[(1<<20)+10],rdp[(1<<20)+10];
vector<int> v;
int main()
{
	int n,V;
	cin>>n>>V;
	rep(i,n) cin>>x[i];
	while(V>0){
		v.pb(V);V/=2;
	}
	v.pb(0);int m=v.size();
	rep(i,n) rep(j,m){
		rne[i][j]=i;
		if(i>0 && x[i]-x[i-1]<=v[j]) rne[i][j]=rne[i-1][j];
	}
	for(int i=n-1;i>=0;i--) rep(j,m){
		ne[i][j]=i;
		if(i<n-1 && x[i+1]-x[i]<=v[j]) ne[i][j]=ne[i+1][j];
	}
	memset(dp,0,sizeof(dp));
	rep(i,(1<<20)+5) rdp[i]=n-1;
	rep(i,(1<<m)) rep(j,m){
		if((i&(1<<j))>0) continue;
		dp[i+(1<<j)]=max(dp[i+(1<<j)],ne[dp[i]][j]+1);
		rdp[i+(1<<j)]=min(rdp[i+(1<<j)],rne[rdp[i]][j]-1);
	}
	//rep(i,(1<<m)) cout<<i<<' '<<dp[i]<<' '<<rdp[i]<<endl;
	if(dp[(1<<m)-1]<n || rdp[(1<<m)-1]>=0){
		assert(dp[(1<<m)-1]<n && rdp[(1<<m)-1]>=0)
		rep(i,n) cout<<"Impossible"<<endl;
		return 0;
	}
	int now=0;
	while(now<n){
		int f=0;
		rep(i,(1<<(m-1))){
			if(dp[(1<<m)-2-(i<<1)]>=now && rdp[(i<<1)]<=ne[now][0]) f=1;
		}
		REP(i,now,ne[now][0]+1){
			if(f>0) cout<<"Possible"<<endl;
			else cout<<"Impossible"<<endl;
		}
		now=ne[now][0]+1;
	}
}
