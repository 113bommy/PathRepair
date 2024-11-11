#include <bits/stdc++.h>
using namespace std;
int n;
char s[2020];
bool mp[8080][8080], mp1[8080][8080];
long long ans;
int cnt2, cnt3;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    char s = getchar();
    int cur;
    for (int j = 1; j <= n / 4; ++j) {
      s = getchar();
      cur = s >= '0' && s <= '9' ? s - '0' : s - 'A' + 10;
      for (int k = 0; k < 4; ++k)
        mp1[i][j * 4 - k] = mp[i][j * 4 - k] = cur >> k & 1;
    }
  }
  ans = (614ll * n + 1) * n * (n - 1) / 2;
  for (int i = 1; i <= n; ++i) {
    int ed = 0, p = 0;
    for (int j = 1; j <= n; ++j)
      if (mp[i][j] && (!ed || mp[ed][j])) ed = j;
    for (int j = 1; j <= n; ++j)
      if (!mp[i][j] && mp[ed][j]) {
        ++cnt2;
        mp1[i][j] = 1;
        if (!p || mp[j][p]) p = j;
      }
    for (int j = 1; j <= n; ++j)
      if (!mp1[i][j] && i != j && mp[p][j]) ++cnt3;
  }
  ans -= cnt2 * (614ll * n - 2) + cnt3 * (614ll * n - 3);
  printf("%lld", ans);
  return 0;
}
