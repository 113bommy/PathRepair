#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 50;
const int inf = 0x3f3f3f3f;
const int M = 5000 * 4;
const int mod = 998244353;
long long fac[MAXN];
long long quick(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans % mod;
}
long long ccc(long long n, long long m) {
  return (fac[n] * quick(fac[m], mod - 2) % mod * quick(fac[n - m], mod - 2) %
          mod) %
         mod;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  fac[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  int n, m;
  cin >> n >> m;
  if (n == 2) {
    cout << 0 << endl;
    return 0;
  }
  cout << ccc(m, n - 1) * quick(2, n - 3) % mod * (n - 2) % mod << endl;
  return 0;
}
