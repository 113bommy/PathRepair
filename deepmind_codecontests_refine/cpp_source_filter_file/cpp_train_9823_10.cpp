#include <bits/stdc++.h>
namespace chtholly {
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= c == '-';
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return f ? x : -x;
}
template <typename mitsuha>
inline bool read(mitsuha &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c) && ~c; c = getchar()) f ^= c == '-';
  if (!~c) return 0;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return x = f ? x : -x, 1;
}
template <typename mitsuha>
inline int write(mitsuha x) {
  if (!x) return 0 & putchar(48);
  if (x < 0) x = -x, putchar('-');
  int bit[20], i, p = 0;
  for (; x; x /= 10) bit[++p] = x % 10;
  for (i = p; i; --i) putchar(bit[i] + 48);
  return 0;
}
inline char fuhao() {
  char c = getchar();
  for (; isspace(c); c = getchar())
    ;
  return c;
}
}  // namespace chtholly
using namespace chtholly;
using namespace std;
long long dp[62];
long long get(long long x) {
  if (!x) return 0;
  long long llx = 0;
  int i, j, k;
  for (i = 1; i <= 60; ++i) {
    for (j = 2; i * j <= 60; ++j) {
      long long t = 0, ub, lb;
      for (k = 0; k < j; ++k) t += 1ll << (i * k);
      ub = min(x / t, (1ll << i) - 1), lb = 1ll << (i - 1);
      if (lb <= ub) llx += (ub - lb + 1) * dp[j];
    }
  }
  return llx;
}
int main() {
  int i, j;
  fill(dp + 1, dp + 61, 1);
  for (i = 2; i <= 60; ++i)
    for (j = i << 1; j <= 60; j += i) dp[j] -= dp[i];
  long long l, r;
  read(l), read(r);
  write(get(r) - get(l));
}
