#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const int maxm = 2e5;
int m, n, tot, cnt, a[maxn + 10], b[maxn + 10], father[maxn * 2 + 10];
long long ans;
struct edge {
  int u, v, w;
} e[maxm + 10];
int cmp(edge a, edge b) { return a.w > b.w; }
int find(int x) { return x == father[x] ? x : father[x] = find(father[x]); }
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 1; i <= m; ++i) {
    int s;
    scanf("%d", &s);
    for (int j = 1; j <= s; ++j) {
      int x;
      scanf("%d", &x);
      e[++tot] = (edge){i, x + m, a[i] + b[x]};
      ans += a[i] + b[x];
    }
  }
  sort(e + 1, e + 1 + tot, cmp);
  for (int i = 1; i <= n + m; ++i) father[i] = i;
  for (int i = 1; i <= tot; ++i) {
    int fx = find(e[i].u), fy = find(e[i].v);
    if (fx == fy) continue;
    father[fx] = fy;
    ans -= e[i].w;
    if (++cnt == n + m - 1) break;
  }
  printf("%lld\n", ans);
  return 0;
}
