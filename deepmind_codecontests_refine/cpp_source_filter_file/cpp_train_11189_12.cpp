#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int LogN = 21;
int n, q, all, leaf;
struct Edge {
  int to, val;
};
vector<Edge> G[N];
template <typename _Tp>
inline void IN(_Tp& x) {
  char ch;
  bool flag = 0;
  x = 0;
  while (ch = getchar(), !isdigit(ch))
    if (ch == '-') flag = 1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  if (flag) x = -x;
}
inline void addedge(int u = 0, int v = 0, int w = 0) {
  IN(u), IN(v), IN(w), all += w;
  G[u].push_back((Edge){v, w}), G[v].push_back((Edge){u, w});
}
struct Algorithm_Tree {
  int rt, f[N][LogN], g[N][LogN];
  int dis[N], son[N], sum[N], top[N], mx[N], rank[N];
  int m, nod[N], val[N];
  void getdist(int u, int fa) {
    for (auto t : G[u])
      if (t.to != fa) dis[t.to] = dis[u] + t.val, getdist(t.to, u);
  }
  void pre(int u, int fa, int v = 0) {
    for (auto t : G[u])
      if ((v = t.to) != fa) {
        f[v][0] = u, g[v][0] = t.val;
        for (int i = 0; f[v][i]; ++i)
          f[v][i + 1] = f[f[v][i]][i], g[v][i + 1] = g[v][i] + g[f[v][i]][i];
        dis[v] = dis[u] + t.val, pre(v, u);
        if (mx[v] + t.val > mx[u]) mx[u] = mx[v] + t.val, son[u] = v;
      }
    for (auto t : G[u])
      if ((v = t.to) != fa && v != son[u]) val[nod[++m] = v] = mx[v] + t.val;
  }
  inline void getroot(int now) {
    getdist(rt = now, 0);
    for (int i = 1; i <= n; ++i)
      if (dis[i] > dis[rt]) rt = i;
    dis[rt] = 0, pre(rt, 0), val[nod[++m] = rt] = mx[rt];
    sort(nod + 1, nod + 1 + m, [&](int x, int y) { return val[x] > val[y]; });
    for (int i = 1; i <= m; ++i) sum[i] = sum[i - 1] + val[nod[i]];
    for (int i = 1; i <= m; ++i) {
      int tmp = nod[i];
      while (tmp) top[tmp] = nod[i], rank[tmp] = i, tmp = son[tmp];
    }
  }
  inline int calc1(int x, int y) {
    int res = mx[x];
    for (int i = LogN - 1; ~i; --i)
      if (rank[f[x][i]] >= y) res = g[x][i], x = f[x][i];
    return sum[y - 1] + res + g[x][0];
  }
  inline int calc2(int x, int y) {
    int res = mx[x];
    for (int i = LogN - 1; ~i; --i)
      if (rank[f[x][i]] > y) res = g[x][i], x = f[x][i];
    return sum[y] - mx[f[x][0]] + res + g[x][0];
  }
  inline int query(int x, int y) {
    y = (y << 1) - 1;
    return rank[x] <= y ? sum[y] : max(calc1(x, y), calc2(x, y));
  }
} T1, T2;
int main() {
  IN(n), IN(q);
  for (int i = 2; i <= n; ++i) addedge();
  for (int i = 1; i <= n; ++i) leaf += (int)(G[i].size()) == 1;
  T1.getroot(1), T2.getroot(T1.rt);
  int x, y, lastans = 0;
  while (q--) {
    IN(x), IN(y);
    x = (x + lastans - 1) % n + 1, y = (y + lastans - 1) % n + 1;
    printf("%d\n",
           lastans =
               ((y << 1) >= leaf ? all : max(T1.query(x, y), T2.query(x, y))));
  }
  return 0;
}
