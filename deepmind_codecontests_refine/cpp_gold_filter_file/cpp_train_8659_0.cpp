#include <bits/stdc++.h>
using namespace std;
int n, m, x[100001], y[100001];
long long d[100001], tem[100001];
std::set<std::pair<long long, long long> > Set;
long double sq(long double x) { return x * x; }
void get(long long x, long long y, long long now) {
  if (1ll * (x - ::x[1]) * (x - ::x[1]) + 1ll * (y - ::y[1]) * (y - ::y[1]) !=
      now)
    return;
  for (int i = 1; i <= n; i++) {
    tem[i] =
        1ll * (x - ::x[i]) * (x - ::x[i]) + 1ll * (y - ::y[i]) * (y - ::y[i]);
  }
  std::sort(tem + 1, tem + n + 1);
  for (int i = 1; i <= n; i++)
    if (tem[i] != d[i]) return;
  Set.insert(std::make_pair(x, y));
}
void calc(long long x, long long y, long long now) {
  for (int i = x - 20; i <= x + 20; i++)
    for (int j = y - 20; j <= y + 20; j++) get(i, j, now);
}
void check(long long x1, long long y1, long double r1, long long x2,
           long long y2, long long r2) {
  long double dis = sq((long double)x2 - ((long double)x1 / (long double)n)) +
                    sq((long double)y2 - ((long double)y1 / (long double)n));
  if (dis > sq(sqrt(r1) + sqrt((long double)r2)) + 1e-6) return;
  long double k =
      std::atan2(((long double)y1 / (long double)n - (long double)y2),
                 ((long double)x1 / (long double)n) - (long double)x2);
  long double p = ((long double)((long double)r2 + dis - r1)) / 2. / sqrt(dis) /
                  sqrt((long double)r2);
  if (p < -1.) p = -1.;
  if (p > 1.) p = 1.;
  p = acos(p);
  long double X, Y;
  X = sqrt((long double)r2) * cos(k + p);
  Y = sqrt((long double)r2) * sin(k + p);
  calc(x2 + (long long)X, y2 + (long long)Y, r2);
  X = sqrt((long double)r2) * cos(k - p);
  Y = sqrt((long double)r2) * sin(k - p);
  calc(x2 + (long long)X, y2 + (long long)Y, r2);
}
int main() {
  scanf("%d", &n);
  long long sx = 0, sy = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d%d", x + i, y + i), sx += x[i], sy += y[i];
  for (int i = 1; i <= n; i++)
    if (1ll * x[i] * n != sx || 1ll * y[i] * n != sy) {
      std::swap(x[1], x[i]);
      std::swap(y[1], y[i]);
      break;
    }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    for (int i = 1; i <= n; i++) scanf("%lld", d + i);
    std::sort(d + 1, d + n + 1);
    long double r = 0.;
    for (int i = 1; i <= n; i++)
      r += (long double)d[i] -
           (sq((long double)x[i] - (long double)sx / (long double)n) +
            sq((long double)y[i] - (long double)sy / (long double)n));
    r /= n;
    Set.clear();
    for (int i = 1; i <= n; i++) {
      if (!d[i])
        calc(x[1], y[1], 0);
      else
        check(sx, sy, r, x[1], y[1], d[i]);
    }
    printf("%d ", Set.size());
    for (auto it = Set.begin(); it != Set.end(); ++it)
      printf("%lld %lld ", it->first, it->second);
    putchar('\n');
  }
}
