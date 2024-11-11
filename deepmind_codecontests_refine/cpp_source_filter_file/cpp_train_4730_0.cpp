#include <bits/stdc++.h>
using namespace std;
inline void readi(int &x);
const int N = 1000, M = 1000000007;
int C[N + 10][N + 10], fac[N + 10];
int f[N + 10][N + 10];
void am(int &a, const int &b) {
  a += b;
  if (a >= M) a -= M;
}
void init() {
  C[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) am(C[i][j], C[i - 1][j - 1] + C[i - 1][j]);
  }
  fac[0] = 1;
  for (int i = 1; i <= N; i++) fac[i] = (long long)fac[i - 1] * i % M;
  for (int l = 0; l <= N; l++) {
    f[l][1] = 1;
    for (int k = 2; k <= 65; k++) {
      int &t = f[l][k];
      for (int i = 0; (i + 1) * k - 1 <= l; i++) {
        t += f[l - (i + 1) * k + 1][k - 1];
        if (t >= M) t -= M;
      }
    }
  }
  for (int l = 0; l <= N; l++)
    for (int k = 1; k <= N; k++) f[l][k] = (long long)f[l][k] * fac[k] % M;
}
void work() {
  int T, n, k, ans;
  for (readi(T); T--;) {
    readi(n), readi(k);
    if (k > 60) {
      printf("-1\n");
      continue;
    }
    ans = 0;
    for (int l = 0; l <= n; l++) am(ans, (long long)f[l][k] * C[n - l][k] % M);
    if (ans < 0) ans += M;
    printf("%d\n", ans);
  }
}
int main() {
  init();
  work();
  return 0;
}
inline void readi(int &x) {
  char c;
  for (c = getchar(); c > '9' || c < '0'; c = getchar())
    ;
  x = c ^ '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
    x = x * 10 + (c ^ '0');
}
