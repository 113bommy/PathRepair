#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int powmod(int a, int b) {
  int tmp = 1;
  a %= (1000000007);
  for (; b; b >>= 1) {
    if (b & 1) tmp = tmp * a % (1000000007);
    a = a * a % (1000000007);
  }
  return tmp;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <class T>
inline void R(T &xx) {
  xx = 0;
  char ch = getchar();
  bool F = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') F = 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
  if (F) xx = -xx;
}
template <class T>
inline void add(int &x, T y) {
  for (x += y; x >= (1000000007); x -= (1000000007))
    ;
}
int n, k, a[5011], f[5011][2222][2], ans;
int main() {
  R(n);
  R(k);
  for (int i = 1; i <= n; i++) R(a[i]);
  f[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0 || a[i] == 2)
      for (int j = 0; j < (int)2049; j++) {
        int p = min(j + 2, 2048);
        add(f[i][p][1], f[i - 1][j][1]);
        add(f[i][p][0], f[i - 1][j][0]);
      }
    if (a[i] == 0 || a[i] == 4)
      for (int j = 0; j < (int)2049; j++) {
        int p = min(j + 4, 2048);
        if (j % 4)
          add(f[i][4][j >= (1 << k)], f[i - 1][j][0]),
              add(f[i][4][1], f[i - 1][j][1]);
        else
          add(f[i][p][0], f[i - 1][j][0]), add(f[i][p][1], f[i - 1][j][1]);
      }
  }
  for (int i = 0; i < (int)2049; i++) {
    add(ans, f[n][i][1]);
    if (i >= (1 << k)) add(ans, f[n][i][0]);
  }
  printf("%d\n", ans);
  return 0;
}
