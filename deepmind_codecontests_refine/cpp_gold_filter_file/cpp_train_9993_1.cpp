#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=10100;
map<int,int> dp,v,c;
VI cand,d[N];
int w,h,k,n,x,y;
//v[N],c[N],dp[N];
int query(int x) { return (--dp.upper_bound(x))->se;}
int solve(VI x) {
	v.clear(); c.clear();
	cand.clear();
	for (auto p:x) {
		if (p%2==0) c[p/2+1]=2;
		else v[p/2+1]=1;
		cand.pb(p/2+1);
		if (p/2+2<=(w+1)/2) cand.pb(p/2+2);
		if (p/2+3<=(w+1)/2) cand.pb(p/2+3);
	}
	cand.pb((w+1)/2);
	cand.pb(0);
	sort(all(cand));
	cand.erase(unique(all(cand)),cand.end());
	dp.clear();
	dp[0]=0;
	rep(x,1,SZ(cand)) {
		int i=cand[x];
		dp[i]=query(i-1)+v[i];
		if (i-2>=0) dp[i]=min(dp[i],query(i-2)+c[i]);
	}
	return dp[w/2+1];
/*	rep(i,1,w/2+2) {
		v[i]=c[i]=0;
	}
	for (auto p:x) {
		if (p%2==0) c[p/2+1]=1; else v[p/2+1]=1;
	}
	dp[0]=0;
	rep(i,1,w/2+2) {
		dp[i]=dp[i-1]+v[i];
		if (i>=2) dp[i]=min(dp[i],dp[i-2]+2*c[i]);
	}
	return dp[w/2+1];*/
}
int main() {
	scanf("%d%d%d",&w,&h,&k);
	k-=(w+1)/2;
	if (k<0) {
		puts("-1");
		return 0;
	}
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",&x,&y);
		if (y%2==0) d[y/2].pb(x);
	}
	int r=0;
	rep(i,1,h/2+1) r+=solve(d[i]);
	int cur=(h/2)*(w/2+1)-r;
	int dd=min(r,k); r-=dd; k-=dd;
	dd=min(cur,k); cur-=dd; k-=dd;
	printf("%d\n",cur+r*2);
}