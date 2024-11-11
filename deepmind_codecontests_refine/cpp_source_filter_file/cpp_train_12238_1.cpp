#include <bits/stdc++.h>
using namespace std;
long long n, x[5010], a[5010], b[5010], c[5010], d[5010], s, e;
long long f[5010][2][2], g[5010][2][2];
int main() {
  cin >> n >> s >> e;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) cin >> d[i];
  x[n + 1] = 1e15 + 1;
  for (int i = 0; i <= n + 5; i++)
    f[i][1][0] = f[i][1][1] = f[i][0][0] = f[i][0][1] = 1e15 + 1;
  f[1][1][1] = 0;
  for (int in = n; in >= 1; in--) {
    for (int j = n; j >= 0; j--) {
      for (int z = 1; z >= 0; z--) {
        for (int t = 1; t >= 0; t--) {
          g[j][z][t] = 1e15 + 1;
          if (in == s) {
            if (j > 0)
              g[j][z][t] =
                  min(g[j][z][t], (2 * j - z - t - 1) * (x[in + 1] - x[in]) +
                                      c[in] + f[j][1][t]);
            g[j][z][t] =
                min(g[j][z][t], (2 * j - z - t + 1) * (x[in + 1] - x[in]) +
                                    d[in] + f[j + 1][1][t]);
          } else if (in == e) {
            if (j > 0)
              g[j][z][t] =
                  min(g[j][z][t], (2 * j - z - t - 1) * (x[in + 1] - x[in]) +
                                      a[in] + f[j][z][1]);
            g[j][z][t] =
                min(g[j][z][t], (2 * j - z - t + 1) * (x[in + 1] - x[in]) +
                                    b[in] + f[j + 1][z][1]);
          } else {
            if (j > 0 && !(j == 1 && z == 1))
              g[j][z][t] =
                  min(g[j][z][t], (x[in + 1] - x[in]) * (2 * j - z - t) +
                                      b[in] + c[in] + f[j][z][t]);
            if (j > 0 && !(j == 1 && t == 1))
              g[j][z][t] =
                  min(g[j][z][t], (x[in + 1] - x[in]) * (2 * j - z - t) +
                                      d[in] + a[in] + f[j][z][t]);
            g[j][z][t] =
                min(g[j][z][t], (x[in + 1] - x[in]) * (2 * j - z - t + 2) +
                                    b[in] + d[in] + f[j + 1][z][t]);
            if (j > 1)
              g[j][z][t] =
                  min(g[j][z][t], (x[in + 1] - x[in]) * (2 * j - z - t - 2) +
                                      a[in] + c[in] + f[j - 1][z][t]);
          }
        }
      }
    }
    swap(g, f);
    f[1][1][1] = 1e15 + 1;
  }
  cout << f[0][0][0] << "\n";
}
