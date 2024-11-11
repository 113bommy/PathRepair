#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
double ans;
int n, m = 1000000;
int d[2000005], u[2000005];
int x[100005], y[100005];
void solve() {
  for (int i = -m; i <= m; i++) d[i + m] = 1000000000, u[i + m] = -1000000000;
  int lm = m, rm = -m;
  for (int i = 1; i <= n; i++) lm = min(lm, x[i]), rm = max(rm, x[i]);
  for (int i = 1; i <= n; i++) {
    if (x[i] == x[i + 1]) {
      u[x[i] + m] = max(u[x[i] + m], y[i]);
      d[x[i] + m] = min(d[x[i] + m], y[i]);
      continue;
    }
    bool flag = 0;
    if (x[i] > x[i + 1]) {
      swap(x[i], x[i + 1]), swap(y[i], y[i + 1]);
      flag = 1;
    }
    for (int j = x[i]; j <= x[i + 1]; j++) {
      double now =
          (double)(j - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]) + y[i];
      d[j + m] = min((int)ceil(now), d[j + m]);
      u[j + m] = max((int)floor(now), u[j + m]);
    }
    if (flag) swap(x[i], x[i + 1]), swap(y[i], y[i + 1]);
  }
  double s0 = 0, s1 = 0, s2 = 0;
  for (long long i = lm; i <= rm; i++) {
    long long t = u[i + m] - d[i + m] + 1;
    s0 += t;
    s1 += t * i;
    s2 += t * i * i;
  }
  ans += (double)(s0 * s2 - s1 * s1) / s0 / (s0 - 1);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
  x[n + 1] = x[1];
  y[n + 1] = y[1];
  solve();
  for (int i = 1; i <= n + 1; i++) swap(x[i], y[i]);
  solve();
  printf("%.10lf\n", ans);
  return 0;
}
