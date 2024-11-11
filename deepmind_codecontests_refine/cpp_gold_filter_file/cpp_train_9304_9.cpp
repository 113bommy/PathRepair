#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const long double eps = 1e-7;
long long a, w, h;
long double solve() {
  if (a > 90) a = 180 - a;
  if (a == 0) return w * h;
  if (a == 90) return ((min(w, h)) * (min(w, h)));
  long double n[4], k[4], ans = 0, x[9], y[9], w2 = (long double)w / 2,
                          h2 = (long double)h / 2, alpha;
  int len = 0;
  alpha = pi * a / 180;
  k[0] = tan(alpha);
  n[0] = h / (2 * cos(alpha));
  k[1] = -1 / k[0];
  n[1] = -w / (2 * sin(alpha));
  k[2] = k[0];
  k[3] = k[1];
  n[2] = -n[0];
  n[3] = -n[1];
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      y[len] = i ^ j ? -h2 : h2;
      x[len] = (y[len] - n[2 * i]) / k[2 * i];
      if (((-w2 <= x[len] + eps) && (x[len] <= w2 + eps))) ++len;
    }
    for (int j = 0; j < 2; ++j) {
      x[len] = i ^ j ? w2 : -w2;
      y[len] = x[len] * k[2 * i] + n[2 * i];
      if (((-h2 <= y[len] + eps) && (y[len] <= h2 + eps))) ++len;
    }
    for (int j = 0; j < 2; ++j) {
      x[len] = i ^ j ? w2 : -w2;
      y[len] = x[len] * k[2 * i + 1] + n[2 * i + 1];
      if (((-h2 <= y[len] + eps) && (y[len] <= h2 + eps))) ++len;
    }
    for (int j = 0; j < 2; ++j) {
      y[len] = i ^ j ? h2 : -h2;
      x[len] = (y[len] - n[2 * i + 1]) / k[2 * i + 1];
      if (((-w2 <= x[len] + eps) && (x[len] <= w2 + eps))) ++len;
    }
  }
  for (int i = 0; i < len; ++i)
    ans += abs(x[i] * y[(i + 1) % len] - x[(i + 1) % len] * y[i]);
  return ans / 2;
}
int main() {
  scanf("%I64d %I64d %I64d", &w, &h, &a);
  cout << setprecision(15) << fixed;
  cout << solve() << '\n';
  return 0;
}
