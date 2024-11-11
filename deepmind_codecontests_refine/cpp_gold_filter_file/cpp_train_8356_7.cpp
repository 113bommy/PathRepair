#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long MOD = 998244353;
const long long inf = 1e18;
const long long MAX = 2e5 + 1;
inline long long add(long long a, long long b) {
  return ((a % mod) + (b % mod)) % mod;
}
inline long long sub(long long a, long long b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
inline long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
vector<long long> fac(1e6);
long long pwr(long long x, long long n) {
  x = x % mod;
  if (!n) return 1;
  if (n & 1)
    return mul(x, pwr(mul(x, x), (n - 1) / 2));
  else
    return pwr(mul(x, x), n / 2);
}
long long modinv(long long n) { return pwr(n, mod - 2); }
long long inv(long long i) {
  if (i == 1) return 1;
  return (MOD - (MOD / i) * inv(MOD % i) % MOD) % MOD;
}
long long ncr(long long n, long long r) {
  long long ans = 1;
  if (r != 0 && r != n) {
    ans = fac[n] * modinv(fac[r]) % MOD * modinv(fac[n - r]) % MOD;
  }
  return ans;
}
void pre() {
  fac[0] = 1;
  for (int i = 1; i < (int)fac.size(); i++) {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
}
void solve() {
  long long n, k;
  cin >> n;
  int a, b, c;
  a = n - 3;
  b = n - 5;
  c = n - 7;
  int c3 = 0, c5 = 0, c7 = 0;
  int ar[3] = {3, 5, 7};
  for (int i = 0; i < 3; i++) {
    if (a >= 0 && ((a % ar[i]) == 0)) {
      c3++;
      if (ar[i] == 3)
        c3 += a / 3;
      else if (ar[i] == 5)
        c5 += a / 5;
      else if (ar[i] == 7)
        c7 += a / 7;
      cout << c3 << " " << c5 << " " << c7 << endl;
      return;
    }
    if (b >= 0 && ((b % ar[i]) == 0)) {
      c5++;
      if (ar[i] == 3)
        c3 += b / 3;
      else if (ar[i] == 5)
        c5 += b / 5;
      else if (ar[i] == 7)
        c7 += b / 7;
      cout << c3 << " " << c5 << " " << c7 << endl;
      return;
    }
    if (c >= 0 && ((c % ar[i]) == 0)) {
      c7++;
      if (ar[i] == 3)
        c3 += c / 3;
      else if (ar[i] == 5)
        c5 += c / 5;
      else if (ar[i] == 7)
        c7 += c / 7;
      cout << c3 << " " << c5 << " " << c7 << endl;
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
