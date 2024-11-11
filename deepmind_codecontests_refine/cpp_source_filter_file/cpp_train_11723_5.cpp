#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while ('0' > s || '9' < s) {
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
int n, sum1[1000005], sum2[1000005];
double s, al[1000005], ar[1000005];
struct ming {
  double x, v;
  int dir;
} a[1000005];
bool check(double mid) {
  double L = 1e6;
  bool fg = 0;
  for (int i = 0; i <= L; i++) sum1[i] = sum2[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].dir == 2) continue;
    if (a[i].x / a[i].v <= mid) {
      sum1[0]++;
      sum1[(int)1e6]--;
      break;
    }
    if (a[i].x / (a[i].v + s) > mid) continue;
    al[i] = a[i].x;
    ar[i] =
        min(L - 1, a[i].x + ((a[i].v + s) * mid - a[i].x) * (s - a[i].v) / s);
    sum1[(int)ceil(al[i])]++;
    sum1[(int)floor(ar[i]) + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].dir == 1) continue;
    if ((L - a[i].x) / a[i].v <= mid) {
      sum2[0]++;
      sum2[(int)1e6]--;
      break;
    }
    if ((L - a[i].x) / (a[i].v + s) > mid) continue;
    al[i] =
        max(0.0, a[i].x + ((a[i].v + s) * mid - L + a[i].x) * (a[i].v - s) / s);
    ar[i] = a[i].x;
    sum2[(int)ceil(al[i])]++;
    sum2[(int)floor(ar[i]) + 1]--;
  }
  for (int i = 0; i <= L; i++) {
    if (i) sum1[i] += sum1[i - 1], sum2[i] += sum2[i - 1];
    fg |= (sum1[i] && sum2[i]);
    if (fg) break;
  }
  return fg;
}
signed main() {
  read(n);
  scanf("%lf", &s);
  for (int i = 1; i <= n; i++) scanf("%lf %lf %d", &a[i].x, &a[i].v, &a[i].dir);
  double l = 0, r = 1e6, ans = r;
  while (l + eps < r) {
    double mid = (l + r) / 2.0;
    if (check(mid))
      r = mid - eps, ans = mid;
    else
      l = mid + eps;
  }
  printf("%.6f\n", ans);
  return 0;
}
