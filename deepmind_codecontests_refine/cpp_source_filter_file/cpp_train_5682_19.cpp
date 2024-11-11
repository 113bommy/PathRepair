#include <bits/stdc++.h>
using namespace std;
long long bit[65], f[65][120][2];
inline long long dp(long long s, int tot, int h1, int h2) {
  memset(f, 0, sizeof f);
  f[0][0][0] = 1;
  int ed = log2(s);
  for (int i = 1; i <= ed; ++i) {
    long long d = (s >> i) & 1;
    int ed = i * 2 - 2;
    for (int j = 1; j <= ed; ++j)
      for (int k = 0; k <= 1; ++k)
        for (int p1 = 0; p1 <= 1; ++p1)
          for (int p2 = 0; p2 <= 1; ++p2)
            if ((i < h1 || p1 == 0) && (i < h2 || p2 == 0) &&
                (p1 + p2 + k) % 2 == d)
              f[i][j + p1 + p2][(k + p1 + p2) / 2] += f[i - 1][j][k];
  }
  return f[ed][tot][0];
}
int main() {
  long long x, s, res, ans = 0;
  int ed = 0;
  scanf("%lld", &s);
  bit[0] = 1;
  while (bit[ed] <= s) bit[++ed] = bit[ed - 1] << 1;
  for (int i = 1; i <= ed; ++i) {
    if (bit[i] - 1 > s) break;
    x = s % (bit[i] - 1);
    for (int j = i; j >= 1; --j)
      if (x >= bit[j] - 1) x -= bit[j] - 1;
    if (!x) ++ans;
  }
  for (int h1 = 1; h1 <= ed - 1; ++h1) {
    for (int h2 = 1; bit[h2] - 1 <= s && h2 < ed; ++h2) {
      x = (s - bit[h2] + 1) / (bit[h1 + 1] + bit[h2 + 1] - 3);
      if (x > 0) {
        res = (s - bit[h2] + 1) % (bit[h1 + 1] + bit[h2 + 1] - 3);
        if (res == 0) {
          ++ans;
          continue;
        }
        if (h1 == 1 && h2 == 1) {
          ans += (s == x * 5 + 1);
          continue;
        }
        for (int i = 1; i <= h1 + h2; ++i)
          if ((res + i) % 2 == 0) ans += dp(res + i, i, h1, h2);
      }
    }
  }
  printf("%lld", ans);
}
