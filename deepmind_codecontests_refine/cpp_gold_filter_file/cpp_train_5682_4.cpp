#include <bits/stdc++.h>
using namespace std;
long long s, ans, f[60][120][2];
bool check(long long num, int o) {
  int cnt = 0;
  while (num) cnt += (num & 1), num >>= 1;
  return cnt == o;
}
void dp(int l, int r, int k, long long num) {
  for (int i = 0; (1ll << i) <= num << 1; ++i)
    for (int j = 0; j <= min(k + 2, 2 * i); ++j) f[i][j][0] = f[i][j][1] = 0;
  f[0][0][0] = 1;
  int cnt = 0;
  for (int i = 0; (1ll << i) <= num; ++i) {
    ++cnt;
    for (int j = 0; j <= min(k, 2 * i); ++j)
      for (int o = 0; o < 2; ++o)
        for (int a = 0, b; a < 2; ++a) {
          b = ((num >> i + 1) ^ (o + a)) & 1;
          if (a && i + 2 > l) continue;
          if (b && i + 2 > r) continue;
          f[i + 1][j + a + b][(o + a + b) >> 1] += f[i][j][o];
        }
  }
  ans += f[cnt][k][0];
}
int main() {
  scanf("%lld", &s);
  for (int i = 1; (1ll << i) <= s + 1; ++i) {
    long long x = s - s / ((1ll << i) - 1) * ((1ll << i) - 1);
    if (x > (1ll << i) - 2) continue;
    for (int j = (x & 1); j <= i; j += 2)
      if (check(x + j, j)) ++ans;
  }
  for (int l = 1; (1ll << l + 1) <= s; ++l)
    for (int r = 1; (1ll << r + 1) <= s; ++r) {
      long long x =
          (s - (1ll << r) + 1) / ((1ll << l + 1) + (1ll << r + 1) - 3);
      if (x <= 0) continue;
      x = (s - (1ll << r) + 1) - x * ((1ll << l + 1) + (1ll << r + 1) - 3);
      for (int k = (x & 1); k <= l + r - 2; k += 2) dp(l, r, k, x + k);
    }
  printf("%lld", ans);
  return 0;
}
