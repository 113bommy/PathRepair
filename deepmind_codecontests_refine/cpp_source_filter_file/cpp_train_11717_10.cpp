#include <bits/stdc++.h>
using namespace std;
inline bool SR(int &x) { return scanf("%d", &x) == 1; }
inline bool SR(long long &x) { return scanf("%lld", &x) == 1; }
inline bool SR(double &x) { return scanf("%lf", &x) == 1; }
inline bool SR(char *s) { return scanf("%s", s) == 1; }
inline bool RI() { return true; }
template <typename I, typename... T>
inline bool RI(I &x, T &...tail) {
  return SR(x) && RI(tail...);
}
inline void SP(const int x) { printf("%d", x); }
inline void SP(const long long x) { printf("%lld", x); }
inline void SP(const double x) { printf("%.16lf", x); }
inline void SP(const char *s) { printf("%s", s); }
inline void PL() { puts(""); }
template <typename I, typename... T>
inline void PL(const I x, const T... tail) {
  SP(x);
  if (sizeof...(tail)) putchar(' ');
  PL(tail...);
}
template <typename I>
void _DOING(const char *s, I &&x) {
  cerr << s << " = " << x << endl;
}
template <typename I, typename... T>
void _DOING(const char *s, I &&x, T &&...tail) {
  int c = 0;
  while (*s != ',' || c != 0) {
    if (*s == '(' || *s == '[' || *s == '{') c++;
    if (*s == ')' || *s == ']' || *s == '}') c--;
    cerr << *s++;
  }
  cerr << " = " << x << " , ";
  _DOING(s + 1, tail...);
}
inline int RAND() {
  static int x = 880301;
  return (x = x * 0xdefaced + 1) & 0x7fffffff;
}
const int MAX_N = 100000 + 10;
const long long MOD = 1000000000 + 7;
long long a[MAX_N];
inline long long power_mod(long long a, long long n, long long m) {
  long long res = 1;
  a %= m;
  while (n) {
    if (n & 1) res = res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}
inline long long inv(long long a, long long m) {
  return power_mod(a, m - 2, m);
}
int main() {
  int n;
  RI(n);
  int n_mod_2 = 0;
  long long mul = 1;
  for (int i = 0; i < int(n); i++) {
    RI(a[i]);
    if (a[i] & 1) n_mod_2 ^= 1;
    mul = mul * (a[i] % (MOD - 1)) % (MOD - 1);
  }
  long long p, q = power_mod(2, (mul + MOD - 2) % (MOD - 1), MOD);
  if (n_mod_2)
    p = (q + MOD - 1) % MOD * inv(3, MOD) % MOD;
  else
    p = (q + 1) % MOD * inv(3, MOD) % MOD;
  printf("%lld/%lld\n", p, q);
  return 0;
}
