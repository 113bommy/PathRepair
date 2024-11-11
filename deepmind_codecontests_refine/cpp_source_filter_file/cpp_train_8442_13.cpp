#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
string s1, s2;
int a, b, c, d;
int binpow(int a, int b) {
  if (b == 0) return 1;
  if (b % 2) return a * 1ll * binpow(a, b - 1) % mod;
  int t = binpow(a, b / 2);
  return t * 1ll * t % mod;
}
string chng(string s) {
  for (int i = (int)s.size() - 1; i >= 0; i--) {
    if (s[i] == '1') {
      s[i] = 0;
      break;
    } else
      s[i] = '1';
  }
  if ((int)s.size() == 1) return s;
  if (s[0] == '0') s.erase(s.begin());
  return s;
}
int f[N], rev[N];
int C(int n, int k) {
  int answ = f[n] * 1ll * rev[k] % mod;
  answ = answ * 1ll * rev[n - k] % mod;
  return answ;
}
int cnt(int a, int b) {
  if (a == b && a == 0) return 1;
  if (a < 1 || a < b || a - 1 < a - b) return 0;
  return C(a - 1, a - b);
}
int calc(int c1, int c0, int one, int zero) {
  int A = cnt(c1, one);
  int B = cnt(c0, zero);
  return A * 1ll * B % mod;
}
int solve(string &s, int a, int b, int c, int d) {
  int sz = a + b + c + d + 1;
  if (s == "0") return 0;
  if ((int)s.size() < sz) return 0;
  int c1 = d + c;
  int c0 = a + b;
  if (b == c)
    c1++;
  else
    c0++;
  int all = b + c + 1;
  int zero = all / 2;
  int one = all - zero;
  if ((int)s.size() > sz) return calc(c1, c0, one, zero);
  vector<int> G;
  for (int i = 0; i < (int)s.size(); i++) {
    char x = s[i];
    int k = 0;
    while (i < (int)s.size() && s[i] == x) {
      ++i;
      ++k;
    }
    --i;
    G.push_back(k);
  }
  int answ = 0;
  for (int i = 0; i < (int)G.size(); i++) {
    if (i % 2 == 0) {
      for (int j = 1; j < G[i]; j++) {
        answ += calc(c1 - j, c0, one - 1, zero);
        answ %= mod;
      }
      c1 -= G[i];
      --one;
    } else {
      answ += calc(c1, c0 - G[i], one, zero);
      answ %= mod;
      c0 -= G[i];
      --zero;
    }
  }
  if (c0 == 0 && c1 == 0 && zero == 0 && one == 0) {
    answ++;
    answ %= mod;
  }
  return answ;
}
void precalc() {
  f[0] = rev[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    f[i] = f[i - 1] * 1ll * i % mod;
    rev[i] = binpow(f[i], mod - 2);
  }
}
int main() {
  precalc();
  cin >> s1 >> s2;
  s1 = chng(s1);
  cin >> a >> b >> c >> d;
  if (c - b != 0 && c - b != 1) {
    cout << 0 << endl;
    return 0;
  }
  int A = solve(s1, a, b, c, d);
  int B = solve(s2, a, b, c, d);
  cout << (B - A + mod) % mod << endl;
  return 0;
}
