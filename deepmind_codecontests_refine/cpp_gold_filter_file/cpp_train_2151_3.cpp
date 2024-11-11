#include <bits/stdc++.h>
using namespace std;
const int MOD = 323232323;
const int BAS = 233;
const int N = 10;
int m, d;
int powi(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, a = 1ll * a * a % MOD)
    if (b & 1) c = 1ll * c * a % MOD;
  return c;
}
map<long long, int> M;
int v[N][N], w[N], tot;
int main() {
  scanf("%d%d", &m, &d);
  for (int i = 1; i <= m; ++i) {
    for (int p = 0; p < d; ++p)
      for (int q = 0; q < d; ++q) v[p][q] = 0;
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      for (int p = 0; p < d; ++p) {
        scanf("%d", &w[p]);
        if (w[p] < 0) w[p] += MOD;
      }
      for (int p = 0; p < d; ++p)
        if (w[p]) {
          if (!v[p][p]) {
            int x = powi(w[p], MOD - 2);
            for (int q = p; q < d; ++q) v[p][q] = 1ll * w[q] * x % MOD;
            break;
          } else {
            int x = w[p];
            for (int q = p; q < d; ++q)
              w[q] = (w[q] - 1ll * v[p][q] * x % MOD + MOD) % MOD;
          }
        }
    }
    for (int p = d - 1; ~p; --p)
      if (v[p][p])
        for (int q = 0; q < p; ++q)
          if (v[q][p]) {
            int x = v[q][p];
            for (int r = p; r < d; ++r)
              v[q][r] = (v[q][r] - 1ll * x * v[p][r] % MOD + MOD) % MOD;
          }
    long long key = 0;
    for (int p = 0; p < d; ++p)
      for (int q = 0; q < d; ++q) key = key * BAS + v[p][q];
    if (!M.count(key)) M[key] = ++tot;
    printf("%d\n", M[key]);
  }
}
