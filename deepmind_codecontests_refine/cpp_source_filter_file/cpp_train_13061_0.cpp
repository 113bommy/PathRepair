#include <bits/stdc++.h>
using namespace std;
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
inline T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
inline T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
long long Bigmod(long long base, long long power, long long MOD) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream second(s);
  second >> sm;
  return sm;
}
string Dekhi(string s) {
  string ans = s;
  for (int i = 1; i <= 9; i++) {
    string a;
    for (int j = 0; j < s.size(); j++) {
      int tp = ((int)(s[j] - '0') + i) % 10;
      a += (tp + '0');
    }
    ans = min(ans, a);
  }
  return ans;
}
string Rot(string s) {
  string a;
  for (int i = 1; i < s.size(); i++) a += s[i];
  a += s[0];
  return a;
}
int main() {
  int n;
  string s;
  cin >> n >> s;
  string ans = s;
  for (int i = 0; i < n - 1; i++) {
    ans = min(ans, Dekhi(s));
    s = Rot(s);
  }
  cout << ans << endl;
  return 0;
}
