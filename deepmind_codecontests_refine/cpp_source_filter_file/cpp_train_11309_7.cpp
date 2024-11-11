#include <bits/stdc++.h>
using namespace std;
const long long int Mod = 998244353;
const long long int mod = 1e9 + 7;
long long int Pow(long long int a, long long int b) {
  a = a % mod;
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return (res % mod);
}
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void solve() {
  int n, a, b;
  cin >> n;
  cin >> a;
  cin >> b;
  int itr = n / max(a, b);
  for (int i = 0; i <= itr; i++) {
    if ((n - (i * a)) % b == 0 && ((n - (i * a)) / b) >= 0) {
      cout << "YES"
           << "\n";
      cout << i << " " << ((n - (i * a)) / b);
      return;
    }
  }
  cout << "NO";
}
int main() {
  solve();
  return 0;
}
