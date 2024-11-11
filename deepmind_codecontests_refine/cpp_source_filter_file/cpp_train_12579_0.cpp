#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(x,y) (x=min(x,y))
#define chmax(x,y) (x=max(x,y))
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
#define N 200010
vector<int> g[N];
ll d[N], two[N];
int n;

void dfs(int u, int dep){
	d[dep]++;
	for(auto v: g[u]) dfs(v, dep+1);
}

vector<vector<ll>> rec(int u){
	vector<vector<ll>> dp;
	int mx = 0;
	for(auto v: g[u]){
		auto dp2 = rec(v);
		if(dp.size()<dp2.size()) dp.swap(dp2);
		chmax(mx, dp2.size());
		rep(i, dp2.size()){
			auto &a = dp[dp.size()-i-1], &b = dp2[dp2.size()-i-1];
			ll c[3] = {};
			for(int j = 2; j >= 0; j--) rep(k, 3) (c[min(2, j+k)]+=a[j]*b[k])%=mod;
			rep(j, 3) a[j] = c[j];
		}
	}
	for(int i = 0; i < mx; i++){
		auto &x = dp[dp.size()-i-1];
		(x[0]+=x[2])%=mod;
		x[2] = 0;
	}
	dp.emplace_back((vector<ll>){1, 1, 0});
	return dp;
}

int main(){
	cin>>n;
	rep(i, n){
		int p;
		cin>>p;
		g[p].push_back(i+1);
	}
	dfs(0, 0);
	auto dp = rec(0);
	ll res = 0;
	two[0] = 1;
	rep(i, n) (two[i+1]=two[i]*2%mod);
	rep(i, dp.size()) (res+=dp[dp.size()-i-1][1]*two[n+1-d[i]])%=mod;
	cout<<res<<endl;
	/*cerr<<"DEBUG"<<endl;
	rep(i, dp.size()) cerr<<dp[i]<<endl;
	cerr<<endl;
	rep(i, n) cerr<<d[i]<<endl;
	cerr<<endl;*/
	return 0;
}
