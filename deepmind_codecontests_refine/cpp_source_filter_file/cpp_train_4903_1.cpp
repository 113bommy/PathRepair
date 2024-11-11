#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, ans, f[3000000], v[3000000];
struct pr {
  int x, y;
} a[3000000];
bool cmp(pr x, pr y) { return x.x < y.x; }
int gf(int x) {
  if (f[x] == x) return x;
  f[x] = gf(f[x]);
  return f[x];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (1); i <= (k); i++) scanf("%d%d", &a[i].x, &a[i].y);
  sort(a + 1, a + n + 1, cmp);
  for (int i = (1); i <= (m); i++) f[i] = i;
  for (int i = (1); i <= (k - 1); i++)
    if (a[i].x == a[i + 1].x) {
      x = gf(a[i].y);
      y = gf(a[i + 1].y);
      if (x != y) f[x] = y;
    }
  for (int i = (1); i <= (k); i++) v[a[i].x] = 1;
  ans = -1;
  for (int i = (1); i <= (n); i++)
    if (!v[i]) ans++;
  for (int i = (1); i <= (m); i++)
    if (f[i] == i) ans++;
  printf("%d\n", ans);
}
