#include <bits/stdc++.h>
using namespace std;
long long int intik(string m) {
  long long int a, s, z;
  s = 0;
  z = 1;
  for (long long int i = m.length() - 1; i >= 0; i--) {
    a = (m[i] - '0') * z;
    s = s + a;
    z *= 10;
  }
  return s;
}
string SofH(long long int a) {
  string s;
  long long int o;
  char e;
  bool n;
  n = false;
  if (a < 0) n = true;
  a = abs(a);
  while (a != 0) {
    o = a % 10;
    e = o + '0';
    string _e(1, e);
    s.insert(0, _e);
    a = a / 10;
  }
  if (n == true) {
    e = '-';
    string _e(1, e);
    s.insert(0, _e);
  }
  return s;
}
int main() {
  long long int n, p;
  cin >> n >> p;
  long long int k = 0;
  long long int n1 = 1, n2 = 9;
  long long int ans = 0;
  while (k != n) {
    for (long long int i = n1; i <= n2; i++) {
      string s = SofH(i);
      string scopy = s;
      reverse(scopy.begin(), scopy.end());
      s += scopy;
      long long int a = intik(s);
      a %= p;
      ans += a;
      ans %= p;
      k++;
      if (k == n) break;
    }
    n1 *= 10;
    n2 = n2 * 10 + 9;
  }
  cout << ans;
  return 0;
}
