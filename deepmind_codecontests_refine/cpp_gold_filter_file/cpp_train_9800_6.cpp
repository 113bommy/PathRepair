#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long const mod1 = 998244353;
long long const mod = 1000000007;
long long toint(const string &s) {
  stringstream ss;
  ss << s;
  long long x;
  ss >> x;
  return x;
}
string tostring(long long number) {
  stringstream ss;
  ss << number;
  return ss.str();
}
long long modexp(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n & 1) {
    return (modexp((x * x) % mod, n / 2) % mod * x % mod) % mod;
  } else {
    return (modexp((x * x) % mod, n / 2) % mod);
  }
}
long long modinv(long long n) { return modexp(n, mod - 2); }
long long query(long long x, long long y) {
  cout << "?"
       << " " << x << " " << y << endl;
  char a;
  cin >> a;
  if (a == 'x')
    return 1;
  else
    return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (1) {
    string s;
    cin >> s;
    if (s == "start") {
      long long x = 0;
      long long y = 1;
      long long l, r;
      while (query(x, y) != 1) {
        x = y;
        y *= 2;
      }
      l = x;
      r = y;
      while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (query(l, m) == 1) {
          r = m;
        } else
          l = m;
      }
      cout << "!"
           << " " << r << endl;
    } else if (s == "mistake") {
      break;
    } else
      break;
  }
}
