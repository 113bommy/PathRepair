#include <bits/stdc++.h>
using namespace std;
namespace mine {
long long qread() {
  long long ans = 0, f = 1;
  char c = getchar();
  while (c < '0' or c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c and c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans * f;
}
void write(long long num) {
  if (num < 0) putchar('-'), num = -num;
  if (num >= 10) write(num / 10);
  putchar('0' + num % 10);
}
void write1(long long num) {
  write(num);
  putchar(' ');
}
void write2(long long num) {
  write(num);
  putchar('\n');
}
template <typename T>
inline bool chmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool chmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
bool IN(long long x, long long l, long long r) { return l <= x and x <= r; }
void GG() {
  puts("No");
  exit(0);
}
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int mm(const int x) { return x >= MOD ? x - MOD : x; }
template <typename T>
void add(T &x, const int &y) {
  x = (x + y >= MOD ? x + y - MOD : x + y);
}
long long qpower(long long x, long long e, int mod = MOD) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = ans * x % mod;
    x = x * x % mod;
    e >>= 1;
  }
  return ans;
}
long long invm(long long x) { return qpower(x, MOD - 2); }
const int MM = 1e6 + 10;
long long fac[MM], facinv[MM], Inv[MM];
long long C(int n, int m) {
  return n < 0 or m < 0 or n < m
             ? 0
             : fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}
int C_sm(int n, int m) {
  if (n < MOD and m < MOD) return C(n, m);
  return C(n / MOD, m / MOD) * C(n % MOD, m % MOD) % MOD;
}
void PRE() {
  fac[0] = 1;
  for (int i = (1), I = (MM - 1); i <= I; i++) fac[i] = fac[i - 1] * i % MOD;
  facinv[MM - 1] = invm(fac[MM - 1]);
  for (int i = (MM - 1), I = (1); i >= I; i--)
    facinv[i - 1] = facinv[i] * i % MOD;
  Inv[1] = 1;
  for (int i = (2), I = (MM - 1); i <= I; i++)
    Inv[i] = (MOD - MOD / i) * Inv[MOD % i] % MOD;
}
const int N = 1e5 + 10;
double dp[110][N], cc[110][110];
void main() {
  int n = qread(), X = qread(), sum = 0;
  cc[0][0] = 1;
  for (int i = (1), I = (n); i <= I; i++) {
    cc[i][0] = 1;
    for (int j = (1), I = (i); j <= I; j++)
      cc[i][j] = cc[i - 1][j - 1] + cc[i - 1][j];
  }
  dp[0][0] = 1;
  for (int tim = (1), I = (n); tim <= I; tim++) {
    int c = qread();
    for (int i = (tim), I = (0); i >= I; i--)
      for (int j = (0), I = (sum); j <= I; j++) dp[i + 1][j + c] += dp[i][j];
    sum += c;
  }
  double ans = 0;
  for (int k = (0), I = (n - 1); k <= I; k++)
    for (int s = (0), I = (sum); s <= I; s++)
      if (cc[n][k] > eps)
        ans += dp[n - k][s] / cc[n][k] *
               min(X / 2.0 * (1.0 * n / (n - k) + 1), s * 1.0 / (n - k));
  printf("%.10lf", ans);
}
};  // namespace mine
signed main() {
  mine::main();
  ;
}
