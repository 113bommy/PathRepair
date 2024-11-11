#include <bits/stdc++.h>
using namespace std;
const double eps(1e-8);
int comb[110][110], f[52][102][52][102];
int n, m, k;
const int mod = 1000000007;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i <= n; i++) comb[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i == j)
        comb[i][j] = 1;
      else
        comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
      comb[i][j] = min(comb[i][j], 101);
    }
  f[0][0][0][1] = 1;
  int ans = 0;
  for (int i = 0; i < m && i <= n / 2; i++)
    for (int len = 0; len <= n; len++)
      for (int last = 0; last <= n / 2; last++)
        for (int way = 0; way <= k; way++) {
          int num = f[i][len][last][way];
          if (!num) continue;
          if (i) ans = (ans + ((long long)num * (m - i)) % mod) % mod;
          for (int next = 1; next * 2 + len <= n; next++) {
            int nway = way * comb[last + next - 1][next - 1];
            if (nway > k) continue;
            f[i + 1][len + next * 2][next][nway] += num;
            if (f[i + 1][len + next * 2][next][nway] > mod)
              f[i + 1][len + next * 2][next][nway] -= mod;
          }
        }
  printf("%d\n", ans);
  return 0;
}
