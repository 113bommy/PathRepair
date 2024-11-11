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
void chmax(T &x, const T y) {
  x = (x > y ? x : y);
}
template <typename T>
void chmin(T &x, const T y) {
  x = (x < y ? x : y);
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
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
const int N = 2e3 + 10;
int F[N][N + N];
int g[N], h[N];
void main() {
  int n = qread(), k = qread();
  for (int i = (0), I = (n - 1); i <= I; i++)
    h[i] = g[(i + n - 1) % n] = qread();
  F[0][N + 0] = 1;
  for (int i = (0), I = (n - 1); i <= I; i++)
    for (int j = (-n), I = (n); j <= I; j++)
      if (F[i][N + j]) {
        if (h[i] == g[i])
          add(F[i + 1][N + j], F[i][N + j] * k % MOD);
        else
          add(F[i + 1][N + j - 1], F[i][N + j]),
              add(F[i + 1][N + j + 1], F[i][N + j]),
              add(F[i + 1][N + j], F[i][N + j] * (k - 2) % MOD);
      }
  long long ans = 0;
  for (int now = (1), I = (n); now <= I; now++) add(ans, F[n][N + now]);
  write(ans);
}
};  // namespace mine
signed main() {
  srand(time(0));
  mine::main();
}
