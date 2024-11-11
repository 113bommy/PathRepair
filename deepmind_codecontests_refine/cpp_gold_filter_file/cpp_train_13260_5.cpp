#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
#pragma hdrstop
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
inline void swap(short& a, short& b) { b ^= a ^= b ^= a; }
inline void swap(int& a, int& b) { b ^= a ^= b ^= a; }
inline void swap(char& a, char& b) { b ^= a ^= b ^= a; }
inline void swap(long long& a, long long& b) { b ^= a ^= b ^= a; }
template <class T>
inline T abs(T x) {
  return x < 0 ? -x : x;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T min(T& a, T& b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T& a, T& b) {
  return a > b ? a : b;
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
  return a / gcd(a, b) * b;
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
template <class T>
inline T ppow(T a, long long b) {
  T ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    b >>= 1;
  }
  return ret;
}
template <class T>
inline T ppow(T a, long long b, long long md) {
  T ret = 1;
  a %= md;
  while (b) {
    if (b & 1) ret = ret * a % md;
    a = a * a % md;
    b >>= 1;
  }
  return ret % md;
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
inline int Random() { return ((rand() << 16) | rand()); }
inline int Random(int l, int r) {
  if (l == r) return l;
  return Random() % (r - l) + l;
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
int __;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
const int MD = 1000000007;
int ls, ans, cx, cy;
char s[1111111];
int main() {
  sIO();
  gets(s);
  ls = strlen(s);
  ans = cx = 1;
  while (cx < ls) {
    cy = cx;
    while (s[cy] == s[cx]) ++cy;
    if (s[cx] == '1' || cy < ls) ++ans;
    cx = cy + 1;
  }
  printf("%d", ans);
  return 0;
}
