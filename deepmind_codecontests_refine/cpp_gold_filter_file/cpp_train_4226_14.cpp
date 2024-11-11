#include <bits/stdc++.h>
using namespace std;
struct eg {
  int u, v, g, s;
  bool operator<(const eg &a) const { return g < a.g || (g == a.g && s < a.s); }
} a[50001], q[201];
int n, m, G, S;
int fa[201];
long long ans;
int find(int x) {
  if (fa[x] != x) fa[x] = find(fa[x]);
  return fa[x];
}
void pre() {
  for (int i = 1; i <= n; i++) fa[i] = i;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &G, &S);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d%d", &a[i].u, &a[i].v, &a[i].g, &a[i].s);
  sort(a + 1, a + m + 1);
  ans = 2000000000000000001;
  for (int i = 1, cnt = 0, r = 0; i <= m; i++, cnt = 0) {
    q[++r] = a[i];
    for (int j = r - 1; j > 0; j--)
      if (q[j + 1].s < q[j].s) swap(q[j + 1], q[j]);
    pre();
    for (int j = 1; j <= r && cnt < n - 1; j++) {
      int u = find(q[j].u), v = find(q[j].v);
      if (u != v) q[++cnt] = q[j], fa[u] = v;
    }
    if (cnt == n - 1) {
      int mx1 = 0, mx2 = 0;
      for (int j = 1; j <= cnt; j++)
        mx1 = max(mx1, q[j].g), mx2 = max(mx2, q[j].s);
      ans = min(ans,
                (long long)mx1 * (long long)G + (long long)mx2 * (long long)S);
    }
    r = cnt;
  }
  if (ans == 2000000000000000001)
    printf("-1\n");
  else
    printf("%lld\n", ans);
  return 0;
}
