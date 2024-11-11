#include <bits/stdc++.h>
using namespace std;
int n;
int x[1000005], y[1000005];
int s[1000005], _sum[1000006], _sumx[1000006], _sumy[1000006],
    *sum = _sum + 1, *sumx = _sumx + 1, *sumy = _sumy + 1;
long long _tot[1000006], *tot = _tot + 1;
const int MOD = 1e9 + 7;
inline int area(int x, int y, int xx, int yy) {
  int ret = ((long long)x * yy - (long long)xx * y) % MOD;
  if (ret < 0) ret += MOD;
  return ret;
}
inline long long areaL(int x, int y, int xx, int yy) {
  return (long long)x * yy - (long long)xx * y;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d%d", x + i, y + i);
  int ans = 0, mul = -1;
  for (int times = 0; times < (int)(2); ++times) {
    for (int i = 0; i < (int)(n + 5); ++i) {
      x[n + i] = x[i];
      y[n + i] = y[i];
    }
    int N = 2 * n + 4;
    for (int i = 0; i < (int)(N); ++i)
      s[i] = area(x[i], y[i], x[i + 1], y[i + 1]);
    tot[-1] = sum[-1] = sumx[-1] = sumy[-1] = 0;
    for (int i = 0; i < (int)(N); ++i)
      tot[i] = tot[i - 1] + areaL(x[i], y[i], x[i + 1], y[i + 1]);
    for (int i = 0; i < (int)(N); ++i)
      sum[i] = (sum[i - 1] - (long long)i * s[i]) % MOD;
    for (int i = 0; i < (int)(N); ++i) sumx[i] = (sumx[i - 1] + x[i]) % MOD;
    for (int i = 0; i < (int)(N); ++i) sumy[i] = (sumy[i - 1] + y[i]) % MOD;
    for (int i = 0, j = 1; i < n; ++i) {
      if (j == i) ++j;
      while (j < i + n - 2 &&
             abs(tot[j] - tot[i - 1] + areaL(x[j + 1], y[j + 1], x[i], y[i])) +
                     times <=
                 abs(tot[n + i - 1] - tot[j] +
                     areaL(x[i], y[i], x[j + 1], y[j + 1]))) {
        ++j;
      }
      if (j == i + 1) continue;
      ans = (ans + mul * (sum[j - 1] - sum[i - 1] +
                          (tot[j - 1] - tot[i - 1]) % MOD * j - s[i])) %
            MOD;
      ans = (ans + mul * areaL(sumx[j] - sumx[i + 1], sumy[j] - sumy[i + 1],
                               x[i], y[i])) %
            MOD;
    }
    if (times == 0) {
      reverse(x + 1, x + n);
      reverse(y + 1, y + n);
      mul = 1;
    }
  }
  int ss = 0;
  for (int i = 0; i < (int)(n); ++i)
    ss = (ss + area(x[i], y[i], x[i + 1], y[i + 1])) % MOD;
  ans = ((long long)ss * ((long long)n * (n - 3) / 2 % MOD) - ans) % MOD;
  if (ans < 0) ans += MOD;
  printf("%d\n", ans);
  return 0;
}
