#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
ll MOD = 1000000007;
const ll root = 3;
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
ll modInv(ll a) { return binpow(a, MOD - 2); }
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 500001;
int par[mxN][20];
int arr[mxN];
int rt;
int val = INF;
ll ans = 0;
int n;
vector<int> adj[mxN];
void dfs(int u, int p) {
  par[u][0] = p;
  for (int v : adj[u]) {
    if (v ^ p) {
      dfs(v, u);
    }
  }
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    cin >> arr[i];
    if (arr[i] < val) {
      val = arr[i];
      rt = i;
    }
  }
  int a, b;
  for (int i = (0); i < (n - 1); ++i) {
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(rt, rt);
  for (int lg = (1); lg < (20); ++lg) {
    for (int i = (0); i < (n); ++i) {
      par[i][lg] = par[par[i][lg - 1]][lg - 1];
    }
  }
  for (int i = (0); i < (n); ++i) {
    if (i == rt) continue;
    ll best = INFLL;
    for (int lg = (0); lg < (20); ++lg) {
      best = min(best, 1LL * (lg + 1) * arr[par[i][lg]]);
    }
    best += arr[i];
    ans += best;
  }
  cout << ans << "\n";
  return 0;
}
