#include <bits/stdc++.h>
using namespace std;
double const eps = 1e-10;
int const INF = 100000;
int const MOD = 1;
int const MAX = 1000 * 100 + 5;
int a[MAX];
int b[MAX];
int n;
long long check(long long x, int c) {
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != 0 && x > ((long long)b[i] * (c - res) + a[i] - 1) / a[i])
      return c + 1;
    res += a[i] * x / b[i] + 1;
  }
  return res;
}
int main() {
  int i, j, c;
  long long m = 0;
  scanf("%d%d", &n, &c);
  if (c < n) {
    printf("0");
    return 0;
  }
  bool f = false;
  double A = 0;
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    A += (double)a[i] / b[i];
    if (a[i] != 0) f = true;
  }
  if (!f && c == n) {
    printf("-1");
    return 0;
  }
  long long t = 2 * (long long)(c / A + eps);
  long long left = 0, right = t + 1;
  while (left + 1 < right) {
    m = (left + right) / 2;
    long long k = check(m, c);
    if (k < c)
      left = m;
    else
      right = m;
  }
  long long res = -left;
  left = 0, right = t + 1;
  while (left + 1 < right) {
    m = (left + right) / 2;
    long long k = check(m, c);
    if (k <= c)
      left = m;
    else
      right = m;
  }
  res += left;
  cout << max(res, (long long)0);
  return 0;
}
