#include <bits/stdc++.h>
const int N = 30, M = (1 << 23) + 5, mod = 998244353;
int n;
int cnt[N][26];
int rk[26][N];
int f[M];
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    static char s[20005];
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    for (int j = 1; j <= l; ++j) ++cnt[i][s[j] - 'a'];
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = 1; j <= n; ++j) rk[i][j] = j;
    std::sort(rk[i] + 1, rk[i] + 1 + n,
              [&](int x, int y) -> bool { return cnt[x][i] < cnt[y][i]; });
  }
  f[(1 << n) - 1] = 1;
  for (int i = 0; i < 26; ++i)
    for (int s = 1; s < 1 << n; ++s)
      if (f[s]) {
        int tmp = f[s];
        f[s] = 0;
        int now = (1 << n) - 1;
        const int *r = rk[i];
        for (int j = 1; j <= n; ++j)
          if (s & now) {
            int t = s & now, bas = cnt[r[j]][i] - cnt[r[j - 1]][i] + (j == 1);
            f[t] = (f[t] + 1ll * tmp * bas) % mod;
            now ^= 1 << (r[j] - 1);
          }
      }
  for (int i = 0; i < n; ++i)
    for (int s = 0; s < 1 << n; ++s)
      if ((s >> i) & 1) f[s] = (f[s] + f[s ^ (1 << i)]) % mod;
  long long ans = 0;
  for (int s = 1; s < 1 << n; ++s) {
    int bas = 0, c = 0;
    for (int i = 0; i < n; ++i)
      if ((s >> i) & 1) bas += i + 1, ++c;
    ans ^= 1ll * (f[(1 << n) - 1] - f[(1 << n) - s - 1] + mod) % mod * bas * c;
  }
  printf("%lld\n", ans);
  return 0;
}
