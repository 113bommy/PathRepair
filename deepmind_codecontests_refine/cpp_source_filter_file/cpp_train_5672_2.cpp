#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const int N = 200005;
int fa[N], f[N][20], tag[N], p[N], lg[N];
int now, ans, rt, n, m, Q, a, b, c;
long long dis[N], d[N], lim;
vector<pair<int, int> > e[N];
void dfs(int u, int fa, long long D) {
  dis[u] = max(dis[u], D);
  for (auto v : e[u])
    if (v.first != fa) {
      d[v.first] = d[u] + v.second;
      dfs(v.first, u, D + v.second);
    }
}
void dfs2(int u) {
  f[u][0] = fa[u];
  for (int j = (1); j <= (18); j++) f[u][j] = f[f[u][j - 1]][j - 1];
  for (auto v : e[u])
    if (v.first != fa[u]) {
      d[v.first] = d[u] + v.second;
      fa[v.first] = u;
      dfs2(v.first);
    }
}
void dfs3(int u) {
  p[u] = u;
  for (auto v : e[u])
    if (v.first != fa[u]) {
      dfs3(v.first);
      if (dis[p[v.first]] < dis[p[u]]) p[u] = p[v.first];
    }
  for (int j = (lg[d[p[u]]]); j >= (0); j--) {
    int t = f[p[u]][j];
    if (t && dis[t] >= dis[u] - lim) p[u] = t;
  }
  tag[u]++, tag[fa[p[u]]]--;
}
void dfs4(int u) {
  for (auto v : e[u])
    if (v.first != fa[u]) {
      dfs4(v.first);
      tag[u] += tag[v.first];
    }
  ans = max(ans, tag[u]);
}
int main() {
  read(n);
  for (int i = (1); i <= (n - 1); i++) {
    read(a), read(b), read(c);
    e[a].push_back(make_pair(b, c)), e[b].push_back(make_pair(a, c));
  }
  dfs(1, 0, 0);
  rt = max_element(d + 1, d + n + 1) - d;
  d[rt] = 0, dfs(rt, 0, 0);
  rt = max_element(d + 1, d + n + 1) - d;
  d[rt] = 0, dfs(rt, 0, 0);
  rt = min_element(dis + 1, dis + n + 1) - dis;
  d[rt] = fa[rt] = 0, dfs2(rt);
  lg[0] = -1;
  for (int i = (1); i <= (n); i++) lg[i] = lg[i >> 1] + 1;
  read(Q);
  while (Q--) {
    fill(tag + 1, tag + n + 1, 0);
    read(lim), dfs3(rt);
    ans = 0, dfs4(rt);
    printf("%d\n", ans);
  }
  return 0;
}
