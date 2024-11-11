#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline string getStr() {
  char ch[1000000];
  scanf("%s", ch);
  return ch;
}
inline char getCh() {
  char ch;
  scanf(" %c", &ch);
  return ch;
}
template <class P, class Q>
inline P smin(P &a, Q b) {
  if (b < a) a = b;
  return a;
}
template <class P, class Q>
inline P smax(P &a, Q b) {
  if (a < b) a = b;
  return a;
}
const long long MOD = 1e9 + 7;
const long long MAX_N = 20;
const long long MAX_LG = 21;
const long long base = 29;
const long long MAX_DIF = 2001;
vector<long long> g[MAX_N];
long long dp[MAX_N], cnt[MAX_N], root[MAX_N][MAX_LG], lvl[MAX_N];
long long dp2[MAX_N], cnt2[MAX_N], n, q;
inline void dfs(long long v, long long pr = 0, long long dep = 0) {
  cnt[v] = 1;
  dp[v] = 0;
  lvl[v] = dep;
  root[v][0] = pr;
  for (long long i = 1; i < MAX_LG; i++)
    root[v][i] = root[root[v][i - 1]][i - 1];
  for (long long i = 0; i < g[v].size(); i++) {
    long long u = g[v][i];
    if (u != pr) {
      dfs(u, v, dep + 1);
      cnt[v] += cnt[u];
      dp[v] += dp[u] + cnt[u];
    }
  }
}
inline void dfs2(long long v, long long pr = 0) {
  for (long long i = 0; i < g[v].size(); i++) {
    long long u = g[v][i];
    if (u != pr) {
      dp2[u] = dp2[v] + (n - cnt[v]) + (dp[v] - dp[u]) + (cnt[v] - 2 * cnt[u]);
      dfs2(u, v);
    }
  }
}
inline long long lca(long long p, long long q) {
  if (lvl[p] < lvl[q]) swap(p, q);
  for (long long i = MAX_LG - 1; i >= 0; i--) {
    if (lvl[p] - (1 << i) >= lvl[q]) p = root[p][i];
  }
  if (p == q) return p;
  for (long long i = MAX_LG - 1; i >= 0; i--) {
    if (root[p][i] != root[q][i]) {
      p = root[p][i], q = root[q][i];
    }
  }
  return root[p][0];
}
inline long long getpar(long long p, long long k) {
  for (long long i = MAX_LG - 1; i >= 0; i--) {
    if ((1 << i) <= k) {
      p = root[p][i];
      k -= (1 << i);
    }
  }
  return p;
}
int32_t main() {
  cout.precision(20);
  n = in(), q = in();
  for (long long i = 0; i < n - 1; i++) {
    long long v = in(), u = in();
    g[v].push_back(u), g[u].push_back(v);
  }
  dfs(1);
  dfs2(1);
  while (q--) {
    long long v = in(), u = in();
    if (lvl[v] > lvl[u]) swap(v, u);
    long long LCA = lca(v, u);
    long double val = 0;
    long long dist = lvl[v] + lvl[u] - 2 * lvl[LCA];
    if (LCA == v) {
      long long par = getpar(u, lvl[u] - lvl[v] - 1);
      long long DP = dp2[v] + dp[v] - dp[par] - cnt[par];
      val = (long double)(DP * cnt[u] + dp[u] * (n - cnt[par])) /
                (cnt[u] * (n - cnt[par])) +
            dist + 1;
      cout << fixed << val << "\n";
    } else {
      val = (long double)(dp[v] * cnt[u] + dp[u] * cnt[v]) / (cnt[v] * cnt[u]) +
            dist + 1;
      cout << fixed << val << "\n";
    }
  }
}
