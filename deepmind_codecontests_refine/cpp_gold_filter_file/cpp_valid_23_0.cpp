#include <bits/stdc++.h>
using namespace std;
const int N = 1010, mod = 998244353;
int n, m, pd[N], fac[N];
namespace PQtree {
const int M = N << 2;
int op[M], tp[M], rt, tot;
vector<int> son[M];
inline void init() {
  tot = n;
  rt = ++tot;
  tp[tot] = 0;
  for (int i = 1; i <= n; ++i) tp[i] = 0, son[tot].push_back(i);
}
inline void dfs1(int p) {
  if (p <= n) {
    op[p] = pd[p];
    return;
  }
  bool pd0 = 0, pd1 = 0;
  for (int v : son[p]) {
    dfs1(v);
    pd0 |= (op[v] == 0 || op[v] == 2);
    pd1 |= (op[v] == 1 || op[v] == 2);
  }
  if (!pd0)
    op[p] = 1;
  else if (!pd1)
    op[p] = 0;
  else
    op[p] = 2;
}
inline void dfs2(int u, int lim) {
  if (op[u] != 2) return;
  vector<int> ve[3];
  for (int v : son[u]) ve[op[v]].push_back(v);
  if (!lim && ve[2].size() >= 3) {
    puts("0");
    exit(0);
  }
  if (lim && ve[2].size() >= 2) {
    puts("0");
    exit(0);
  }
  if (!lim && (ve[1].size() + ve[2].size()) <= 1) {
    for (int v : ve[1]) dfs2(v, 0);
    for (int v : ve[2]) dfs2(v, 0);
    return;
  }
  if (tp[u] == 0) {
    vector<int> nw;
    int np = -1;
    if (!ve[1].empty()) np = ve[1][0];
    if (ve[1].size() > 1) np = ++tot, son[np] = ve[1], tp[np] = 0;
    if (!ve[2].empty()) {
      dfs2(ve[2][0], 2);
      for (int t : son[ve[2][0]]) nw.push_back(t);
    }
    if (np != -1) nw.push_back(np);
    if (ve[2].size() > 1) {
      dfs2(ve[2][1], 1);
      for (int t : son[ve[2][1]]) nw.push_back(t);
    }
    if (!ve[0].size()) {
      tp[u] = 1;
      son[u] = nw;
      if (lim == 1) reverse(son[u].begin(), son[u].end());
    } else {
      if (lim) {
        int nq = ve[0][0];
        if (ve[0].size() > 1) nq = ++tot, son[nq] = ve[0], tp[nq] = 0;
        son[u].clear();
        son[u].push_back(nq);
        for (int i : nw) son[u].push_back(i);
        tp[u] = 1;
        if (lim == 1) reverse(son[u].begin(), son[u].end());
      } else {
        int nq = nw[0];
        if (nw.size() > 1) nq = ++tot, son[nq] = nw, tp[nq] = 1;
        son[u] = ve[0];
        son[u].push_back(nq);
        tp[u] = 0;
      }
    }
  } else {
    int f = 0;
    if (op[son[u][0]] == 1 || op[son[u].back()] == 0)
      reverse(son[u].begin(), son[u].end());
    vector<int> nw;
    for (int v : son[u]) {
      if (!op[v]) {
        if (f == 1) f = 2;
        nw.push_back(v);
      } else if (op[v] == 1) {
        if (f == 2) {
          puts("0");
          exit(0);
        }
        if (f == 0) f = 1;
        nw.push_back(v);
      } else {
        if (f == 2) {
          puts("0");
          exit(0);
        }
        if (f == 1)
          f = 2;
        else
          f = 1;
        dfs2(v, (f == 1 ? 2 : 1));
        for (int x : son[v]) nw.push_back(x);
      }
    }
    if (lim && f == 2) {
      puts("0");
      exit(0);
    }
    if (lim == 1) reverse(nw.begin(), nw.end());
    son[u] = nw;
  }
}
inline void insert() {
  dfs1(rt);
  dfs2(rt, 0);
}
inline int query(int u) {
  int ans = 1;
  for (int v : son[u]) ans = 1ll * ans * query(v) % mod;
  if (u <= n) return ans;
  if (tp[u] && son[u].size() > 1) ans = 2ll * ans % mod;
  if (!tp[u]) ans = 1ll * ans * fac[son[u].size()] % mod;
  return ans;
}
}  // namespace PQtree
using namespace PQtree;
int main() {
  scanf("%d%d", &n, &m);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  init();
  for (int i = 1; i <= m; ++i) {
    memset(pd + 1, 0, sizeof(int) * (n));
    int len;
    scanf("%d", &len);
    for (int j = 1, x; j <= len; ++j) scanf("%d", &x), pd[x] = 1;
    insert();
  }
  printf("%d\n", query(rt));
  return 0;
}
