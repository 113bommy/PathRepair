#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const int maxn = 45;
int n1, n2, n3, d1, d2, n, a[maxn], m;
double r1, r2, r3, res, ans;
inline double getsum() {
  double sum = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != 3) continue;
    int x = i;
    if (x > m) x -= m;
    double L3 = x - r3, R3 = x + r3;
    for (int j = 1; j <= n; j++) {
      if (a[j] == 3) continue;
      int y = j, t = a[j];
      if (y > m) y -= m;
      if (t == 1) {
        double L1 = y - r1, R1 = y + r1;
        sum += max(0.0, d1 * (min(R1, R3) - max(L1, L3)));
      } else if (t == 2) {
        double L2 = y - r2, R2 = y + r2;
        sum += max(0.0, d2 * (min(R2, R3) - max(L2, L3)));
      }
    }
  }
  return res + sum;
}
inline void solve() {
  double t = 10000;
  double ans = 0;
  while (t > 1e-12) {
    int xx = rand() % n + 1, yy = rand() % n + 1;
    while (a[xx] == a[yy]) xx = rand() % n + 1, yy = rand() % n + 1;
    swap(a[xx], a[yy]);
    double zp = getsum();
    if (zp > ans) {
      ans = zp;
      star::ans = max(star::ans, ans);
    } else if (rand() < exp((ans - zp) / t / 1.38e-23) * RAND_MAX)
      swap(a[xx], a[yy]);
    else
      ans = zp;
    t *= 0.99;
  }
}
inline void work() {
  n1 = read(), n2 = read(), n3 = read();
  r1 = read();
  r1 = sqrt(r1 * r1 - 1);
  r2 = read();
  r2 = sqrt(r2 * r2 - 1);
  r3 = read();
  r3 = sqrt(r3 * r3 - 1);
  d1 = read(), d2 = read();
  res = 2 * n1 * r1 * d1 + 2 * n2 * r2 * d2;
  if (n3 == 0) return (void)printf("%.10lf", res);
  n = n1 + n2 + n3;
  for (int i = 1; i <= n; i++)
    if (n1)
      a[i] = 1, n1--;
    else if (n2)
      a[i] = 2, n2--;
    else if (n3)
      a[i] = 3, n3--;
  m = n / 2 + 1;
  n = m * 2;
  random_shuffle(a + 1, a + 1 + n);
  srand(time(0));
  for (int i = 1; i <= 100; i++) solve();
  printf("%.10lf\n", ans);
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
