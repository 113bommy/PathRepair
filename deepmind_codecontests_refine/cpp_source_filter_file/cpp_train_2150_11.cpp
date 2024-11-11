#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100000;
const int MAXXY = 200000 + 10;
const int MAXUV = 2 * MAXXY;
int n;
int x[MAXN], y[MAXN];
int u[MAXN], v[MAXN];
int a[MAXUV + 1];
int b[MAXUV + 1];
int c[MAXUV + 1];
int d[MAXUV + 1];
long long calc(int par) {
  for (int i = (0); i <= (MAXUV); ++i) a[i] = INT_MIN;
  for (int i = (0); i < (n); ++i)
    if ((x[i] + y[i]) % 2 == par && v[i] != 0)
      a[v[i] - 1] = max(a[v[i] - 1], u[i] - 1);
  for (int i = MAXUV - 1; i >= 0; --i) a[i] = max(a[i], a[i + 1]);
  for (int i = (0); i <= (MAXUV); ++i) b[i] = INT_MIN;
  for (int i = (0); i < (n); ++i)
    if ((x[i] + y[i]) % 2 == par && v[i] != MAXUV)
      b[v[i] + 1] = max(b[v[i] + 1], u[i] - 1);
  for (int i = (1); i <= (MAXUV); ++i) b[i] = max(b[i], b[i - 1]);
  for (int i = (0); i <= (MAXUV); ++i) c[i] = INT_MAX;
  for (int i = (0); i < (n); ++i)
    if ((x[i] + y[i]) % 2 == par && v[i] != 0)
      c[v[i] - 1] = min(c[v[i] - 1], u[i] + 1);
  for (int i = MAXUV - 1; i >= 0; --i) c[i] = min(c[i], c[i + 1]);
  for (int i = (0); i <= (MAXUV); ++i) d[i] = INT_MAX;
  for (int i = (0); i < (n); ++i)
    if ((x[i] + y[i]) % 2 == par && v[i] != MAXUV)
      d[v[i] + 1] = min(d[v[i] + 1], u[i] + 1);
  for (int i = (1); i <= (MAXUV); ++i) d[i] = min(d[i], d[i - 1]);
  int ret = 0;
  for (int i = (0); i <= (MAXUV); ++i)
    if (i % 2 != par) {
      int mx = min(a[i], b[i]), mn = max(c[i], d[i]);
      if (mn > mx) continue;
      if (mx != INT_MIN && mx % 2 != i % 2) --mx;
      if (mn != INT_MAX && mn % 2 != i % 2) ++mn;
      if (mn > mx) continue;
      int cur = (mx - mn) / 2 + 1;
      ret += cur;
    }
  return ret;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i)
    scanf("%d%d", &x[i], &y[i]), x[i] += MAXXY / 2, y[i] += MAXXY / 2;
  for (int i = (0); i < (n); ++i)
    u[i] = x[i] + y[i], v[i] = y[i] - x[i] + MAXUV / 2;
  long long ret = 0;
  ret += calc(0);
  ret += calc(1);
  printf("%lld\n", ret);
}
int main() {
  run();
  return 0;
}
