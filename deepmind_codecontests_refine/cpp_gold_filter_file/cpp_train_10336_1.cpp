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
long long P, A[1000005], fac[1000005], g[5005][5005], f[5005], tmp[5005];
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
  long long s, fs = 1;
  for (int i = 1; i <= n; i++) {
    s = 0;
    for (int j = 1; j <= min(a[i], m); j++) {
      f[j] = (A[j] * g[a[i]][j] % P * fs % P -
              fac[j] * g[a[i]][j] % P * tmp[j] % P + P) %
             P;
      s = (s + f[j]) % P;
    }
    fs = s;
    for (int j = 1; j <= a[i - 1]; j++) tmp[j] = 0;
    for (int j = 1; j <= a[i]; j++) tmp[j] = f[j];
  }
  cout << fs << endl;
  return 0;
}
