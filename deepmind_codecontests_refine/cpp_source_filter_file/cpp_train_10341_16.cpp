#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c;
  long long flag = 1;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') {
      flag = -1;
    }
  }
  long long count = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') {
    count *= 10;
    count += c - '0';
  }
  return count * flag;
}
inline void print(long long x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}
const long long N = 1e6 + 10;
const long long Mod = 1e9 + 7;
long long f[N];
long long g[N];
signed main() {
  long long n = read() / 2;
  f[0] = g[1] = 1;
  for (register long long i = 1; i <= n; i++) {
    f[i] = f[i - 1] * 2 % Mod;
  }
  for (register long long i = 2; i <= n; i++) {
    g[i] = g[i - 1] * (f[i] - 3) % Mod;
  }
  long long ans = 0;
  for (register long long i = 2; i <= n; i++) {
    ans += (4 * g[i]) % Mod;
    ans %= Mod;
  }
  ans = (2 * ans % Mod * ans % Mod + 8 * ans % Mod + 10) % Mod;
  print(ans);
  return 0;
}
