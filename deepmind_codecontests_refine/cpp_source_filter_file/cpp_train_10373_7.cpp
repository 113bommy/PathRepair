#include <bits/stdc++.h>
using namespace std;
const int N = 1010, P = 1e9 + 7;
int ans = 1, B[N], C[N][N], m, n;
bitset<N> vis, f, b[60], t;
char s[N];
int main() {
  scanf("%d%d", &m, &n);
  B[0] = 1;
  for (int i = (1); i <= (m); ++i) f[i] = 1;
  for (int i = (0); i <= (m); ++i) {
    C[i][0] = 1;
    for (int j = (1); j <= (m); ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
  }
  for (int i = (1); i <= (m); ++i)
    for (int j = (0); j <= (i - 1); ++j)
      B[i] = (B[i] + 1ll * B[j] * C[i - 1][j]) % P;
  for (int i = (1); i <= (n); ++i) {
    scanf("%s", s + 1);
    for (int j = (1); j <= (m); ++j) b[i][j] = s[j] - 48;
  }
  for (int i = (1); i <= (m); ++i)
    if (!vis[i]) {
      t = f;
      for (int j = (1); j <= (n); ++j)
        if (b[j][i])
          t &= b[j];
        else
          t &= f ^ b[j];
      ans = 1ll * ans * B[t.count()] % P;
      vis |= t;
    }
  printf("%d\n", ans);
  return 0;
}
