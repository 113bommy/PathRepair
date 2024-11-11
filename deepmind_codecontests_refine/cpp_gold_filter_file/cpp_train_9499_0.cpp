#include <bits/stdc++.h>
using namespace std;
namespace Base {
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const long long infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
template <typename T>
void read(T &x) {
  x = 0;
  int fh = 1;
  double num = 1.0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    while (isdigit(ch)) {
      num /= 10;
      x = x + num * (ch - '0');
      ch = getchar();
    }
  }
  x = x * fh;
}
template <typename T>
void chmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
void chmin(T &x, T y) {
  x = x > y ? y : x;
}
}  // namespace Base
using namespace Base;
const int N = 5050, P = 998244353;
int a[N][N], c[N][N], ans[N], n, fac[N];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    a[i][0] = 1;
    for (int j = 1; j <= i - 1; j++)
      a[i][j] = (1ll * a[i - 1][j - 1] * (i - j) + a[i - 1][j] * (j + 1ll)) % P;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      ans[i] = (ans[i] + 1ll * a[j][i - 1] * c[n][j] % P * fac[n - j]) % P;
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
