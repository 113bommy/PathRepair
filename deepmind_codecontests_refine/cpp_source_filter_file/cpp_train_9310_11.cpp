#include <bits/stdc++.h>
using namespace std;
inline long long int gcd(long long int x, long long int y) {
  return x % y == 0 ? y : gcd(y, x % y);
}
inline long long int lcm(long long int x, long long int y) {
  return x * (y / gcd(x, y));
}
inline long long int powmod(long long int a, long long int b,
                            long long int mod) {
  long long int res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
inline long long int mulmod(long long int a, long long int b, long long int c) {
  if (!b) return 0;
  long long int x = mulmod(a, b / 2, c);
  if (b & 1) return (x + x + a) % c;
  return (x + x) % c;
}
int main() {
  string s, newstr;
  cin >> s;
  int n = s.length();
  if (s.substr(0, 3) == "dot") {
    newstr += "dot";
    s = s.substr(3, n - 3);
  }
  if (s.substr(0, 2) == "at") {
    newstr += "at";
    s = s.substr(2, n - 2);
  }
  n = s.length();
  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (i + 2 < n && s.substr(i, 3) == "dot") {
      newstr += ".";
      i += 2;
    } else if (flag == 0 && i + 1 < n && s.substr(i, 2) == "at") {
      flag = 1;
      newstr += "@";
      i++;
    } else {
      newstr += s[i];
    }
  }
  if (flag == 0 && newstr[newstr.length() - 1] == '@') {
    newstr[newstr.length() - 1] = 'a';
    newstr += "t";
  }
  if (newstr[newstr.length() - 1] == '.') {
    newstr[newstr.length() - 1] = 'd';
    newstr += "ot";
  }
  cout << newstr << endl;
  return 0;
}
