#include <bits/stdc++.h>
using namespace std;
int n, m, fa[100010], siz[100010];
double ans;
int getfa(int w) { return (w == fa[w]) ? w : fa[w] = getfa(fa[w]); }
struct edg {
  int nx, ny, val;
  bool operator<(const edg& e) const { return val > e.val; }
} a[100010];
int main() {
  cin >> n >> m;
  int b[100010];
  long long tot = 0;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = (edg){x, y, min(b[x], b[y])};
  }
  sort(a, a + m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= n; i++) siz[i] = 1;
  for (int i = 0; i < m; i++)
    if (getfa(a[i].nx) ^ getfa(a[i].ny)) {
      int x = a[i].nx, y = a[i].ny;
      tot += (long long)a[i].val * siz[fa[x]] * siz[fa[y]];
      siz[fa[x]] += siz[fa[y]];
      fa[fa[y]] = fa[x];
    }
  ans = tot;
  tot = (long long)n * (n - 1) / 2;
  ans /= tot;
  printf("%.06lf", ans);
  return 0;
}
