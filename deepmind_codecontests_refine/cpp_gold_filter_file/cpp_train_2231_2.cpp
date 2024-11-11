#include <bits/stdc++.h>
using std::vector;
const int N = 200005;
int cnt, now, n, x;
vector<int> ans[2];
struct {
  int son[N], dfn[N], size[N], tp[N], deep[N], id, vis[N << 2], c[N], f[N];
  vector<int> e[N], tag[N << 2];
  void dfs(int x) {
    size[x] = 1;
    for (auto u : e[x]) {
      deep[u] = deep[x] + 1, dfs(u);
      if (size[u] > size[son[x]]) son[x] = u;
      size[x] += size[u];
    }
  }
  void dfs(int x, int top) {
    dfn[x] = ++id, tp[x] = top;
    if (son[x]) dfs(son[x], top);
    for (auto u : e[x]) {
      if (u == son[x]) continue;
      dfs(u, u);
    }
  }
  void add(int k, int l, int r, int L, int R, int x) {
    if (l == L && r == R) {
      tag[k].push_back(x);
      return;
    }
    int mid = (L + R) >> 1;
    if (r <= mid)
      add(k << 1, l, r, L, mid, x);
    else if (l > mid)
      add(k << 1 | 1, l, r, mid + 1, R, x);
    else {
      add(k << 1, l, mid, L, mid, x);
      add(k << 1 | 1, mid + 1, r, mid + 1, R, x);
    }
  }
  void del(int k, int L, int R, int x) {
    if (!vis[k]) {
      for (auto x : tag[k]) {
        if (!c[x]) {
          cnt++;
          ans[now].push_back(x);
          c[x] = 1;
        }
      }
      vis[k] = 1;
    }
    if (L == R) return;
    int mid = (L + R) >> 1;
    if (x <= mid)
      del(k << 1, L, mid, x);
    else
      del(k << 1 | 1, mid + 1, R, x);
  }
  void solve(int x, int y, int tag) {
    while (tp[x] != tp[y]) {
      if (deep[tp[x]] < deep[tp[y]]) std::swap(x, y);
      add(1, dfn[tp[x]], dfn[x], 1, n, tag);
      x = f[tp[x]];
    }
    if (deep[x] > deep[y]) std::swap(x, y);
    if (x != y) add(1, dfn[x] + 1, dfn[y], 1, n, tag);
  }
} T[2];
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &T[0].f[i]);
    T[0].e[T[0].f[i]].push_back(i);
  }
  for (int i = 2; i <= n; i++) {
    scanf("%d", &T[1].f[i]);
    T[1].e[T[1].f[i]].push_back(i);
  }
  T[0].deep[1] = 1, T[1].deep[1] = 1;
  T[0].dfs(1), T[0].dfs(1, 1);
  T[1].dfs(1), T[1].dfs(1, 1);
  for (int i = 2; i <= n; i++) {
    T[1].solve(i, T[0].f[i], i);
    T[0].solve(i, T[1].f[i], i);
  }
  now = 1;
  scanf("%d", &x);
  printf("Blue\n%d\n", x);
  ans[0].push_back(x + 1);
  T[1].c[x + 1] = 1;
  do {
    cnt = 0;
    ans[now].clear();
    for (auto j : ans[now ^ 1]) T[now ^ 1].del(1, 1, n, T[now ^ 1].dfn[j]);
    if (!cnt) break;
    std::sort(ans[now].begin(), ans[now].end());
    puts(now ? "Red" : "Blue");
    for (auto j : ans[now]) printf("%d ", j - 1);
    puts("");
    now = now ^ 1;
  } while (1);
}
