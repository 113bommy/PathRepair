#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, ten = 10;
long long md;
long long pr10(long long x) {
  if (x == 0) {
    return 1;
  }
  long long ret = (pr10(x / 2)) % md;
  ret *= ret;
  ret %= md;
  if (x % 2) {
    ret = (ret * ten) % md;
  }
  return ret;
}
long long pwr[34][100] = {0}, a[500010], n;
void pre() {
  long long tmp;
  for (long long i = 0; i < n; ++i) {
    ++pwr[0][a[i] % md];
  }
  for (long long i = 1; i < 33; ++i) {
    for (long long j = 0; j < 100; ++j) {
      for (long long k = 0; k < 100; ++k) {
        tmp = (j * pr10(1ll << (i - 1)) + k) % md;
        pwr[i][tmp] += (pwr[i - 1][j] * pwr[i - 1][k]) % mod;
        pwr[i][tmp] %= mod;
      }
    }
  }
}
int main() {
  long long tmp, b[100] = {0}, b2[100] = {0}, kk, p, tmp2;
  cin >> n >> p >> kk >> md;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  pre();
  for (long long k = 0; k < 100; ++k) b[k] = pwr[0][k];
  --p;
  for (long long i = 32; i >= 0; --i) {
    tmp = (1ll << i);
    if (tmp & p) {
      for (long long k = 0; k < 100; ++k) b2[k] = 0;
      for (long long j = 0; j < 100; ++j) {
        for (long long k = 0; k < 100; ++k) {
          tmp2 = (j * pr10(tmp) + k) % md;
          b2[tmp2] += (b[j] * pwr[i][k]) % mod;
          b2[tmp2] %= mod;
        }
      }
      for (long long k = 0; k < 100; ++k) {
        b[k] = b2[k];
      }
    }
  }
  cout << b[kk] << endl;
  return 0;
}
