#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 10, MOD = (int)1e+9 + 7;
long long fac[MAXN], Ifac[MAXN], T;
int k, w;
long long Pow(long long a, long long b) {
  long long d = 1;
  for (; b; d = (b & 1) ? d * a % MOD : d, a = a * a % MOD, b /= 2)
    ;
  return d;
}
int A(int x, int y) { return fac[x] * Ifac[x - y] % MOD; }
int main() {
  cin >> k >> w;
  fac[0] = Ifac[0] = 1;
  for (int i = 1; i <= k; ++i)
    fac[i] = fac[i - 1] * i % MOD,
    Ifac[i] = Ifac[i - 1] * Pow(i, MOD - 2) % MOD;
  long long CC = 0, t = Pow(k, w - 2);
  for (int i = 1; i <= k; ++i) {
    if (i < w)
      CC = (CC + A(k, i) * A(k, i) % MOD * t % MOD * i % MOD) % MOD;
    else
      CC = (CC + A(k, i) * A(k + w - 1 - i, w - 1) % MOD * w) % MOD;
    if (i < k) {
      t = t * Pow(k, MOD - 2) % MOD;
      if (i + 2 <= w)
        CC = (CC + A(k, i) * A(k, i + 1) % MOD * t % MOD * i % MOD) % MOD;
      else
        CC =
            (CC + A(k, i + 1) * A(k - i + w - 2, w - 2) % MOD * (w - 1) % MOD) %
            MOD;
    }
  }
  cout << (CC + MOD) % MOD << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
