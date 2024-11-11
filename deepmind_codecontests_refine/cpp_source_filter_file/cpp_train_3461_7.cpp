#include <bits/stdc++.h>
using namespace std;
long long po(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = (res * x) % 998244353;
    n = n / 2;
    x = (x * x) % 998244353;
  }
  return res;
}
long long fac[500000 + 1] = {0};
long long ifac[500000 + 1] = {0};
void pre() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= 500000; i++) {
    fac[i] = (i * fac[i - 1]) % 998244353;
    ifac[i] = po(fac[i], 998244353 - 2);
  }
}
long long nCr(long long n, long long r) {
  if (r > n || r < 0 || n < 1) return 0;
  return (((fac[n] * ifac[r]) % 998244353) * ifac[n - r]) % 998244353;
}
void func() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  pre();
  for (int i = 1; i <= n; i++) {
    ans = (ans + nCr(n / i - 1, k - 1)) % 998244353;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) func();
}
