#include <bits/stdc++.h>
using namespace std;
inline void readi(int &x);
const int N = 100000, K = 100, M = 1000000007;
int n, m;
int f[N + 5][K + 5], a[N + 5];
int C[N + K + 5][K + 5];
inline void up(int &x, const int &y) {
  x += y;
  if (x >= M) x -= M;
  if (x < 0) x += M;
}
void init() {
  readi(n), readi(m);
  for (int i = 1; i <= n; i++) readi(a[i]);
  for (int i = 0; i <= N; i++) {
    C[i][0] = 1;
    if (i <= K) C[i][i] = 1;
    for (int j = 1; j <= K && j < i; j++)
      up(C[i][j], C[i - 1][j]), up(C[i][j], C[i - 1][j - 1]);
  }
  for (int i = 1, l, r, k; i <= m; i++) {
    readi(l), readi(r), readi(k);
    f[l][k]++;
    for (int j = 0; j <= k; j++) up(f[r + 1][j], -C[r - l + k - j][k - j]);
  }
}
void work() {
  for (int i = 1; i <= n; i++) {
    for (int j = K; j >= 0; j--)
      up(f[i][j], f[i - 1][j]), up(f[i][j], f[i][j + 1]);
    a[i] = a[i] + f[i][0] % M;
    if (a[i] < 0) a[i] += M;
    printf("%d%c", a[i], " \n"[i == n]);
  }
}
int main() {
  init();
  work();
  return 0;
}
inline void readi(int &x) {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  x = c ^ '0';
  while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + (c ^ '0');
}
