#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
bool hr[3605], hc[3605];
int cdp[3605][1805];
int cntr[1805], cntc[1805];
int h, w, n;
int gen_dp(int len, bool ch[], int ret[]) {
  memset(cdp, 0, sizeof(cdp));
  cdp[0][0] = 1;
  for (int i = 1; i <= (int)(len); i++)
    for (int j = 0; j < (int)(i / 2 + 1); j++) {
      cdp[i][j] = cdp[i - 1][j];
      if (i > 1 && !ch[i] && !ch[i - 1])
        cdp[i][j] = (cdp[i][j] + cdp[i - 2][j - 1]) % MOD;
    }
  for (int i = 0; i < (int)(len / 2 + 1); i++) ret[i] = cdp[len][i];
  int ans = 0;
  for (int i = 1; i <= (int)(len); i++) ans += !ch[i];
  return ans;
}
int C[3605][3605];
int main() {
  C[0][0] = 1;
  for (int i = 1; i <= (int)(3600); i++) {
    C[i][0] = 1;
    for (int j = 1; j <= (int)(i); j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
  for (int i = 1; i <= (int)(3600); i++) {
    int cfac = 1;
    for (int j = 1; j <= (int)(i); j++) {
      cfac = 1LL * cfac * j % MOD;
      C[i][j] = 1LL * C[i][j] * cfac % MOD;
    }
  }
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 0; i < (int)(n); i++) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    hr[r1] = hr[r2] = true;
    hc[c1] = hc[c2] = true;
  }
  int rs = gen_dp(h, hr, cntr);
  int cs = gen_dp(w, hc, cntc);
  int ans = 0;
  for (int i = 0; i < (int)(rs / 2 + 1); i++)
    for (int j = 0; j < (int)(cs / 2 + 1); j++)
      ans = (ans + 1LL * cntr[i] * cntc[j] % MOD * C[rs - 2 * i][j] % MOD *
                       C[cs - 2 * j][i]) %
            MOD;
  printf("%d\n", ans);
  return 0;
}
