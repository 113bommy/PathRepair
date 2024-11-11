#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
template <typename T>
inline void Sol(T &x) {
  if (x >= mod) x -= mod;
}
template <typename T1, typename T2>
inline void Add(T1 &x, T2 y) {
  x += y;
  Sol(x);
}
template <typename T1, typename T2>
inline void Dec(T1 &x, T2 y) {
  x += mod - y;
  Sol(x);
}
int n, p, f[2][2][2][2], pw[maxn], c[maxn];
int main() {
  n = read(), p = read();
  pw[0] = 1;
  for (int i = 1; i <= n; i++) c[i] = read();
  for (int i = 1; i <= n; i++) pw[i] = (pw[i - 1] << 1) % mod;
  if (c[1] == 0)
    f[1][0][1][1] = 1;
  else if (c[1] == 1)
    f[1][1][0][1] = 1;
  else
    f[1][0][1][1] = f[1][1][0][1] = 1;
  for (int i = 1; i < n; i++) {
    int np = i & 1, p = np ^ 1;
    memset(f[p], 0, sizeof f[p]);
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        for (int l = 0; l < 2; l++)
          if (f[np][j][k][l]) {
            int now = 1LL * pw[i - 1] * f[np][j][k][l] % mod;
            if (c[i + 1] != 0) {
              if (k)
                Add(f[p][j][k][l], now), Add(f[p][j | 1][k][l ^ 1], now);
              else
                Add(f[p][j | 1][k][l ^ 1], 1LL * (now << 1) % mod);
            }
            if (c[i + 1] != 1) {
              if (j)
                Add(f[p][j][k][l], now), Add(f[p][j][k | 1][l ^ 1], now);
              else
                Add(f[p][j][k | 1][l ^ 1], 1LL * (now << 1) % mod);
            }
          }
  }
  int ans = 0, np = n & 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) Add(ans, f[np][i][j][p]);
  printf("%d\n", ans);
  return 0;
}
