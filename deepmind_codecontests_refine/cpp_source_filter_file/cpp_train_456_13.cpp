#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int maxm = 1e3 + 10;
struct Edge {
  int to, next;
  int l, r;
} E[maxn];
int head[maxm], L[maxn], R[maxn], cnt, n, m;
bool vis[maxn];
inline void init() {
  memset(head, -1, sizeof head);
  cnt = 0;
}
inline void addedge(int u, int v, int l, int r) {
  E[cnt].to = v;
  E[cnt].l = l;
  E[cnt].r = r;
  E[cnt].next = head[u];
  head[u] = cnt++;
}
bool dfs(int u, int l, int r) {
  if (u == n) return 1;
  for (int i = head[u]; ~i; i = E[i].next) {
    int v = E[i].to, ll = E[i].l, rr = E[i].r;
    if (!vis[v] && ll <= l && r <= rr) {
      vis[v] = 1;
      if (dfs(v, l, r)) return 1;
    }
  }
  return 0;
}
int main() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b, l, r;
    scanf("%d%d%d%d", &a, &b, &l, &r);
    addedge(a, b, l, r);
    addedge(b, a, l, r);
    L[i] = l;
    R[i] = r;
  }
  sort(L + 1, L + m + 1);
  sort(R + 1, R + m + 1);
  int ans = -1;
  for (int i = 1; i <= m; i++) {
    int l = i, r = m;
    while (l <= r) {
      int mid = l + r >> 1;
      memset(vis, 0, sizeof vis);
      vis[1] = 1;
      if (dfs(1, L[i], R[mid])) {
        ans = max(ans, R[mid] - L[i] + 1);
        l = mid + 1;
      } else
        r = mid - 1;
    }
  }
  if (ans == -1)
    puts("Nice work, Dima!");
  else
    printf("%d\n", ans);
  return 0;
}
