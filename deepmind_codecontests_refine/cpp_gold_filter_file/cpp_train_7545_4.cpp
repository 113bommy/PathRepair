#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, kk, a[500005], b[500005], q[500005], fz[500005], fm[500005],
    head[500005];
bool use[500005], del[500005];
struct Edge {
  int nxt, to;
} e[500005];
inline void link(int x, int y) {
  e[++kk].nxt = head[x];
  e[kk].to = y;
  head[x] = kk;
}
bool check(double x) {
  int tot = 0;
  int left1 = 1, right1 = 0;
  for (int i = 1; i <= n; i++) a[i] = fz[i], b[i] = fm[i];
  for (int i = 1; i <= n; i++) {
    if (use[i]) continue;
    tot++;
    del[i] = 0;
    if (1.0 * a[i] / b[i] < x) q[++right1] = i, del[i] = 1, tot--;
  }
  while (left1 <= right1) {
    int u = q[left1++];
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (del[v] || use[v]) continue;
      a[v]--;
      if (1.0 * a[v] / b[v] < x) del[v] = 1, q[++right1] = v, tot--;
    }
  }
  return tot >= 1;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) scanf("%d", &x), use[x] = 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    link(x, y);
    link(y, x);
    fm[x]++;
    fm[y]++;
    if (!use[x]) fz[y]++;
    if (!use[y]) fz[x]++;
  }
  double l = 0;
  double r = 1e9;
  while (l + 1e-12 < r) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  check(l);
  int ans1 = 0;
  for (int i = 1; i <= n; i++)
    if (!del[i] && !use[i]) ans1++;
  printf("%d\n", ans1);
  for (int i = 1; i <= n; i++)
    if (!del[i] && !use[i]) printf("%d ", i);
  return 0;
}
