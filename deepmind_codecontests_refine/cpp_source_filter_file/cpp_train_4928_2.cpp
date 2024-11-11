#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int LIM = 3e5 + 5;
const int MOD = 1e9 + 7;
const long double EPS = 1e-10;
const double PI = acos(-1.0);
double tick() {
  static clock_t oldt;
  clock_t newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
template <typename T>
void inpos(T &x) {
  x = 0;
  register T c = getchar();
  while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
  bool neg = false;
  if (c == '-') neg = true;
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
  if (neg) x = -x;
}
template <typename T>
void outpos(T n) {
  if (n < 0) {
    putchar('-');
    n *= -1;
  }
  char snum[65];
  int i = 0;
  do {
    snum[i++] = n % 10 + '0';
    n /= 10;
  } while (n);
  i = i - 1;
  while (i >= 0) putchar(snum[i--]);
  putchar('\n');
}
inline void instr(char *str) {
  register char c = 0;
  register int i = 0;
  while (c < 33) c = getchar();
  while (c != '\n' && c != ' ' && c != EOF) {
    str[i] = c;
    c = getchar();
    ++i;
  }
  str[i] = '\0';
}
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
template <typename T>
T mod(T a, T b) {
  return (a < b ? a : a % b);
}
template <typename T>
T add(T a, T b, T c) {
  T x = a + b;
  return (x >= c ? x - c : x);
}
template <typename T>
T mod_neg(T a, T b) {
  a = mod(a, b);
  if (a < 0) {
    a += b;
  }
  return a;
}
long long mulmod(long long a, long long b, long long m) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T expo(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T power(T e, T n, T m) {
  T x = 1 % m, p = e;
  while (n) {
    if (n & 1) x = mod(x * p, m);
    p = mod(p * p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    T q = a / b, t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
template <typename T>
T mod_inverse(T a, T n) {
  T x, y;
  T d = extended_euclid(a, n, x, y);
  return (d > 1 ? -1 : mod_neg(x, n));
}
int c[MAX];
int main() {
  int n, a, b;
  inpos(n), inpos(a), inpos(b);
  for (int i = 0; i < n; ++i) {
    inpos(c[i]);
  }
  sort(c, c + n);
  printf("%d\n", c[a + 1] - c[a]);
  return 0;
}
