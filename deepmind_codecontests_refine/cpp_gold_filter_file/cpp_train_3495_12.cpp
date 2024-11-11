#include <bits/stdc++.h>
using namespace std;
const int N = 1000005, M = 21, Mod = 1000000007;
int vis[N], pri[N], tot, cnt, Ans, f[N][M], n, r;
inline int Read() {
  int t = 0, f = 1;
  char c = getchar();
  for (; c > 57 || c < 48; c = getchar())
    if (c == '-') f = -1;
  for (; c > 47 && c < 58; c = getchar()) t = (t << 1) + (t << 3) + c - 48;
  return t * f;
}
int main() {
  for (int i = 2; i < N; i++)
    if (!vis[i]) {
      pri[++tot] = i;
      for (int j = i + i; j < N; j += i) vis[j] = 1;
    }
  f[0][0] = 1;
  for (int i = 1; i < N; i++) f[0][i] = 2;
  for (int i = 1; i < N; i++) {
    f[i][0] = 1;
    for (int j = 1; j < M; j++) f[i][j] = (f[i - 1][j] + f[i][j - 1]) % Mod;
  }
  for (int m = Read(); m--;) {
    r = Read(), n = Read();
    Ans = 1;
    for (int i = 1; pri[i] * pri[i] <= n && vis[n]; i++)
      if (n % pri[i] == 0) {
        for (cnt = 0; n % pri[i] == 0; n /= pri[i], cnt++)
          ;
        Ans = 1ll * Ans * f[r][cnt] % Mod;
      }
    if (n > 1) Ans = 1ll * Ans * f[r][1] % Mod;
    printf("%d\n", Ans);
  }
}
