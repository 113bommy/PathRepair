#include <bits/stdc++.h>
using namespace std;
const long long N = 1000010, M = 998244353;
long long inv[N];
int32_t main() {
  long long n;
  cin >> n;
  long long f = 1;
  inv[0] = inv[1] = 1;
  for (long long i = 2; i <= n; i++) {
    f *= i;
    f %= 998244353;
    inv[i] = (M - M / i) * inv[M % i] % M;
  }
  long long s = 0, cs = 1;
  for (long long i = 1; i < n; i++) {
    cs = cs * inv[i] % M;
    s += f * cs % M;
  }
  cout << (n * f % 998244353 - s % M + 998244353) % 998244353 << endl;
}
