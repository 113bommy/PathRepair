#include <bits/stdc++.h>
using namespace std;
const int maxn = 200009;
int n, k, m;
int sz[maxn], mx[maxn], mx2[maxn], cnt[maxn], w[maxn];
bool F[maxn];
struct edge {
  int t;
  edge* n;
} E[maxn << 1], *pt = E, *H[maxn];
inline void AddEdge(int u, int v) {
  pt->t = v;
  pt->n = H[u];
  H[u] = pt++;
}
void dfs(int x, int fa) {
  sz[x] = 1;
  cnt[x] = mx[x] = mx2[x] = 0;
  F[x] = (w[x] >= m);
  for (edge* e = H[x]; e; e = e->n)
    if (e->t != fa) {
      dfs(e->t, x);
      sz[x] += sz[e->t];
      F[x] += F[e->t];
      if (w[e->t] < m) continue;
      if (F[e->t] == sz[e->t]) {
        cnt[x] += sz[e->t];
      } else
        mx2[x] = max(mx2[x], cnt[e->t] + mx[e->t] + 1);
      if (mx2[x] > mx[x]) swap(mx2[x], mx[x]);
    }
}
void DFS(int x, int fa) {
  for (edge* e = H[x]; e; e = e->n)
    if (e->t != fa) {
      if (w[x] >= m) {
        if (n - sz[e->t] == F[0] - F[e->t]) {
          cnt[e->t] += n - sz[e->t];
        } else if (F[e->t] == sz[e->t]) {
          mx2[e->t] = max(mx2[e->t], cnt[x] - sz[e->t] + mx[x] + 1);
        } else if (mx[x] == cnt[e->t] + mx[e->t] + 1)
          mx2[e->t] = max(mx2[e->t], cnt[x] + mx2[x] + 1);
        else
          mx2[e->t] = max(mx2[e->t], cnt[x] + mx[x] + 1);
        if (mx2[x] > mx[x]) swap(mx2[x], mx[x]);
      }
      DFS(e->t, x);
    }
}
bool chk() {
  dfs(0, -1);
  DFS(0, -1);
  for (int i = 0; i < n; i++)
    if (w[i] >= m && cnt[i] + mx[i] + 1 >= k) return true;
  return false;
}
void Work() {
  int l = 1, r = 1000000, ans;
  while (l <= r) {
    m = (l + r) >> 1;
    if (chk())
      l = m + 1, ans = m;
    else
      r = m - 1;
  }
  printf("%d\n", ans);
}
void Init() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", w + i);
  }
  int u, v;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    AddEdge(u, v);
    AddEdge(v, u);
  }
}
int main() {
  Init();
  Work();
  return 0;
}
