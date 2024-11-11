#include <bits/stdc++.h>
using namespace std;
int dp[30005], cnt[30];
char str[100005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    long long ans = 0x3f3f3f3f3f3f3f3f;
    scanf("%d%d%d", &n, &m, &k);
    if (n < m) swap(n, m);
    memset(cnt, 0, sizeof(cnt));
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) cnt[str[i] - 'A' + 1]++;
    for (int i = 1; i <= 26; i++) {
      for (int j = 1; j <= n; j++) dp[j] = 0;
      dp[0] = 1;
      for (int j = 1; j <= 26; j++) {
        if (i == j) continue;
        for (int k = n; k >= cnt[j]; k--) {
          dp[k] |= dp[k - cnt[j]];
        }
      }
      for (int j = min(cnt[i], n); j >= 0; j--) {
        if (!dp[n - j]) continue;
        ans = min(ans, 1ll * j * (max(0ll, 1ll * cnt[i] - j - k + m + n)));
      }
    }
    cout << ans << endl;
  }
}
