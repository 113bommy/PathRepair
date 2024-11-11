#include <bits/stdc++.h>
const int N = 21;
int n, m;
char s[51][N];
long long f[1 << N];
int bit[1 << N], er[1 << N];
double ans[1 << N];
int count(long long x) {
  int ans = 0;
  while (x) {
    long long low = (x & -x);
    x -= low;
    ans++;
  }
  return ans;
}
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf(" %s", s[i] + 1);
  n = strlen(s[1] + 1);
  for (int i = 1; i <= m; ++i)
    for (int j = i + 1; j <= m; ++j) {
      int sta = 0;
      for (int k = 1; k <= n; ++k)
        if (s[i][k] == s[j][k]) sta |= (1 << k - 1);
      f[sta] |= (1ll << i - 1);
      f[sta] |= (1ll << j - 1);
    }
  for (int i = (1 << n) - 1; i + 1; --i)
    for (int j = 1; j <= n; ++j)
      if (f[i] && ((i >> j - 1) & 1)) f[i ^ (1 << j - 1)] |= f[i];
  for (int i = 0; i < 1 << n; ++i)
    bit[i] = count(f[i]), er[i] = er[i >> 1] + (i & 1);
  for (int i = (1 << n) - 1; i + 1; --i) {
    int sum = n - er[i];
    if (!bit[i]) continue;
    for (int j = 1; j <= n; ++j) {
      if (!((i >> j - 1) & 1))
        ans[i] += 1.0 * (1.0 * ans[i ^ (1 << j - 1)] / sum) *
                  (1.0 * bit[i ^ (1 << j - 1)] / bit[i]);
    }
    ans[i] += 1;
  }
  printf("%.10lf", ans[0]);
  return 0;
}
