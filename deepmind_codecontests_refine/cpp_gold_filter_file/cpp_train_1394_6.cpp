#include <bits/stdc++.h>
using namespace std;
const int MAX_INT = (1ll << 31) - 1;
const int INF = 2e9 + 10;
const long long inf = 9e18 + 10;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
void err() { cout << endl; }
template <typename T, typename... Args>
void err(T a, Args... args) {
  cout << a << " ";
  err(args...);
}
template <template <typename...> class T, typename t, typename... A>
void err(const T<t> &arg, const A &...args) {
  for (auto &it : arg) cout << it << " ";
  err(args...);
}
template <typename T>
void err(T a[], int l, int r) {
  for (int i = (l); i <= (r); ++i) cout << a[i] << " ";
  cout << endl;
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  x *= f;
  return;
}
const int N = 55;
int c[N][N];
long long f[N * 4][N][N];
void init(int n) {
  for (int i = (0); i <= (n); ++i) c[i][0] = 1;
  for (int i = (1); i <= (n); ++i) {
    for (int j = (1); j <= (i); ++j)
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1], c[i][j] %= MOD;
  }
}
int C(int n, int m) { return n < 0 || m < 0 || n < m ? 0 : c[n][m]; }
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  init(n);
  int X = 0, Y = 0;
  for (int i = (1); i <= (n); ++i) {
    int w;
    scanf("%d", &w);
    if (w == 50)
      X += 1;
    else
      Y += 1;
  }
  f[0][X][Y] = 1;
  for (int i = (1); i <= (4 * n); ++i) {
    if (i & 1) {
      for (int x = (0); x <= (X); ++x)
        for (int y = (0); y <= (Y); ++y) {
          if (f[i - 1][x][y] == 0) continue;
          for (int a = (0); a <= (x); ++a)
            for (int b = (0); b <= (y); ++b) {
              if (a * 50 + b * 100 <= k && a + b > 0)
                f[i][x - a][y - b] += f[i - 1][x][y] * C(x, a) * C(y, b) % MOD;
            }
        }
    } else {
      for (int x = (0); x <= (X); ++x)
        for (int y = (0); y <= (Y); ++y) {
          if (f[i - 1][x][y] == 0) continue;
          for (int a = (0); a <= (X - x); ++a)
            for (int b = (0); b <= (Y - y); ++b) {
              if (a * 50 + b * 100 <= k && a + b > 0)
                f[i][x + a][y + b] +=
                    f[i - 1][x][y] * C(X - x, a) * C(Y - y, b) % MOD;
            }
        }
    }
  }
  long long ansi = -1, ans = 0;
  for (int i = (0); i <= (4 * n); ++i)
    if (f[i][0][0]) {
      ansi = i, ans = f[i][0][0];
      break;
    }
  printf("%lld\n%lld\n", ansi, ans % MOD);
  return 0;
}
