#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
long long PowMod(long long a, long long b, const long long &Mod) {
  a %= Mod;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return ans;
}
long long Inv(long long a, long long n) { return PowMod(a, n - 2, n); }
long long k, a, b;
int main() {
  ios::sync_with_stdio(false);
  bool f = 1;
  cin >> k;
  b = 1;
  while (k--) {
    cin >> a;
    b = b * PowMod(2, a, Mod) % Mod;
    if (f && a % 2 == 0) f = 0;
  }
  b = b * Inv(2, Mod) % Mod;
  a = (b + (f ? -1 : 1)) * Inv(3, Mod) % Mod;
  cout << a << '/' << b << endl;
  return 0;
}
