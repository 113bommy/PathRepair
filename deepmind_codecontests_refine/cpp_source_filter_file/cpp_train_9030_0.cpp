#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <typename T>
void chmax(T &x, const T &y) {
  if (x < y) x = y;
}
int read() {
  char c;
  while ((c = getchar()) < '-')
    ;
  if (c == '-') {
    int x = (c = getchar()) - '0';
    while ((c = getchar()) >= '0') x = x * 10 + c - '0';
    return -x;
  }
  int x = c - '0';
  while ((c = getchar()) >= '0') x = x * 10 + c - '0';
  return x;
}
const int N = 4000 + 5, M = N * 2, K = 80, D = 998244353;
long long mi(long long x, int y = D - 2) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % D;
    x = x * x % D;
    y >>= 1;
  }
  return ans;
}
int k, t[N], to[M], nex[M];
long long f[N][K], fe[M][K], g[M][K], F[2][K];
long long jie[K];
long long C(int n, int m) { return jie[n] * mi(jie[m] * jie[n - m] % D); }
void get(int n, long long F[]) {
  for (int i = 1; i <= n; ++i) t[i] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    int x = read(), y = read();
    to[i * 2] = y;
    nex[i * 2] = t[x];
    t[x] = i * 2;
    to[i * 2 + 1] = x;
    nex[i * 2 + 1] = t[y];
    t[y] = i * 2 + 1;
  }
  for (int i = 1; i <= n; ++i) f[i][0] = 1;
  for (int i = 2; i <= n * 2 - 1; ++i) g[i][0] = 1;
  for (int j = 1; j <= k; ++j) {
    for (int u = 1; u <= n; ++u) {
      long long ans = 0;
      for (int i = t[u]; i; i = nex[i]) (ans += fe[i ^ 1][j - 1]) %= D;
      f[u][j] = ans;
    }
    for (int i = 2; i <= n * 2 - 1; ++i) {
      int u = to[i ^ 1], v = to[i];
      long long ans = 0;
      for (int x = 0; x <= j - 1; ++x) (ans += g[i][x] * f[v][j - 1 - x]) %= D;
      fe[i][j] = ans;
      ans = f[u][j];
      for (int x = 0; x <= j - 1; ++x)
        (ans -= g[i][x] * fe[i ^ 1][j - x - 1]) %= D;
      g[i][j] = ans;
    }
  }
  for (int j = 0; j <= k; ++j) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += f[i][j];
    F[j] = ans % D;
  }
}
int main() {
  int n1 = read(), n2 = read();
  k = read();
  get(n1, F[0]);
  get(n2, F[1]);
  jie[0] = 1;
  for (int i = 1; i <= k; ++i) jie[i] = jie[i - 1] * i % D;
  long long ans = 0;
  for (int x = 0; x <= k; ++x)
    (ans += F[0][x] * F[1][k - x] % D * C(k, x)) %= D;
  cout << (ans + D) % D;
}
