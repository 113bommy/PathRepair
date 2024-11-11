#include <bits/stdc++.h>
using namespace std;
namespace my_std {
const long long inf = 0x3f3f3f3f;
const long long inff = 1e15;
inline long long read() {
  long long sum = 0, f = 1;
  char ch = 0;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    sum = (sum << 1) + (sum << 3) + (ch ^ 48);
    ch = getchar();
  }
  return sum * f;
}
inline void write(long long x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
inline void writesp(long long x) {
  write(x);
  putchar(' ');
}
}  // namespace my_std
using namespace my_std;
const long long N = 1050;
long long n, d, mod, f[N][20][N], inv[20], mul[20];
inline long long ksmod(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
inline long long C(long long n, long long m, long long ans = 1) {
  if (m > n || m < 0 || n < 0) return 0;
  for (register long long i = (1); i <= (m); i++) ans = ans * (n - i + 1) % mod;
  ans = ans * inv[m] % mod;
  return ans;
}
inline void init() {
  mul[0] = inv[0] = 1;
  for (long long i = 1; i <= 10; i++) mul[i] = (mul[i - 1] * i) % mod;
  inv[10] = ksmod(mul[10], mod - 2);
  for (long long i = 10 - 1; i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
int main(void) {
  n = read(), d = read(), mod = read();
  if (n == 1 || n == 2) {
    puts("1");
    return 0;
  }
  init();
  for (register long long i = (0); i <= (n); i++) f[1][0][i] = 1;
  for (register long long i = (2); i <= (n); i++)
    for (long long j = 1; j < i && j <= d; j++)
      for (register long long k = (1); k <= (n); k++) {
        f[i][j][k] = f[i][j][k - 1];
        for (long long t = 1; t * k < i && t <= j; t++) {
          if (k != 1)
            f[i][j][k] =
                (f[i][j][k] + f[i - t * k][j - t][k - 1] *
                                  C(f[k][d - 1][k - 1] + t - 1, t) % mod) %
                mod;
          else
            f[i][j][k] = (f[i][j][k] + f[i - t * k][j - t][k - 1] *
                                           C(f[k][0][k - 1] + t - 1, t) % mod) %
                         mod;
        }
      }
  long long ans = f[n][d][n / 2];
  if (!(n & 1)) ans = (ans - C(f[n / 2][d - 1][n / 2], 2) + mod) % mod;
  writeln(ans);
  return 0;
}
