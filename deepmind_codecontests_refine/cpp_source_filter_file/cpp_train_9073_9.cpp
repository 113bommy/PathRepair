#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const double pi = acos(-1.0);
int n, m, f[23][2 * N];
struct point {
  int x, y;
  double arg, l;
} a[N];
struct note {
  double l, r;
} b[2 * N];
bool cmp(note x, note y) { return x.r == y.r ? x.l < y.l : x.r < y.r; }
bool check(double R) {
  for (int i = 1; i <= n; i++) {
    double t = acos(R / a[i].l);
    b[i] = {a[i].arg - t, a[i].arg + t};
    if (b[i].r > pi) b[i].l -= 2 * pi, b[i].r -= 2 * pi;
  }
  std::sort(b + 1, b + n + 1, cmp);
  for (int i = 1; i <= n; i++) b[i + n] = {b[i].l + 2 * pi, b[i].r + 2 * pi};
  f[0][2 * n + 1] = 2 * n + 1;
  for (int i = 1, j = 1; i <= 2 * n; i++) {
    while (j + 1 <= 2 * n && b[j].l <= b[i].r) j++;
    f[0][i] = j;
  }
  int w = 1;
  for (; (1 << w) < m; w++)
    for (int j = 1; j <= 2 * n + 1; j++) f[w][j] = f[w - 1][f[w - 1][j]];
  for (int i = 1; i <= n; i++) {
    int p = i;
    for (int j = w; j >= 0 && p <= 2 * n; j--)
      if (m & (1 << j)) p = f[j][p];
    if (p >= i + n) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  double l = 0, r = 1000000;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].arg = atan2(a[i].y, a[i].x);
    a[i].l = sqrt(1ll * a[i].x * a[i].x + 1ll * a[i].y * a[i].y);
    r = std::min(r, a[i].l);
  }
  while (r - l > 1e-7) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.8lf", l);
}
