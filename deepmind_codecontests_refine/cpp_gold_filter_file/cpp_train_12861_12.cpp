#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-11;
signed long long m;
signed long long chk(signed long long c, bool b) {
  signed long long res = 0;
  for (signed long long i = 2; i <= 1000000; i++) {
    signed long long k = c / i / i / i;
    if (k == 0) break;
    if (b) cout << i << ' ' << k << endl;
    res += k;
  }
  return res;
}
int main() {
  cin >> m;
  signed long long M, L = 0, R = 1000000000ll * 1000000000;
  while (R - L > 100) {
    M = (L + R) / 2;
    if (chk(M, 0) > m)
      R = M - 1;
    else
      L = M;
  }
  for (signed long long i = max(0ll, L - 100); i < R; i++)
    if (chk(i, 0) == m) {
      cout << i << endl;
      return 0;
    }
  cout << -1 << endl;
  return 0;
}
