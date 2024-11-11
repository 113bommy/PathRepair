#include <bits/stdc++.h>
const int Inf = 2 * 1000 * 1000 * 1000;
long long LINF = (long long)4e18;
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
const int mod = 998244353;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0)
    if (b & 1) {
      res = (long long)(res * 1ll * a) % mod;
      --b;
    } else {
      a = (long long)(a * 1ll * a) % mod;
      b >>= 1;
    }
  return (long long)res % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  string sss = "CODEFORCES";
  int r = (int)s.size() - 10;
  if (sss.size() > s.size()) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i <= 10; i++) {
    bool gg = true;
    for (int j = 0; j < i; j++) {
      if (sss[j] != s[j]) {
        gg = false;
        break;
      }
    }
    for (int j = r, k = 0; j < s.size(); j++, k++) {
      if (sss[k + i] != s[j]) {
        gg = false;
        break;
      }
    }
    r++;
    if (gg) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
