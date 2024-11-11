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
int n, m[4][4], a[222], ans, hw[222], tmp, bc, beg[222], st, d[222], v, tt, to,
    cw[222], len, cur;
vector<int> g[222];
bool w[222], can[222];
int main() {
  sIO();
  memset(m, 0, sizeof(m));
  m[1][2] = 1;
  m[1][3] = 2;
  m[2][1] = 2;
  m[2][3] = 1;
  m[3][1] = 1;
  m[3][2] = 2;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  ans = INF;
  memset(hw, 0, sizeof(hw));
  bc = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", hw + i);
    for (int j = 0; j < hw[i]; ++j) {
      scanf("%d", &tmp);
      g[tmp].push_back(i);
    }
    if (!hw[i]) beg[bc++] = i;
  }
  for (int k = 0; k < bc; ++k) {
    st = beg[k];
    memset(w, 0, sizeof(w));
    memset(can, 0, sizeof(can));
    for (int i = 0; i < bc; ++i) can[beg[i]] = true;
    for (int i = 1; i <= n; ++i) cw[i] = hw[i];
    memset(d, INF, sizeof(d));
    d[st] = 0;
    for (int _ = 0; _ < n; ++_) {
      v = 0;
      for (int i = 1; i <= n; ++i)
        if (!w[i] && can[i] && d[i] < d[v]) v = i;
      w[v] = true;
      tt = (int)g[v].size();
      for (int i = 0; i < tt; ++i) {
        to = g[v][i];
        --cw[to];
        if (!cw[to]) can[to] = true;
      }
      for (int i = 1; i <= n; ++i)
        if (can[i]) {
          len = m[a[v]][a[i]];
          d[i] = min(d[i], d[v] + len);
        }
    }
    cur = 0;
    for (int i = 1; i <= n; ++i) cur = max(cur, d[i]);
    ans = min(ans, cur);
  }
  printf("%d", ans + n);
  return 0;
}
