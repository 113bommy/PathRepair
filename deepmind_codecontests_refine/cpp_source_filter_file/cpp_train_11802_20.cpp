#include <bits/stdc++.h>
using namespace std;
long long m, l, r, k;
long long f(long long x) { return r / x - (l - 1) / x; }
long long fibo(long long p) {
  long long mt[2][2] = {1, 1, 0, 1};
  long long qm[2][2] = {1, 0, 0, 1};
  long long tm[2][2];
  for (long long e = p - 2; e > 0; e >>= 1) {
    if (e & 1) {
      memcpy(tm, qm, sizeof qm);
      memset(qm, 0, sizeof qm);
      for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k) qm[i][j] += tm[i][k] * mt[k][j];
          qm[i][j] %= m;
        }
    }
    memcpy(tm, mt, sizeof mt);
    memset(mt, 0, sizeof mt);
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) mt[i][j] += tm[i][k] * tm[k][j];
        mt[i][j] %= m;
      }
  }
  return qm[0][0] + qm[0][1];
}
int main() {
  cin >> m >> l >> r >> k;
  long long mx = -1;
  for (long long y = 1, my = sqrt(r) + 1; y <= my; ++y) {
    long long x = r / y;
    if (f(x) >= k)
      if (mx < x) mx = x;
  }
  for (long long x = 1, mxp = sqrt(r) + 1; x <= mxp; ++x) {
    if (f(x) >= k)
      if (mx < x) mx = x;
  }
  cout << fibo(mx) << endl;
  return 0;
}
