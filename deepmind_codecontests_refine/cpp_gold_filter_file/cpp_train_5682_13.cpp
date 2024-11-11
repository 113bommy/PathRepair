#include <bits/stdc++.h>
using namespace std;
const long long N = 55;
long long S, ans, L;
long long Pow[N];
long long f[N][N * 2][2];
int main() {
  scanf("%lld", &S);
  L = log2(S + 1);
  Pow[0] = 1;
  for (long long u = 1; u < N; u++) Pow[u] = Pow[u - 1] * 2;
  for (long long u = 1; u <= L; u++) {
    long long x = S % (Pow[u] - 1);
    for (long long i = u; i > 0; i--)
      if (x >= Pow[i] - 1) x = x - (Pow[i] - 1);
    if (x == 0) ans++;
  }
  for (long long h0 = 1; h0 <= L; h0++)
    for (long long h1 = 1; S + 1 - Pow[h1] >= Pow[h0 + 1] + Pow[h1 + 1] - 3;
         h1++) {
      long long x = (S + 1 - Pow[h1]) / (Pow[h0 + 1] + Pow[h1 + 1] - 3);
      long long v = (S + 1 - Pow[h1]) % (Pow[h0 + 1] + Pow[h1 + 1] - 3);
      if (v == 0) {
        ans++;
        continue;
      }
      if (h0 == 1 && h1 == 1) {
        ans = ans + (S == x * 5 + 1);
        continue;
      }
      for (long long u = 1; u <= h0 + h1 - 2; u++) {
        long long c = v + u;
        long long t = log2(c);
        if (c & 1) continue;
        memset(f, 0, sizeof(f));
        f[0][0][0] = 1;
        for (long long i = 1; i <= t; i++) {
          long long d = (c >> i) & 1;
          for (long long j = 0; j <= u; j++)
            for (long long k = 0; k < 2; k++)
              if (f[i - 1][j][k])
                for (long long a = 0; a < 2; a++)
                  if (a == 0 || i < h0)
                    for (long long b = 0; b < 2; b++)
                      if (b == 0 || i < h1)
                        if (((k + a + b) & 1) == d)
                          f[i][j + a + b][(k + a + b) / 2] =
                              f[i][j + a + b][(k + a + b) / 2] + f[i - 1][j][k];
        }
        ans = ans + f[t][u][0];
      }
    }
  printf("%lld\n", ans);
  return 0;
}
