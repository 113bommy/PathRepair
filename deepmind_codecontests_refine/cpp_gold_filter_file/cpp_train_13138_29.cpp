#include <bits/stdc++.h>
using namespace std;
long long mod1 = 1e9 + 7;
long long mod2 = 998244353;
long long mul(long long x, long long y) {
  return (1ll * (x % mod1) * (y % mod1));
}
long long power(long long x, long long y) {
  long long z = 1;
  while (y > 0) {
    if (y % 2) z = mul(z, x);
    x = mul(x, x);
    y /= 2;
  }
  return z;
}
long long gcd(long long a, long long b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long pref[(long long)1e7];
string sol(const string& s) {
  string a = s;
  long long c = 0;
  for (int i = 1; i < (int)a.size(); i++) {
    while (c != 0 && a[c] != a[i]) c = pref[c - 1];
    if (a[c] == a[i]) c++;
    pref[i] = c;
  }
  return s.substr(0, c);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string t = sol(s);
  long long n = s.size(), m = t.size();
  long long f = 1;
  if (m == 0) {
    cout << "Just a legend" << endl;
  } else {
    for (long long i = 1; i < n - 1; i++) {
      if (pref[i] == m) {
        f = 0;
        cout << t << endl;
        break;
      }
    }
    string st = s.substr(0, pref[m - 1]);
    if (f) {
      if (st.size() == 0 || m == 0) {
        cout << "Just a legend" << endl;
      } else {
        cout << st << endl;
      }
    }
  }
}
