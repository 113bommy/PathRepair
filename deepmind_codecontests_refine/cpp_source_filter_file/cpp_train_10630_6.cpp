#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const double eps = 1e-6;
inline long long pow(long long a, long long b, long long p) {
  long long rtn = 1;
  while (b) {
    if (b & 1) rtn = rtn * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return rtn;
}
long long inv(long long a, long long p) { return pow(a, p - 2, p); }
long long gcd(long long a, long long b) {
  long long k;
  while (b != 0) {
    k = b;
    b = a % b;
    a = k;
  }
  return a;
}
void makedata() {
  freopen("input.txt", "w", stdout);
  srand((unsigned)time(NULL));
  fclose(stdout);
}
long long n, m, a, b[220000];
const long long mod = 998244353;
int main() {
  std::ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> a;
  for (int i = (1); i <= (m); i++) cin >> b[i];
  bool pr = n & 1;
  n /= 2;
  long long ans = pow(a, 2 * (n - b[m]), mod);
  for (int i = (m); i >= (2); i--) b[i] -= b[i - 1];
  for (int i = (1); i <= (m); i++) {
    long long kol = pow(a, b[i]);
    kol = (((kol) * ((kol + 1) % mod)) % (mod) + mod) % mod;
    if (kol & 1)
      kol = (kol + mod) / 2;
    else
      kol /= 2;
    ans = (((ans) * ((kol) % mod)) % (mod) + mod) % mod;
  }
  if (pr) ans = (((ans) * ((a) % mod)) % (mod) + mod) % mod;
  cout << (ans) << endl;
  return 0;
}
