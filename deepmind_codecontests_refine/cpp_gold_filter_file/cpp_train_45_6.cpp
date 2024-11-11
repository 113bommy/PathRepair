#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);
template <class T, class S>
inline void add(T& a, S b) {
  a += b;
  if (a >= mod) a -= mod;
}
template <class T, class S>
inline void sub(T& a, S b) {
  a -= b;
  if (a < 0) a += mod;
}
template <class T, class S>
inline bool chkmax(T& a, S b) {
  return a < b ? a = b, true : false;
}
template <class T, class S>
inline bool chkmin(T& a, S b) {
  return a > b ? a = b, true : false;
}
int n, q;
int pa[N][20], len[N][20], depth[N];
int allDis2[N];
vector<pair<int, int> > G[N];
struct dpNode {
  dpNode() { cnt = sumDis = sumDis2 = 0; }
  dpNode(int cnt, int sumDis, int sumDis2)
      : cnt(cnt), sumDis(sumDis), sumDis2(sumDis2) {}
  int cnt, sumDis, sumDis2;
  void print() {
    printf("cnt: %d  sumDis: %d  sumDis2: %d\n", cnt, sumDis, sumDis2);
  }
} dp[N], dp2[N], INIT(1, 0, 0);
dpNode mergeTwo(dpNode a, dpNode b, int w, int op) {
  if (op > 0) {
    a.cnt += b.cnt;
    add(a.sumDis, b.sumDis);
    add(a.sumDis, 1LL * b.cnt * w % mod);
    add(a.sumDis2, b.sumDis2);
    add(a.sumDis2, 1LL * b.sumDis * 2 * w % mod);
    add(a.sumDis2, 1LL * w * w % mod * b.cnt % mod);
  } else {
    a.cnt -= b.cnt;
    sub(a.sumDis, b.sumDis);
    sub(a.sumDis, 1LL * b.cnt * w % mod);
    sub(a.sumDis2, b.sumDis2);
    sub(a.sumDis2, 1LL * b.sumDis * 2 * w % mod);
    sub(a.sumDis2, 1LL * w * w % mod * b.cnt % mod);
  }
  return a;
}
void dfs(int u, int fa, int disTofa) {
  depth[u] = depth[fa] + 1;
  pa[u][0] = fa;
  len[u][0] = disTofa;
  dp[u].cnt = 1;
  for (int i = 1; i < 20; i++) {
    pa[u][i] = pa[pa[u][i - 1]][i - 1];
    len[u][i] = (len[u][i - 1] + len[pa[u][i - 1]][i - 1]) % mod;
  }
  for (auto& e : G[u]) {
    int v = e.second;
    if (v == fa) continue;
    dfs(v, u, e.first);
    dp[u] = mergeTwo(dp[u], dp[v], e.first, 1);
  }
}
pair<int, int> getLca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int dis = depth[u] - depth[v];
  int ret = 0;
  for (int i = 19; i >= 0; i--)
    if (dis >> i & 1) add(ret, len[u][i]), u = pa[u][i];
  if (u == v) return make_pair(ret, u);
  for (int i = 19; i >= 0; i--) {
    if (pa[u][i] != pa[v][i]) {
      add(ret, len[u][i]);
      add(ret, len[v][i]);
      u = pa[u][i];
      v = pa[v][i];
    }
  }
  add(ret, len[u][0]);
  add(ret, len[v][0]);
  return make_pair(ret, pa[u][0]);
}
void dfs2(int u, int fa, dpNode up) {
  dp2[u] = up;
  dp2[u].cnt--;
  allDis2[u] = (dp[u].sumDis2 + up.sumDis2) % mod;
  for (auto& e : G[u]) {
    if (e.second == fa) continue;
    up = mergeTwo(up, dp[e.second], e.first, 1);
  }
  for (auto& e : G[u]) {
    if (e.second == fa) continue;
    up = mergeTwo(up, dp[e.second], e.first, -1);
    dfs2(e.second, u, mergeTwo(INIT, up, e.first, 1));
    up = mergeTwo(up, dp[e.second], e.first, 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].push_back(make_pair(w, v));
    G[v].push_back(make_pair(w, u));
  }
  dfs(1, 0, 0);
  dfs2(1, 0, INIT);
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    pair<int, int> ret = getLca(u, v);
    int lca = ret.second, dis = ret.first;
    int ans = 0;
    if (lca != v) {
      int x = mergeTwo(INIT, dp[v], dis, 1).sumDis2;
      int z = allDis2[u];
      ans = ((2 * x - z) % mod + mod) % mod;
    } else {
      int y = mergeTwo(INIT, dp2[v], dis, 1).sumDis2;
      int z = allDis2[u];
      ans = ((z - 2 * y) % mod + mod) % mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
