#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int mod = 998244353;
int a[N], s[N], f[N][105], b[N][105];
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return;
}
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
int main() {
  int n, k, len;
  read(n), read(k), read(len);
  if (len == 1) {
    printf("0\n");
    return 0;
  }
  s[0] = 1;
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k; ++j)
      if (a[i] == j || a[i] == -1) b[i][j] = 1;
  for (int j = 1; j <= k; ++j)
    for (int i = 1; i <= n; ++i) b[i][j] += b[i - 1][j];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (~a[i] && a[i] != j) continue;
      f[i][j] = s[i - 1];
      if (i >= len && b[i][j] - b[i - len][j] == len)
        add(f[i][j], (f[i - len][j] - s[i - len] + mod) % mod);
      add(s[i], f[i][j]);
    }
  }
  printf("%d\n", s[n]);
  return 0;
}
