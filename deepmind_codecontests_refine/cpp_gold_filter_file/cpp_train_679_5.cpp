#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007, M = 200200, mx = 400400, NN = 450040;
int a, b, k, T, t, f[2][NN], ad, ans;
int main() {
  scanf("%d%d%d%d", &a, &b, &k, &T);
  f[0][a - b + M] = 1, f[0][a - b + M + 1] = mod - 1, t = 0;
  for (int i = 1; i <= T * 2; ++i) {
    ad = 0;
    for (int j = 0; j <= mx; ++j) {
      ad = (ad + f[t][j]) % mod;
      f[t ^ 1][max(j - k, 0)] = (f[t ^ 1][max(j - k, 0)] + ad) % mod;
      f[t ^ 1][min(j + k + 1, mx)] =
          (f[t ^ 1][min(j + k + 1, mx)] - ad + mod) % mod;
      f[t][j] = 0;
    }
    t ^= 1;
  }
  ad = 0, ans = 0;
  for (int i = 0; i <= mx; ++i) {
    ad = (ad + f[t][i]) % mod;
    if (i > M) ans = (ans + ad) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
