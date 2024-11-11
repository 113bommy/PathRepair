#include <bits/stdc++.h>
long long inf = 1LL << 58;
using namespace std;
long long f[200][200];
long long x[60], y[60], b[60];
int mark[60];
long long ans, l, r, mid;
int n;
int check(long long w) {
  for (int i = 1; i <= n; ++i) y[i] = x[i] - b[i] * w;
  long long temp;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j)
      if (x[i] < x[j] || (x[i] == x[j] && y[i] < y[j])) {
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        temp = y[i];
        y[i] = y[j];
        y[j] = temp;
        temp = b[i];
        b[i] = b[j];
        b[j] = temp;
      }
  }
  for (int i = 1; i <= n; ++i) {
    if (i == n || x[i] != x[i + 1])
      mark[i] = 1;
    else
      mark[i] = 0;
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) f[i][j] = inf;
  int last = 0;
  long long sum;
  f[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (mark[i] == 0) continue;
    for (int j = 0; j <= n; ++j) {
      sum = 0;
      for (int k = last + 1; k <= i; ++k) sum += y[k];
      for (int k = 0; k <= j; ++k) {
        if (k > i - last) break;
        if (f[i][j - k + i - last - k] > f[last][j] + sum)
          f[i][j - k + i - last - k] = f[last][j] + sum;
        sum -= y[i - k];
      }
    }
    last = i;
  }
  for (int j = 0; j <= n; ++j)
    if (f[n][j] <= 0) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &x[i]);
    x[i] *= 1000;
  }
  for (int i = 1; i <= n; ++i) scanf("%I64d", &b[i]);
  l = 0;
  r = 1LL << 45;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  ans = r;
  if (check(l)) ans = l;
  printf("%I64d\n", ans);
  return 0;
}
