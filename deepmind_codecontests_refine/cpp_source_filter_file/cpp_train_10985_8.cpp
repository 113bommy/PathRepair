#include <bits/stdc++.h>
using namespace std;
long double read_ld() {
  double x;
  scanf("%lf", &x);
  return x;
}
const int MAXN = 1e5 + 10;
const long double EPS = 1e-9;
long double mx[MAXN];
long double mn[MAXN];
int n;
long double a[MAXN];
long double b[MAXN];
bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < (int)n; ++i) {
    mx[i] = read_ld();
  }
  for (int i = 0; i < (int)n; ++i) {
    mn[i] = read_ld();
  }
  return true;
}
long double p[MAXN];
long double q[MAXN];
pair<long double, long double> get(long double x, long double y) {
  long double p = (y + sqrt(max((long double)-1, y * y - 4 * x))) * 0.5;
  return make_pair(p, y - p);
}
void solve() {
  long double sum_mx = 0;
  for (int i = 0; i < (int)n; ++i) {
    sum_mx += mx[i];
    a[i] = sum_mx;
  }
  long double sum_mn = 0;
  for (int i = ((int)n) - 1; i >= 0; --i) {
    if (i == 0) {
      break;
    }
    b[i - 1] = 1.0 - mn[i] - sum_mn + a[i - 1];
    sum_mn += mn[i];
  }
  b[n - 1] = 2.0;
  for (int i = 0; i < (int)n; ++i) {
    long double P, Q;
    tie(P, Q) = get(a[i], b[i]);
    if (i == 0) {
      p[i] = P;
      q[i] = Q;
      continue;
    }
    if (P >= p[i - 1] - EPS && Q >= q[i - 1] - EPS) {
      p[i] = P;
      q[i] = Q;
    } else {
      p[i] = Q;
      q[i] = P;
    }
  }
  for (int i = 0; i < (int)n; ++i) {
    long double cur = p[i];
    if (i) cur -= p[i - 1];
    cur = max(cur, (long double)0.0);
    printf("%.15f ", (double)cur);
  }
  puts("");
  for (int i = 0; i < (int)n; ++i) {
    long double cur = q[i];
    if (i) cur -= q[i - 1];
    cur = max(cur, (long double)0.0);
    printf("%.15f ", (double)cur);
  }
  puts("");
}
int main() {
  while (read()) {
    solve();
  }
  return 0;
}
