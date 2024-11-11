#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl







using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;


ll pw(ll x, ll y) {
    ll res=1;
    while (y) {
	if (y%2) res=res*x%mod;
	x=x*x%mod;y=y/2;
    }
    return ((res%mod)+mod)%mod;
}

int n;
vector<int> g[maxn];

int par[maxn];
int siz[maxn];
vector<int> subtrees[maxn];

void dfs(int at, int p=0) {
    siz[at]=1;
    for (int to: g[at]) {
	if (to == p) continue;
	dfs(to, at);
	par[to] = at;
	siz[at] += siz[to];
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    for (int i=0; i<n-1; i++) {
	int u,v; cin>>u>>v;
	g[u].push_back(v);
	g[v].push_back(u);
    }

    dfs(1);

    
    for (int at=1; at<=n; at++) {
	ll tot = 0;
	for (to: g[at]) {
	    if (to==par[at]) continue;
	    tot += siz[to];
	    subtrees[at].push_back(siz[to]);
	}
	ll up = n-1-tot;
	if (up>0) subtrees[at].push_back(up);
    }


    ll res = 0;
    for (int i=1; i<=n; i++) {
	ll all = pw(2,n-1);
	all --;
	for (ll x: subtrees[i]) {
	    all -= (pw(2,x)-1);
	    all %= mod;
	}
	res += all;
	res %= mod;
    }

    res %= mod;
    res += mod;
    res %= mod;

    ll ans = res*pw(pw(2,n),mod-2)%mod;
    cout<<ans<<endl;
    
    return 0;
}
