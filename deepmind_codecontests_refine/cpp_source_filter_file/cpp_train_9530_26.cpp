#include <bits/stdc++.h>
const long long mod = 9973;
const int inf = 0x7ffffff;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long extgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else
    x = 1, y = 0;
  return d;
}
long long mod_reverse(long long a, long long n) {
  long long x, y;
  long long d = extgcd(a, n, x, y);
  if (d == 1)
    return (x % n + n) % n;
  else
    return -1;
}
long long inv(long long a, long long m) { return powmod(a, m - 2); }
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int flag = 0;
    for (int i = 0; i < 3; i++) {
      string a, b, c;
      cin >> a >> b >> c;
      if (b[0] != '-' && c[0] != '-') {
        int n1 = 0, n2 = 0;
        for (int i = 0; i < b.size(); i++) n1 = n1 * 10 + b[i] - '0';
        for (int i = 0; i < c.size(); i++) n2 = n2 * 10 + c[i] - '0';
        if (n1 >= 2400 && n2 >= 2400 && n2 > n1) flag = 1;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
