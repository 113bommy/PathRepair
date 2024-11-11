#include <bits/stdc++.h>
using namespace std;
const int inf = 0xcfcfcfcf;
int n, typ[17], rs, bs;
int f[1 << 17][17 * 17], rg[1 << 17], bg[1 << 17];
int r[17], b[17];
char opt[2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s%d%d", opt, &r[i], &b[i]);
    rs += r[i];
    bs += b[i];
    if (opt[0] == 'R')
      rg[1 << (i - 1)]++;
    else
      bg[1 << (i - 1)]++;
  }
  for (int s = 0; s < (1 << n); s++) {
    int lb = s & (-s);
    rg[s] = rg[lb] + rg[s ^ lb];
    bg[s] = bg[lb] + bg[s ^ lb];
  }
  memset(f, 0xcf, sizeof(f));
  f[0][0] = 0;
  for (int s = 0; s < (1 << n); s++)
    for (int i = 0; i <= 128; i++) {
      if (f[s][i] == inf) continue;
      for (int j = 1; j <= n; j++) {
        if ((s >> (j - 1)) & 1) continue;
        int t = s | (1 << (j - 1));
        f[t][i + min(rg[s], r[j])] =
            max(f[t][i + min(rg[s], r[j])], f[s][i] + min(bg[s], b[j]));
      }
    }
  int ans = 0x3f3f3f3f;
  for (int i = 0; i <= 128; i++)
    if (f[(1 << n) - 1][i] != inf)
      ans = min(ans, n + max(rs - i, bs - f[(1 << n) - 1][i]));
  printf("%d\n", ans);
  return 0;
}
