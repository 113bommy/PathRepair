#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &n) {
  n = 0;
  T f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (isdigit(c)) n = n * 10 + c - '0', c = getchar();
  n *= f;
}
template <typename T>
void write(T n) {
  if (n < 0) putchar('-'), n = -n;
  if (n > 9) write(n / 10);
  putchar(n % 10 + '0');
}
int n, m, a[1000005];
long long P, A[1000005], fac[1000005], g[5005][5005], f[2][5005];
void init() {
  A[0] = fac[0] = 1;
  for (int i = 1; i <= m; i++) fac[i] = fac[i - 1] * i % P;
  for (int i = 1; i <= m; i++) A[i] = A[i - 1] * (m - i + 1) % P;
}
int main() {
  cin >> n >> m >> P;
  for (int i = 1; i <= n; i++) read(a[i]);
  init();
  g[0][0] = 1;
  for (int i = 1; i < 5005; i++) {
    for (int j = 1; j <= min(i, m); j++) {
      g[i][j] = (g[i - 1][j - 1] + g[i - 1][j] * (j - 1) % P) % P;
    }
  }
  int p = 0;
  for (int i = 1; i <= min(a[1], m); i++) {
    f[p][i] = (A[i] * g[a[1]][i] % P + f[p][i - 1]) % P;
  }
  for (int i = 2; i <= n; i++) {
    p ^= 1;
    for (int j = 1; j <= min(a[i], m); j++) {
      long long t = (f[p ^ 1][j] - f[p ^ 1][j - 1] + P) % P;
      if (j > a[i - 1]) t = 0;
      f[p][j] = (A[j] * g[a[i]][j] % P * f[p ^ 1][min(a[i - 1], m)] % P -
                 fac[j] * g[a[i]][j] % P * t % P + P) %
                P;
    }
    for (int j = 1; j <= min(a[i], m); j++) (f[p][j] += f[p][j - 1]) %= P;
  }
  cout << f[p][min(a[n], m)] << endl;
  return 0;
}
