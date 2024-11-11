#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 1e18, x, y, l, r, s, z, a[1000000], b[1000000], f[10005];
template <typename T>
inline void read(T &n) {
  T w = 1;
  n = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != EOF) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch) && ch != EOF) {
    n = (n << 3) + (n << 1) + (ch & 15);
    ch = getchar();
  }
  n *= w;
}
template <typename T>
inline void write(T x) {
  char F[10001];
  if (x == 0) putchar('0');
  T tmp = x > 0 ? x : -x;
  if (x < 0) putchar('-');
  long long cnt = 0;
  while (tmp > 0) {
    F[cnt++] = tmp % 10 + 48;
    tmp /= 10;
  }
  while (cnt > 0) putchar(F[--cnt]);
}
int main() {
  long long i, j;
  read(n);
  for (i = 1; i <= n; i++) {
    read(b[i]);
    read(a[i]);
    b[i]++;
    m = max(m, b[i]);
  }
  m += n;
  for (i = 0; i <= m; i++) f[i] = 1e18;
  f[0] = 0;
  for (i = 1; i <= n; i++) {
    for (j = m; j >= b[i]; j--) {
      f[j] = min(f[j], f[j - b[i]] + a[i]);
    }
  }
  for (i = n; i <= m; i++) ans = min(ans, f[i]);
  write(ans);
  return 0;
}
