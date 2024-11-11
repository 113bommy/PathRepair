#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
inline void sIO() {}
inline void iIO() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
inline void fIO(string fn) {
  freopen((fn + ".in").c_str(), "r", stdin);
  freopen((fn + ".out").c_str(), "w", stdout);
}
inline void TM() {}
template <class T>
inline T abs(T x) {
  return x < 0 ? -x : x;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T gcd(T a, T b) {
  if (a < b) swap(a, b);
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <class T>
inline T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
template <class T>
inline bool isPrime(T n) {
  if (n < 2) return false;
  T kk = (T)sqrt(n + 0.);
  for (T i = 2; i <= kk; ++i)
    if (!(n % i)) return false;
  return true;
}
template <class T>
inline string toa(T x) {
  stringstream ss;
  ss << x;
  string ret;
  ss >> ret;
  return ret;
}
inline int toi(string s) {
  stringstream ss;
  ss << s;
  int ret;
  ss >> ret;
  return ret;
}
inline long long tol(string s) {
  stringstream ss;
  ss << s;
  long long ret;
  ss >> ret;
  return ret;
}
inline char upperCase(char ch) {
  return (ch >= 'a' && ch <= 'z') ? ch ^ 32 : ch;
}
inline char lowerCase(char ch) {
  return (ch >= 'A' && ch <= 'Z') ? ch ^ 32 : ch;
}
inline string upperCase(string s) {
  int ls = s.length();
  for (int i = 0; i < ls; ++i)
    if (s[i] >= 'a' && s[i] <= 'z') s[i] ^= 32;
  return s;
}
inline string lowerCase(string s) {
  int ls = s.length();
  for (int i = 0; i < ls; ++i)
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] ^= 32;
  return s;
}
inline int dig(char ch) { return ch - 48; }
inline bool isAlpha(char ch) {
  return (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z');
}
inline bool isDigit(char ch) { return (ch >= '0' && ch <= '9'); }
inline bool isLowerCase(char ch) { return (ch >= 'a' && ch <= 'z'); }
inline bool isUpperCase(char ch) { return (ch >= 'A' && ch <= 'Z'); }
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
const int MD = 1000000007;
int x1, kdhaskjdhaskdhakjdhakjhd, r1, x2, y2, r2;
double d;
int main() {
  sIO();
  scanf("%d%d%d%d%d%d", &x1, &kdhaskjdhaskdhakjdhakjhd, &r1, &x2, &y2, &r2);
  if (r1 < r2) {
    swap(x1, x2);
    swap(kdhaskjdhaskdhakjdhakjhd, y2);
    swap(r1, r2);
  }
  d = sqrt(sqr(x1 - x2) + sqr(kdhaskjdhaskdhakjdhakjhd - y2) + 0.);
  if (r1 > r2 + d + EPS)
    printf("%.16f", r1 - r2 - d);
  else if (r1 + r2 > d + EPS)
    printf("0.00000000000000");
  else
    printf("%.16f", (d - r1 - r2) / 2);
  return 0;
}
