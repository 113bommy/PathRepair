#include <bits/stdc++.h>
using namespace std;
struct In {
  inline In operator>>(int &p) const {
    int re = 0;
    register int n = 0, sign = 1, a = getchar();
    while (a < '0' || a > '9') {
      if (a == '-') {
        sign = -1;
        a = getchar();
        break;
      }
      a = getchar();
    }
    while (a >= '0' && a <= '9') {
      n = (n << 1) + (n << 3) + a - '0';
      a = getchar();
    }
    p = n * sign;
    return *this;
  }
  inline In operator>>(double &x) const {
    scanf("%lf", &x);
    return *this;
  }
  inline In operator>>(char &x) const {
    do {
      x = getchar();
    } while (x == ' ' || x == '\n');
    return *this;
  }
  inline In operator>>(char *x) const {
    scanf("%s", x);
    return *this;
  }
  inline In operator>>(string &s) const { return *this; }
} I;
struct Out {
  inline Out operator<<(const int x) const {
    printf("%d", x);
    return *this;
  }
  inline Out operator<<(const double x) const {
    printf("%lf", x);
    return *this;
  }
  inline Out operator<<(const char x) const {
    putchar(x);
    return *this;
  }
  inline Out operator<<(const char *x) const {
    printf("%s", x);
    return *this;
  }
  inline Out operator<<(const string x) const { return operator<<(x.c_str()); }
} O;
inline int pw2(int a, int b) {
  int res = 1;
  while (b--) res *= a;
  return res;
}
inline bool asc(int a, int b) { return (a > b); }
inline int Max(vector<int> a, int mx = -1e9) {
  if (a.empty()) return mx;
  mx = ((mx > a.back()) ? mx : a.back());
  a.pop_back();
  return Max(a, mx);
}
inline int Min(vector<int> a, int mn = 1e9) {
  if (a.empty()) return mn;
  mn = ((mn < a.back()) ? mn : a.back());
  a.pop_back();
  return Min(a, mn);
}
inline int pw(int a, int n, int K = 1e9 + 7) {
  return (n ? (pw((a * a) % K, n / 2ll, K) * (n & 1ll ? a : 1ll)) % K : 1ll);
}
inline int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
inline int lowbit(int m) { return m & (-m); }
inline int getbit(int x, int b) { return (x >> b) & 1; }
inline long long getbit(long long x, int b) { return (x >> b) & 1; }
inline unsigned long long getbit(unsigned long long x, int b) {
  return (x >> b) & 1;
}
inline int setbit(int x, int b) { return x | (1 << b); }
inline void _setbit(int &x, int b) { x = setbit(x, b); }
inline long long setbit(long long x, int b) { return x | (1ll << b); }
inline void _setbit(long long &x, int b) { x = setbit(x, b); }
inline int unsetbit(int x, int b) { return x & (INT_MAX - (1 << b)); }
inline void _unsetbit(int &x, int b) { x = unsetbit(x, b); }
inline int countbit(int x) {
  x = x - ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
inline long long countbit(long long x) {
  int p1 = (x >> 32) & ((1ll << 32) - 1);
  int p2 = x & ((1ll << 32) - 1);
  return countbit(p1) + countbit(p2);
}
template <typename T>
string stringbit(T x, int len) {
  string res = "";
  for (int i = len - 1; i >= 0; i--) res.push_back(getbit(x, i) + '0');
  return res;
}
long long a, d, c;
bool is_integer(double k) { return floor(k) == k; }
int main() {
  cin >> a >> c >> d;
  if (d == 0)
    if (a == c)
      return cout << "YES", 0;
    else
      return cout << "NO", 0;
  if (is_integer((c - a + d) / (double)d) && ((c - a + d) / (double)d) >= 1)
    return cout << "YES", 0;
  else
    return cout << "NO", 0;
}
