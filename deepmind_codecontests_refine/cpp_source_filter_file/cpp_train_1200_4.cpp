#include <bits/stdc++.h>
namespace chtholly {
char buf[1 << 23], *p1 = buf, *p2 = buf;
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
  if (x < 0) putchar('-'), x = -x;
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
const int mulu = 4e5;
typedef long long fuko[mulu | 10];
fuko mp, mp1, mp2, g, pr, p;
long long min_25(long long n) {
  long long i, j, m = sqrt(n + .5);
  for (i = 2; i <= mulu; ++i) {
    if (!p[i]) pr[++*pr] = i;
    for (j = 1; j <= *pr && pr[j] * i <= mulu; ++j) {
      p[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
  for (i = 1; i <= n; i = j + 1) {
    j = n / (n / i);
    mp[++*mp] = n / i;
    mp[*mp] <= m ? mp1[mp[*mp]] = *mp : mp2[n / mp[*mp]] = *mp;
    g[*mp] = mp[*mp] - 1;
  }
  for (j = 1; j <= *pr; ++j) {
    for (i = 1; i <= *mp && pr[j] * pr[j] <= mp[i]; ++i) {
      long long tmp = mp[i] / pr[j];
      tmp = tmp <= m ? mp1[tmp] : mp2[n / tmp];
      g[i] -= g[tmp] - j + 1;
    }
  }
  long long zw = 0;
  for (i = 1; i <= *pr && pr[i] <= m; ++i) {
    zw += g[n / (n / pr[i])] - g[mp1[n / (n / pr[i])]];
  }
  for (i = 1; i <= *pr && pr[i] * pr[i] * pr[i] <= n; ++i)
    ;
  return zw + i - 1;
}
int main() {
  long long n;
  read(n);
  printf("%lld\n", min_25(n));
}
