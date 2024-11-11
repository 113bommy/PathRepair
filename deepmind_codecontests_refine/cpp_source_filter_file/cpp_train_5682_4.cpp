#include <bits/stdc++.h>
using namespace std;
long long f[60][60 * 2][2], s, l, r, tw[60];
signed main() {
  cin >> s;
  l = log2(s + 1);
  tw[0] = 1;
  for (long long i = 1; i < 60; i++) tw[i] = tw[i - 1] * 2;
  for (long long i = 1; i <= l; i++) {
    long long x = s % (tw[i] - 1);
    for (long long j = i; j; j--)
      if (x >= tw[j] - 1) x -= tw[j] - 1;
    if (!x) r++;
  }
  for (long long c = 1; c < l; c++)
    for (long long d = 1; s + 1 - tw[d] >= tw[c + 1] + tw[d + 1] - 3; d++) {
      long long a = (s + 1 - tw[d]) / (tw[c + 1] + tw[d + 1] - 3);
      long long b = (s + 1 - tw[d]) % (tw[c + 1] + tw[d + 1] - 3);
      if (!b) {
        r++;
        continue;
      }
      if (c == 1 && d == 1) {
        if (s == a * 5 + 1) r++;
        continue;
      }
      for (long long n = 1; n <= c + d; n++) {
        memset(f[0], 0, sizeof(f[0]));
        f[0][0][0] = 1;
        long long l = log2(b + n);
        if (l & 1) continue;
        for (long long i = 1; i <= l; i++) {
          memset(f[i], 0, sizeof(f[i]));
          for (long long j = 0; j <= i * 2 - 2 && j <= n; j++)
            for (long long k = 0; k < 2; k++)
              if (f[i - 1][j][k])
                for (long long x = 0; x < 2; x++)
                  if (!x || i < c)
                    for (long long y = 0; y < 2; y++)
                      if (!y || i < d)
                        if (((k + x + y) % 2) == (((b + n) >> i) % 2))
                          f[i][j + x + y][(k + x + y) / 2] += f[i - 1][j][k];
        }
        r += f[l][n][0];
      }
    }
  cout << r;
}
