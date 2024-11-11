#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(12) << fixed;
  cerr << setprecision(12) << fixed;
  int tests = 1;
  while (tests--) {
    solve();
  }
}
const int MAXN = 200200;
const int P = 998244353;
vector<pii> g[MAXN];
void add(int &a, int b) {
  a += b;
  if (a >= P) {
    a -= P;
  }
}
void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += P;
  }
}
void mul(int &a, int b) { a = ll(a) * b % P; }
int dp[MAXN][3];
void dfs(int v, int p = MAXN) {
  for (int i = 0; i < (int)(g[v]).size(); ++i) {
    if (g[v][i].second == p) {
      swap(g[v][i], g[v].back());
      g[v].pop_back();
    }
  }
  auto cmp = [](pii &p, pii &q) { return p.second < q.second; };
  sort((g[v]).begin(), (g[v]).end(), cmp);
  for (auto [u, id] : g[v]) {
    dfs(u, id);
  }
  int deg = (int)(g[v]).size();
  vector<int> pref(deg + 1);
  pref[0] = 1;
  for (int i = 0; i < deg; ++i) {
    auto [u, id] = g[v][i];
    pref[i + 1] = pref[i];
    mul(pref[i + 1], dp[u][1]);
  }
  vector<int> suff(deg + 1);
  suff[deg] = 1;
  for (int i = deg - 1; i >= 0; --i) {
    auto [u, id] = g[v][i];
    suff[i] = suff[i + 1];
    mul(suff[i], dp[u][0]);
  }
  int lim = 0;
  for (int i = 0; i < (int)(g[v]).size(); ++i) {
    if (p < g[v][i].second) {
      break;
    }
    ++lim;
  }
  dp[v][0] = pref[deg];
  dp[v][1] = pref[lim];
  mul(dp[v][1], suff[lim]);
  dp[v][2] = pref[deg];
  for (int i = 0; i < deg; ++i) {
    auto [u, id] = g[v][i];
    int cur = pref[i];
    mul(cur, suff[i + 1]);
    mul(cur, dp[u][2]);
    add(dp[v][0], cur);
    if (cur < lim) {
      add(dp[v][1], cur);
    } else {
      add(dp[v][2], cur);
    }
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[v].push_back({u, i});
    g[u].push_back({v, i});
  }
  dfs(0);
  cout << dp[0][0] << endl;
}
