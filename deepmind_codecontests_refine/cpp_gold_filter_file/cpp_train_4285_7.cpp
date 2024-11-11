#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int mo = 1e9 + 7;
int n, K, kai1[N], m;
inline int fix(int x) {
  if (x >= mo) return x - mo;
  return x < 0 ? x + mo : x;
}
inline int hapow1(int x, int y) {
  int daan = 1;
  while (y) {
    if (y & 1) daan = 1ll * daan * x % mo;
    x = 1ll * x * x % mo;
    y >>= 1;
  }
  return daan;
}
struct matrix {
  int ma[N][N];
  friend matrix operator*(matrix x, matrix y) {
    matrix z;
    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= m; j++) {
        z.ma[i][j] = 0;
        for (int k = 0; k <= m; k++)
          z.ma[i][j] = fix(z.ma[i][j] + 1ll * x.ma[i][k] * y.ma[k][j] % mo);
      }
    return z;
  }
} kai, ans;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void hapow(int y) {
  while (y) {
    if (y & 1) ans = ans * kai;
    kai = kai * kai;
    y >>= 1;
  }
}
inline int C(int x) { return x * (x - 1) / 2; }
int main() {
  n = read();
  K = read();
  for (int i = 1; i <= n; i++) kai1[i] = read(), m += (kai1[i] == 0);
  int hu = 0;
  for (int i = 1; i <= m; i++) hu += (kai1[i] == 0);
  ans.ma[0][hu] = 1;
  int inv = hapow1(n * (n - 1) / 2, mo - 2);
  for (int i = 0; i <= m; i++) {
    kai.ma[i][i] = 1ll * inv *
                   (i * (m - i) + (m - i) * (n - 2 * m + i) + C(m) + C(n - m)) %
                   mo;
    if (i != 0) kai.ma[i][i - 1] = 1ll * inv * i % mo * (n - 2 * m + i) % mo;
    kai.ma[i][i + 1] = 1ll * inv * (m - i) % mo * (m - i) % mo;
  }
  hapow(K);
  cout << ans.ma[0][m];
  return 0;
}
