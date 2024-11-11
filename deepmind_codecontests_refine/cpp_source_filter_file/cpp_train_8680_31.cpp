#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const int mod = int(1e9) + 7;
int n, m, K, i, j, k, x, l, p, v;
long long C[110][110];
int f[52][52][52][110];
long long ans;
int main() {
  read(n);
  read(m);
  read(K);
  for (i = 0; i <= 100; i++) {
    C[i][0] = 1;
    for (j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  n /= 2;
  for (i = 1; i <= n; i++) f[1][i][i][1] = 1;
  for (p = 1; p <= min(n, m); p++)
    for (i = p; i <= n; i++)
      for (j = 1; j <= i; j++)
        for (k = 1; k <= K; k++)
          if (v = f[p][i][j][k]) {
            ans = ((ans) + (1LL * (m - p) * v)) % mod;
            for (x = 1; x <= n - i; x++) {
              long long ff = C[j + x - 1][x];
              if (ff > K) continue;
              int t = k * ff;
              if (t <= K)
                f[p + 1][j + x][x][t] = ((f[p + 1][j + x][x][t]) + (v)) % mod;
            }
          }
  cout << ans << endl;
  scanf("\n");
  return 0;
}
