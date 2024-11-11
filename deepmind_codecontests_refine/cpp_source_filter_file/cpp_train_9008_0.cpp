#include <bits/stdc++.h>
using namespace std;
template <class T>
T __sqr(const T x) {
  return x * x;
}
template <class T, class X>
inline T __pow(T a, X y) {
  T z = 1;
  for (int i = 1; i <= y; i++) {
    z *= a;
  }
  return z;
}
template <class T>
inline T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (!b) return a;
  return __gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / __gcd(a, b)) * b;
}
inline bool ispow2(int x) { return (x != 0 && (x & (x - 1)) == 0); }
template <class T>
void UpdateMin(T &x, T y) {
  if (y < x) {
    x = y;
  }
}
template <class T>
void UpdateMax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <class T, class X, class Y>
inline T bigmod(T n, X m, Y mod) {
  unsigned long long ret = 1, a = n % mod;
  while (m) {
    if (m & 1) ret = (ret * a) % mod;
    m >>= 1;
    a = (a * a) % mod;
  }
  ret %= mod;
  return (T)ret;
}
template <class T, class Y>
inline T modinv(T n, Y mod) {
  return bigmod(n, mod - 2, mod);
}
template <class T, class X>
int getbit(T s, X i) {
  return (s >> i) & 1;
}
template <class T, class X>
T onbit(T s, X i) {
  return s | (T(1) << i);
}
template <class T, class X>
T offbit(T s, X i) {
  return s & (~(T(1) << i));
}
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
void extended_euclid(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  long long first, second;
  extended_euclid(b, a % b, first, second);
  x = second;
  y = first - (a / b) * second;
}
pair<long long, pair<long long, long long> > extendedEuclid(long long a,
                                                            long long b) {
  long long x = 1, y = 0;
  long long xLast = 0, yLast = 1;
  long long q, r, m, n;
  while (a != 0) {
    q = b / a;
    r = b % a;
    m = xLast - q * x;
    n = yLast - q * y;
    xLast = x, yLast = y;
    x = m, y = n;
    b = a, a = r;
  }
  return make_pair(b, make_pair(xLast, yLast));
}
const long long mod[] = {0,          1000000007, 1000000009,
                         1000000021, 1000000033, 1000000097,
                         1000000093, 1000000097, 1000000103};
const long long base[] = {0,       1000003, 1000033, 1000037, 1000039,
                          1000081, 1000099, 1000117, 1000121};
vector<int> G[(500000 + 20)];
double tot[(500000 + 20)];
void dfs(int x) {
  tot[x] = tot[x] + 1.0;
  for (int i = 0; i < ((int)G[x].size()); i++) {
    dfs(G[x][i]);
    tot[x] += tot[G[x][i]];
  }
}
double ex[(500000 + 20)], a[(500000 + 20)];
void calc(int x) {
  if (G[x].size() == 1) {
    ex[G[x][0]] = ex[x] + 1.0;
    dfs(G[x][0]);
    return;
  }
  double sum = 0, sub = G[x].size() - 1;
  for (int i = 0; i < ((int)G[x].size()); i++) {
    double u = tot[G[x][i]];
    a[i] = u;
    sum += a[i];
  }
  for (int i = 0; i < ((int)G[x].size()); i++) {
    int u = G[x][i];
    ex[u] = ex[x] + (sum - a[i]) / 2.0 + 1;
  }
  for (int i = 0; i < ((int)G[x].size()); i++) {
    calc(G[x][i]);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  ex[1] = 0;
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    G[x].push_back(i);
    ex[i] = 0;
  }
  dfs(1);
  ex[1] = 1;
  calc(1);
  for (int i = 1; i <= n; i++) {
    printf("%.12lf ", ex[i]);
  }
  puts("");
  return 0;
}
