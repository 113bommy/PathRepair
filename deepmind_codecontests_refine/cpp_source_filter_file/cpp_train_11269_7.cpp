#include <bits/stdc++.h>
using namespace std;
const int MD = 1000000007;
const int MAXN = 1000500;
int fac[MAXN], revF[MAXN];
int powMod(int x, int st) {
  int res = 1;
  while (st) {
    if (st & 1) {
      res = 1ll * res * x % MD;
    }
    st /= 2;
    x = 1ll * x * x % MD;
  }
  return res;
}
int main() {
  fac[0] = revF[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fac[i] = 1ll * fac[i - 1] * i % MD;
    revF[i] = powMod(fac[i], MD - 2);
  }
  int k, w;
  cin >> k >> w;
  int res = 0;
  for (int t = 1; t <= k; ++t) {
    if (t <= w - 1) {
      int add_cur = 1ll * powMod(1ll * fac[k] * revF[k - t] % MD, 2) * t % MD;
      res = (res + 1ll * add_cur * powMod(k, w - t - 1)) % MD;
    } else {
      int add_cur = 1ll * fac[k] * revF[k - t] % MD * revF[k - t] % MD * w % MD;
      res = (res + 1ll * add_cur * fac[k - t + w - 1]) % MD;
    }
  }
  for (int t = 1; t <= k; ++t) {
    if (t + 1 <= w - 1) {
      int add_cur = 1ll * fac[k] * revF[k - t] % MD * t % MD * fac[k] % MD *
                    revF[k - t - 1] % MD;
      res = (res + 1ll * add_cur * powMod(k, w - t - 2)) % MD;
    } else {
      int add_cur =
          1ll * fac[k] * revF[k - 1] % MD * revF[k - t - 1] % MD * (w - 1) % MD;
      res = (res + 1ll * add_cur * fac[k - t + w - 2]) % MD;
    }
  }
  cout << res << '\n';
  return 0;
}
