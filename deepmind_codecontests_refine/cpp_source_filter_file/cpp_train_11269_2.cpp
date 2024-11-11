#include <bits/stdc++.h>
using namespace std;
const int kMaxK = 1000000, kMod = 1000000007;
int k, w, ans;
int inv[kMaxK + 1], fac[kMaxK + 1], fac_inv[kMaxK + 1];
int PowerMod(int a, int b) {
  int res = 1, tmp = a;
  while (b) {
    if (b & 1) res = (long long)res * tmp % kMod;
    b >>= 1;
    tmp = (long long)tmp * tmp % kMod;
  }
  return res;
}
int main() {
  scanf("%d%d", &k, &w);
  fac[0] = fac_inv[0] = 1;
  for (int i = 1; i <= k; ++i) {
    inv[i] = PowerMod(i, kMod - 2);
    fac[i] = (long long)fac[i - 1] * i % kMod;
    fac_inv[i] = (long long)fac_inv[i - 1] * inv[i] % kMod;
  }
  for (int t = 1; t <= k; ++t) {
    if (t <= w - 1) {
      {
        (ans) += ((long long)t * fac[k] % kMod * fac[k] % kMod *
                  PowerMod(k, w - 1 - t) % kMod * fac_inv[k - t] % kMod *
                  fac_inv[k - t] % kMod);
        if ((ans) >= kMod) (ans) -= kMod;
      };
    } else {
      {
        (ans) += ((long long)fac[k] * w % kMod * fac[k - t + w - 1] % kMod *
                  fac_inv[k - t] % kMod * fac_inv[k - t] % kMod);
        if ((ans) >= kMod) (ans) -= kMod;
      };
    }
  }
  for (int t = 1; t < k; ++t) {
    if (t + 1 <= w - 1) {
      {
        (ans) += ((long long)t * fac[k] % kMod * fac[k] % kMod *
                  PowerMod(k, w - t - 2) % kMod * fac_inv[k - t] % kMod *
                  fac_inv[k - t - 1] % kMod);
        if ((ans) >= kMod) (ans) -= kMod;
      };
    } else {
      {
        (ans) += ((long long)fac[k] * (w - 1) % kMod * fac[k - t + w - 2] %
                  kMod * fac[k - t] % kMod * fac[k - t - 1] % kMod);
        if ((ans) >= kMod) (ans) -= kMod;
      };
    }
  }
  printf("%d\n", ans);
  return 0;
}
