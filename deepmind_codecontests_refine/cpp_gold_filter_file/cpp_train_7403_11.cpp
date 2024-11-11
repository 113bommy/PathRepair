#include <bits/stdc++.h>
using namespace std;
int T, n, m, k;
char s[200010];
int sum[27];
int ans, s1, s2;
bool f[200010];
int main() {
  scanf("%d", &T);
  while (T--) {
    for (int i = 1; i <= 26; i++) sum[i] = 0;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s + 1);
    for (int i = 1; i <= k; i++) sum[s[i] - 'A' + 1]++;
    ans = 0x3f3f3f3f;
    for (int i = 1; i <= 26; i++)
      if (sum[i]) {
        for (int j = 1; j <= k; j++) f[j] = 0;
        f[0] = 1;
        for (int j = 1; j <= 26; j++) {
          if (j == i) continue;
          if (!sum[j]) continue;
          for (int t = k; t >= 1; t--)
            if (t >= sum[j]) f[t] |= f[t - sum[j]];
        }
        for (int j = 0; j <= k; j++)
          if (f[j]) {
            s1 = max(0, n - j);
            s2 = max(0, m - (k - sum[i] - j));
            if (s1 + s2 <= sum[i]) ans = min(ans, s1 * s2);
          }
      }
    printf("%d\n", ans);
  }
}
