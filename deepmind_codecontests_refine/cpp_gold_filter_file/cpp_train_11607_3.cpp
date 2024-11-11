#include <bits/stdc++.h>
using namespace std;
long long mod = (long long)1 << 62;
long long QPow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans % mod * a % mod;
    a = a % mod * a % mod;
    b >>= 1;
  }
  return ans;
}
long long inf = (long long)1 << 60;
double eps = 1e-8;
long long fac[22];
long long fac_1[22];
long long inv[22];
void getInv() {
  inv[1] = 1;
  for (int i = 2; i <= 200001; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
void init1() {
  fac[0] = 1;
  fac_1[0] = 1;
  fac_1[1] = 1;
  for (int i = 1; i <= 200001; i++)
    fac[i] = fac[i - 1] * i % mod, fac_1[i] = inv[i] * fac_1[i - 1] % mod;
}
long long C(int n, int m) {
  if (m < 0 || m > n || n < 0) return 0;
  return fac[n] * fac_1[n - m] % mod * fac_1[m] % mod;
}
long long gcd(long long x, long long y) {
  if (x == 1 || y == 1)
    return 1;
  else {
    if (x == 0) return y;
    if (y == 0) return x;
    if (x % y == 0) return y;
    if (y % x == 0) return x;
    if (x > y)
      return gcd(x % y, y);
    else
      return gcd(x, y % x);
  }
}
int sign(long long x) {
  if (x == 0) return 0;
  if (x > 0) return 1;
  return -1;
}
long long toInt(string str) {
  long long ans = 0;
  for (int i = (str[0] == '-'); i < str.size(); i++) {
    ans *= 10;
    ans += str[i] - '0';
  }
  if (str[0] == '-') ans = -ans;
  return ans;
}
string toString(long long a) {
  if (a == 0) return "0";
  string temp = "";
  if (a < 0) temp.push_back('-');
  long long tp = a;
  while (tp) {
    temp.push_back('0' + tp % 10);
    tp /= 10;
  }
  string temp2 = temp;
  for (int ii = 0; ii < temp.size(); ii++) {
    temp[ii] = temp2[temp.size() - 1 - ii];
  }
  return temp;
}
const int maxn = 105;
bool equ(string s, string t) {
  if (s.size() == 1) return s[0] == t[0];
  bool flag = 1;
  for (int i = 0; i < s.size(); i++)
    if (s[i] != t[i]) {
      flag = 0;
      break;
    }
  if (flag) return 1;
  if (s.size() % 2 != 0) return 0;
  string s1, s2, t1, t2;
  string t3, t4;
  int slen = s.size(), tlen = t.size();
  for (int i = 0; i < slen / 2; i++) s1.push_back(s[i]);
  for (int i = slen / 2; i < slen; i++) s2.push_back(s[i]);
  for (int i = 0; i < tlen / 2; i++) t1.push_back(t[i]);
  for (int i = tlen / 2; i < tlen; i++) t2.push_back(t[i]);
  for (int i = 0; i < tlen / 2; i++) t3.push_back(t[tlen - 1 - i]);
  for (int i = tlen / 2; i < tlen; i++) t4.push_back(t[tlen - 1 - i]);
  flag |= equ(s1, t1) && equ(s2, t2);
  flag |= equ(s1, t3) && equ(s2, t4);
  return flag;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream in("Text.txt");
  long long n, x, t, m, k, d, L;
  long long xp, yp, xv, yv;
  cin >> xp >> yp >> xv >> yv;
  bool win = 1;
  if (xp >= xv && yp >= yv) {
    win = 0;
  } else if (xp <= xv && yp <= yv)
    win = 1;
  else if (xv < yv) {
    if (yp > yv)
      win = 0;
    else
      win = xp <= yv - yp;
  } else if (xv > yv) {
    if (yp < yv)
      win = 0;
    else
      win = yp <= xv - xp;
  } else
    win = 0;
  if (win)
    cout << "Polycarp";
  else
    cout << "Vasiliy";
  return 0;
}
