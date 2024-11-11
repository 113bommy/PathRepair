#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 998244353;
const int MAXN = 800005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int now, n;
vector<int> Ans[MAXN];
struct Tree {
  vector<int> tag[MAXN], e[MAXN];
  int fa[MAXN], sz[MAXN], mx[MAXN], top[MAXN];
  int dep[MAXN], dfn[MAXN], vis[MAXN], flag[MAXN], DFN = 0;
  void dfs(int x) {
    sz[x] = 1;
    for (auto v : e[x]) {
      dep[v] = dep[x] + 1, dfs(v), sz[x] += sz[v];
      if (sz[v] > sz[mx[x]]) mx[x] = v;
    }
  }
  void dfs2(int x, int t) {
    top[x] = t, dfn[x] = ++DFN;
    if (mx[x]) dfs2(mx[x], t);
    for (auto v : e[x])
      if (v != mx[x]) dfs2(v, v);
  }
  void update(int x, int l, int r, int L, int R, int y) {
    if (l >= L && r <= R) {
      tag[x].push_back(y);
      return;
    }
    int mid = (l + r) >> 1;
    if (R <= mid)
      update(x << 1, l, mid, L, R, y);
    else if (L > mid)
      update(x << 1 | 1, mid + 1, r, L, R, y);
    else
      update(x << 1, l, mid, L, mid, y),
          update(x << 1 | 1, mid + 1, r, mid + 1, R, y);
  }
  void erase(int x, int l, int r, int y) {
    if (!vis[x]) {
      for (auto t : tag[x])
        if (!flag[t]) Ans[now ^ 1].push_back(t), flag[t] = 1;
      vis[x] = 1;
    }
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (y <= mid)
      erase(x << 1, l, mid, y);
    else
      erase(x << 1 | 1, mid + 1, r, y);
  }
  void Change(int x, int y) {
    int t = x - 1;
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) swap(x, y);
      update(1, 1, n, dfn[top[x]], dfn[x], t);
      x = fa[top[x]];
    }
    if (x == y) return;
    if (dep[x] < dep[y]) swap(x, y);
    update(1, 1, n, dfn[y], dfn[x], t);
  }
} T[2];
int main() {
  n = read();
  for (int i = 2; i <= n; i++) T[0].e[T[0].fa[i] = read()].push_back(i);
  for (int i = 2; i <= n; i++) T[1].e[T[1].fa[i] = read()].push_back(i);
  T[0].dfs(1), T[0].dfs2(1, 1);
  T[1].dfs(1), T[1].dfs2(1, 1);
  for (int i = 2; i <= n; i++)
    T[1].Change(i, T[0].fa[i]), T[0].Change(i, T[1].fa[i]);
  now = 0;
  int p = read();
  Ans[now].push_back(p), T[now ^ 1].flag[p] = 1;
  for (int num = 0;; num++) {
    if (!Ans[now].size()) break;
    puts((num & 1) ? "Red" : "Blue");
    sort(Ans[now].begin(), Ans[now].end());
    for (auto t : Ans[now])
      T[now].erase(1, 1, n, T[now].dfn[t + 1]), printf("%d ", t);
    puts("");
    Ans[now].clear();
    now ^= 1;
  }
  return 0;
}
