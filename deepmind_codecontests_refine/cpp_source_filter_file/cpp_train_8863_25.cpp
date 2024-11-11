#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr const int kMod = 998244353;
LL coeff[4000];
LL nCr[2003][2003];
void ComputeComb() {
  nCr[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    nCr[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % kMod;
    }
  }
}
LL modexp(LL a, LL b) {
  LL res = 1;
  while (b) {
    if ((b & 1)) {
      res *= a;
      res %= kMod;
    }
    a *= a;
    a %= kMod;
    b >>= 1;
  }
  return res;
}
int main() {
  ComputeComb();
  int N, K;
  LL L;
  cin >> N >> K >> L;
  for (int k = 0; k <= N - K; k++) {
    for (int i = 0; i <= k; i++) {
      LL cs = 1;
      if ((k - i) % 2 != 0) {
        cs = kMod - 1;
      }
      cs *= nCr[k][i];
      cs %= kMod;
      cs *= nCr[N][k];
      cs %= kMod;
      coeff[N - i] += cs;
      coeff[N - i] %= kMod;
    }
  }
  LL ans = 0;
  for (int g = 0; g <= N; g++) {
    LL csum = 0;
    for (int i = 0; i <= g; i++) {
      LL cs = 1;
      if ((g - i) % 2 == 1) {
        cs = kMod - 1;
      }
      cs *= nCr[g][i];
      cs %= kMod;
      csum += (cs * modexp(2 * g - i + 1, kMod - 2)) % kMod;
    }
    csum %= kMod;
    csum *= modexp(2, g);
    csum %= kMod;
    csum *= coeff[g];
    csum %= kMod;
    ans += csum;
    ans %= kMod;
  }
  ans *= L;
  ans %= kMod;
  cout << ans << endl;
  return 0;
}
