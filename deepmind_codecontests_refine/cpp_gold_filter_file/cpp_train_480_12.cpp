#include <bits/stdc++.h>
const int maxn = 1E+5 + 5;
const int maxB = 605;
const int B = 600;
const int INF = 0x3f3f3f3f;
int n, m, ind, a[maxn];
int fa[maxn], siz[maxn];
int top[maxn], son[maxn], dfn[maxn];
std::vector<int> to[maxn];
inline void DFS1(int u) {
  siz[u] = 1;
  for (int v : to[u]) {
    DFS1(v), siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
inline void DFS2(int u, int tp) {
  dfn[u] = ++ind, top[u] = tp;
  if (son[u]) DFS2(son[u], tp);
  for (int v : to[u])
    if (v ^ son[u]) DFS2(v, v);
}
int ans, L[maxB], R[maxB], buc[maxn / maxB + 3][maxn << 1], tag[maxB];
bool vis[maxn];
inline void change(int id, int p, int v) {
  if (p + tag[id] > 0) ans += v;
  buc[id][p + n] += v;
}
inline void Update(int l, int r, int v) {
  int idL = (l - 1) / B + 1, idR = (r - 1) / B + 1;
  if (idL == idR)
    for (int i = l; i <= r; ++i)
      if (!vis[i])
        change(idL, a[i], -1), change(idL, a[i] += v, 1);
      else
        a[i] += v;
  else {
    for (int i = l; i <= idL * B; ++i)
      if (!vis[i])
        change(idL, a[i], -1), change(idL, a[i] += v, 1);
      else
        a[i] += v;
    for (int i = (idR - 1) * B + 1; i <= r; ++i)
      if (!vis[i])
        change(idR, a[i], -1), change(idR, a[i] += v, 1);
      else
        a[i] += v;
    for (int i = idL + 1; i <= idR - 1; ++i) {
      if (v < 0)
        ans -= buc[i][-tag[i] + n + 1];
      else
        ans += buc[i][-tag[i] + n];
      tag[i] += v;
    }
  }
}
inline void Work(int u, int v) {
  while (u) {
    Update(dfn[top[u]], dfn[u], v);
    u = fa[top[u]];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; ++i) scanf("%d", &fa[i]), to[fa[i]].push_back(i);
  DFS1(1), DFS2(1, 1);
  for (int i = 1; i <= (n - 1) / B + 1; ++i) L[i] = R[i - 1] + 1, R[i] = i * B;
  R[(n - 1) / B + 1] = n;
  for (int i = 1, v; i <= n; ++i) scanf("%d", &v), a[dfn[i]] = -v;
  for (int i = 1; i <= n; ++i) ++buc[(i - 1) / B + 1][a[i] + n];
  while (m-- > 0) {
    int k;
    scanf("%d", &k);
    if (k < 0) {
      Work(-k, -1), k = dfn[-k];
      change((k - 1) / B + 1, a[k], 1);
      vis[k] = 0;
    } else {
      Work(k, 1), k = dfn[k];
      change((k - 1) / B + 1, a[k], -1);
      vis[k] = 1;
    }
    printf("%d ", ans);
  }
}
