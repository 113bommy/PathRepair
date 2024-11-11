#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long p) {
  long long res = 1;
  a %= p;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
  }
  return res;
}
template <typename T>
T gcd(T x, T y) {
  while (y) {
    T t = x % y;
    x = y;
    y = t;
  }
  return x;
}
template <typename T>
T lsM(T x, T y) {
  return x / gcd(x, y) * y;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int n, m, mp[25][25];
struct mat {
  int a[25][25];
} now;
mat mul(mat x, mat y) {
  mat z;
  memset(z.a, 0, sizeof z.a);
  for (int i = 1; i <= n * m; i++)
    for (int j = 1; j <= n * m; j++)
      for (int k = 1; k <= n * m; k++) {
        z.a[i][j] = (z.a[i][j] + 1LL * x.a[i][k] * y.a[k][j]) % 1000000007;
      }
  return z;
}
mat power(mat x, int y) {
  mat res;
  memset(res.a, 0, sizeof res.a);
  for (int i = 1; i <= n * m; i++) res.a[i][i] = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int id(int x, int y) { return (x - 1) * m + y; }
int main() {
  int q;
  scanf("%d%d%d", &n, &m, &q);
  int lst = 1;
  memset(now.a, 0, sizeof now.a);
  for (int i = 1; i <= n * m; i++) now.a[i][i] = 1;
  while (q--) {
    int typ, x, y, t;
    scanf("%d%d%d%d", &typ, &x, &y, &t);
    mat tmp;
    memset(tmp.a, 0, sizeof tmp.a);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        for (int k = 0; k < 4; k++) {
          int nx = i + dx[k], ny = j + dy[k];
          if (nx < 1 || nx > n || ny < 1 || ny > m || mp[i][j] || mp[nx][ny])
            continue;
          tmp.a[id(i, j)][id(nx, ny)] = 1;
        }
        if (!mp[i][j]) tmp.a[id(i, j)][id(i, j)] = 1;
      }
    now = mul(now, power(tmp, t - lst));
    if (typ == 1)
      printf("%d\n", now.a[1][id(x, y)]);
    else if (typ == 2)
      mp[x][y] = 1;
    else
      mp[x][y] = 0;
    lst = t;
  }
  return 0;
}
