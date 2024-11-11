#include <bits/stdc++.h>
using namespace std;
namespace star {
const long long maxn = 52;
long long n, D, f[2][maxn << 1][2], p[maxn], ans;
inline long long calc(long long s, long long a, long long b, long long t) {
  memset(f, 0, sizeof f);
  f[0][0][0] = 1;
  long long p = 0;
  for (long long i = 1; i <= log2(s) + 1; i++) {
    long long d = (s >> i) & 1;
    p ^= 1, memset(f[p], 0, sizeof f[p]);
    for (long long j = 0; j <= 2 * i - 2; j++)
      for (long long k = 0; k < 2; k++)
        if (f[p ^ 1][j][k])
          for (long long x = 0; x < 2; x++)
            if (!x or i < a)
              for (long long y = 0; y < 2; y++)
                if (!y or i < b)
                  if (((k + x + y) & 1) == d)
                    f[p][j + x + y][(k + x + y) & 1] += f[p ^ 1][j][k];
  }
  return f[p][t][0];
}
inline void work() {
  scanf("%lld", &n);
  long long x = n;
  p[0] = 1;
  while (x) x >>= 1, ++D, p[D] = p[D - 1] << 1;
  p[D + 1] = p[D] << 1;
  for (long long i = 1; i <= D; i++)
    if ((x = n / (p[i] - 1)) > 0) {
      long long res = n - x * (p[i] - 1);
      for (long long j = i - 1; ~j; j--)
        if (res >= p[j] - 1) res -= p[j] - 1;
      if (!res) ++ans;
    }
  for (long long i = 1; i <= D; i++)
    for (long long j = 1; p[j] - 1 <= n; j++)
      if ((x = (n - p[j] + 1) / (p[i + 1] + p[j + 1] - 3)) > 0) {
        long long res = (n - p[j] + 1) - x * (p[i + 1] + p[j + 1] - 3);
        if (!res) {
          ++ans;
          continue;
        }
        if (i == 1 and j == 1) {
          ans += res == 5 * x + 1;
          continue;
        }
        for (long long k = 1; k <= i + j; k++)
          if ((res + k) & 1 ^ 1) ans += calc(res + k, i, j, k);
      }
  printf("%lld\n", ans);
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
