#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int M = 100010;
const int INF = 0x3f3f3f3f;
const int iinf = 1 << 30;
const long long linf = 2e18;
const int mod = 1000000007;
const double eps = 1e-7;
void douout(double x) { printf("%lf\n", x + 0.0000000001); }
template <class T>
void print(T a) {
  cout << a << endl;
  exit(0);
}
template <class T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}
void add(int &a, int b) { a = a + b < mod ? a + b : a + b - mod; }
void sub(int &a, int b) { a = (a - b + mod) % mod; }
void mul(int &a, int b) { a = (long long)a * b % mod; }
int addv(int a, int b) { return (a += b) >= mod ? a -= mod : a; }
int subv(int a, int b) { return (a -= b) < 0 ? a += mod : a; }
int mulv(int a, int b) { return (long long)a * b % mod; }
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int pw(int a, int b) {
  int s = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) s = (long long)s * a % mod;
  return s;
}
int n, ans;
int a[N], h[M], g[10], f[N][N], opt[N];
void dp(int x, int y) {
  f[x][y] = 2;
  chmax(f[x][y], f[h[a[x] + 1]][y] + 1);
  chmax(f[x][y], f[h[a[x] - 1]][y] + 1);
  chmax(f[x][y], f[x][h[a[y] + 1]] + 1);
  chmax(f[x][y], f[x][h[a[y] - 1]] + 1);
  chmax(f[x][y], f[g[a[x] % 7]][y] + 1);
  chmax(f[x][y], f[x][g[a[y] % 7]] + 1);
}
signed main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (0); i <= (M - 1); i++) h[i] = n + 1;
  for (int i = (0); i <= (6); i++) g[i] = n + 1;
  for (int x = (n); x >= (1); x--) {
    for (int i = (1); i <= (x - 1); i++) dp(i, x), dp(x, i);
    h[a[x]] = g[a[x] % 7] = x;
  }
  for (int i = (1); i <= (n); i++) opt[i] = 1;
  for (int i = (1); i <= (n); i++)
    for (int j = (0); j <= (i - 1); j++)
      if (a[j] == a[i] - 1 || a[j] == a[i] + 1 || a[j] % 7 == a[i] % 7)
        opt[i] = max(opt[i], opt[j] + 1);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (i != j) ans = max(ans, f[i][j] + opt[min(i, j)] - 1);
  printf("%d\n", ans);
  return 0;
}
