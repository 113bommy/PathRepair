#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
template <class t>
inline void writeln(t x) {
  write(x);
  putchar('\n');
  return;
}
template <class t>
inline void write_blank(t x) {
  write(x);
  putchar(' ');
  return;
}
long long n, m, res, ans, lop[2010], h1[5][2010], h2[5][2010], h[2010],
    f[2][2010][2010], g[2][2010][2010];
char a[5][2010], b[2010];
namespace bsfc {
long long get1(long long l, long long r, long long i) {
  return h1[i][r] - h1[i][l - 1] * lop[r - l + 1];
}
long long get2(long long l, long long r, long long i) {
  return h2[i][l] - h2[i][r + 1] * lop[r - l + 1];
}
long long merge(long long x, long long y, long long len) {
  return x * lop[len] + y;
}
void add(long long &x, long long y) {
  x = (x + y % 1000000007 + 1000000007) % 1000000007;
}
void del(long long &x, long long y) {
  x = (x - y % 1000000007 + 1000000007) % 1000000007;
}
}  // namespace bsfc
signed main() {
  cin >> a[0] + 1 >> a[1] + 1 >> b + 1;
  n = strlen(a[0] + 1);
  m = strlen(b + 1);
  lop[0] = 1;
  for (long long i = 1; i <= max(n, m); i++) {
    lop[i] = lop[i - 1] * 131;
  }
  for (long long i = 0; i <= 1; i++) {
    for (long long j = 1; j <= n; j++) {
      h1[i][j] = h1[i][j - 1] * 131 + a[i][j] - 'a' + 1;
    }
  }
  for (long long i = 0; i <= 1; i++) {
    for (long long j = n; j >= 1; j--) {
      h2[i][j] = h2[i][j + 1] * 131 + a[i][j] - 'a' + 1;
    }
  }
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (long long i = 1; i <= m; i++) {
    h[i] = h[i - 1] * 131 + b[i] - 'a' + 1;
  }
  for (long long i = 0; i <= 1; i++) {
    for (long long j = 1; j <= n; j++) {
      for (long long k = j, len = (2 * (j - k + 1)); k && len <= m;
           --k, len += 2) {
        if (bsfc::merge(bsfc::get2(k, j, i ^ 1), bsfc::get1(k, j, i),
                        j - k + 1) == h[len]) {
          if (len == m) {
            res++;
          } else {
            g[i][j][len] = 1;
          }
        }
      }
    }
  }
  for (long long i = 0; i <= 1; i++) {
    for (long long j = 1; j <= n; j++) {
      if (a[i][j] == b[1]) {
        g[i][j][1] = 1;
      }
    }
  }
  for (long long k = 1; k <= m - 1; k++) {
    for (long long i = 0; i <= 1; i++) {
      for (long long j = 1; j <= n; j++) {
        if (j < n && a[i][j + 1] == b[k + 1]) {
          bsfc::add(f[i][j + 1][k + 1], g[i][j][k] + f[i][j][k]);
        }
        if (a[i ^ 1][j] == b[k + 1]) {
          bsfc::add(g[i ^ 1][j][k + 1], f[i][j][k]);
        }
      }
    }
  }
  for (long long i = m; i >= 1; i--) {
    h[i] = h[i + 1] * 131 + b[i] - 'a' + 1;
  }
  for (long long i = 0; i <= 1; i++) {
    for (long long j = 1; j <= n; j++) {
      if (a[i][j] == b[m]) {
        if (m == 1) {
          bsfc::add(ans, 1);
        } else {
          bsfc::add(ans, f[i][j - 1][m - 1] + g[i][j - 1][m - 1]);
        }
      }
      for (long long k = j, len = 2 * (k - j + 1); k <= n && len <= m;
           k++, len += 2) {
        if (bsfc::merge(bsfc::get1(j, k, i ^ 1), bsfc::get2(j, k, i),
                        k - j + 1) == h[m - len + 1]) {
          if (len == m && m != 2) {
            res++;
          } else {
            bsfc::add(ans, f[i][j - 1][m - len] + g[i][j - 1][m - len]);
          }
        }
      }
    }
  }
  reverse(b + 1, b + m + 1);
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (long long i = 1; i <= m; i++) {
    h[i] = h[i - 1] * 131 + b[i] - 'a' + 1;
  }
  for (long long i = 0; i <= 1; i++) {
    for (long long j = 1; j <= n; j++) {
      for (long long k = j, len = (2 * (j - k + 1)); k && len <= m;
           --k, len += 2) {
        if (bsfc::merge(bsfc::get2(k, j, i ^ 1), bsfc::get1(k, j, i),
                        j - k + 1) == h[len]) {
          if (len == m) {
            res++;
          } else {
            g[i][j][len] = 1;
          }
        }
      }
    }
  }
  for (long long i = 0; i <= 1; i++) {
    for (long long j = 1; j <= n; j++) {
      if (a[i][j] == b[1]) {
        g[i][j][1] = 1;
      }
    }
  }
  for (long long k = 1; k <= m - 1; k++) {
    for (long long i = 0; i <= 1; i++) {
      for (long long j = 1; j <= n; j++) {
        if (j < n && a[i][j + 1] == b[k + 1]) {
          bsfc::add(f[i][j + 1][k + 1], g[i][j][k] + f[i][j][k]);
        }
        if (a[i ^ 1][j] == b[k + 1]) {
          bsfc::add(g[i ^ 1][j][k + 1], f[i][j][k]);
        }
      }
    }
  }
  for (long long i = m; i >= 1; i--) {
    h[i] = h[i + 1] * 131 + b[i] - 'a' + 1;
  }
  for (long long i = 0; i <= 1; i++) {
    for (long long j = 1; j <= n; j++) {
      if (a[i][j] == b[m]) {
        if (m == 1) {
          bsfc::add(ans, 1);
        } else {
          bsfc::add(ans, f[i][j - 1][m - 1] + g[i][j - 1][m - 1]);
        }
      }
      for (long long k = j, len = 2 * (k - j + 1); k <= n && len <= m;
           k++, len += 2) {
        if (bsfc::merge(bsfc::get1(j, k, i ^ 1), bsfc::get2(j, k, i),
                        k - j + 1) == h[m - len + 1]) {
          if (len == m && m != 2) {
            res++;
          } else {
            bsfc::add(ans, f[i][j - 1][m - len] + g[i][j - 1][m - len]);
          }
        }
      }
    }
  }
  bsfc::add(ans, res / 2);
  if (m == 1) {
    ans >>= 1;
  }
  write(ans);
  return 0;
}
