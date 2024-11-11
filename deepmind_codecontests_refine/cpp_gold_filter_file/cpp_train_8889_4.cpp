#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 9;
int pow_mod(int a, int n, int m = mod) {
  if (!n) return 1 % m;
  int x = pow_mod(a, n / 2, m);
  long long ans = (long long)x * x % m;
  if (n & 1) ans = ans * a % m;
  return (int)ans;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if ((n - m) * k - n > 0) {
    cout << m << endl;
    return 0;
  }
  long long x = n - (n - m) * k;
  long long ans = (pow_mod(2, x / k + 1) - 2 + mod) % mod * k % mod;
  ans = (ans + x % k) % mod;
  ans = (ans + (n - m) * (k - 1)) % mod;
  cout << ans << endl;
  return 0;
}
