#include <bits/stdc++.h>
using namespace std;
namespace Sweet {
template <typename T>
inline void read(T &x) {
  char ch;
  int f = 1;
  while (ch = getchar(), ch > '9' || ch < '0') (ch == '-') && (f = -1);
  x = (ch ^ 48);
  while (ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48);
  x *= f;
}
template <typename T>
inline void write(T x) {
  static int stk[100], top = 0;
  if (x == 0) return (void)putchar('0');
  if (x < 0) x = -x, putchar('-');
  while (x) stk[++top] = x % 10, x /= 10;
  while (top) putchar(stk[top--] + '0');
}
const int N = 5e2 + 10, B = 61;
long long pow[B + 1];
inline void init() {
  pow[0] = 1;
  for (int i = 1; i <= B; ++i) {
    pow[i] = pow[i - 1] << 1;
  }
}
const long long inf = 1e18;
long long ans;
int n, m;
bitset<N> tmp, g, f[2][B][N];
inline void main() {
  read(n), read(m), init();
  for (int i = 1, x, y, z; i <= m; ++i)
    read(x), read(y), read(z), f[z][0][x][y] = 1;
  for (int i = 1; i <= B; ++i) {
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= n; ++y) {
        if (f[0][i - 1][x][y]) f[0][i][x] |= f[1][i - 1][y];
        if (f[1][i - 1][x][y]) f[1][i][x] |= f[0][i - 1][y];
      }
    }
  }
  if (f[0][B][1].count()) puts("-1"), exit(0);
  tmp[1] = 1;
  static bool now = 0;
  for (int i = B; ~i; --i) {
    g.reset();
    for (int j = 1; j <= n; ++j) (tmp[j]) && (g |= f[now][i][j], 0);
    if (g.count()) {
      now ^= 1, tmp = g, ans += pow[i];
    }
  }
  write(ans > inf ? -1 : ans);
}
}  // namespace Sweet
int main() {
  Sweet::main();
  return 0;
}
