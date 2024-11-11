#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;
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
const int mxN = 100001;
int n;
vector<int> adj[mxN];
int ans[mxN];
ll calc(int u, int p = -1) {
  ll curr = 1;
  for (int v : adj[u]) {
    if (v ^ p) {
      curr = (curr * 2LL * calc(v, u)) % MOD;
    }
  }
  return curr;
}
bool die = false;
int go(int u, int k, int p = -1) {
  int curr = 0;
  for (int v : adj[u]) {
    if (v ^ p) {
      curr += go(v, k, u);
    }
  }
  if (curr % k == 0)
    return 1;
  else if ((curr - 1) % k == 0)
    return 0;
  die = 1;
  return 0;
}
int check(int k) {
  if (k == 1) {
    return calc(0);
  }
  for (int i = (0); i < (n); ++i) {
    if (adj[i].size() > 1) {
      die = false;
      bool ok = go(i, k);
      if (die == 0 && ok == 1) return 1;
      return 0;
    }
  }
}
void solve() {
  cin >> n;
  for (int i = (0); i < (n + 1); ++i) {
    ans[i] = 0;
    adj[i].clear();
  }
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (n == 2) {
    cout << "2 0\n";
    return;
  }
  for (int d = 1; d * d <= n - 1; d++) {
    if ((n - 1) % d == 0) {
      ans[d] = check(d);
      ans[(n - 1) / d] = check((n - 1) / d);
    }
  }
  for (int i = (n)-1; i >= (1); --i) {
    for (int j = i + i; j < n; j += i) {
      ans[i] = (ans[i] - ans[j] + MOD) % MOD;
    }
  }
  for (int i = (1); i < (n + 1); ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
  return 0;
}
