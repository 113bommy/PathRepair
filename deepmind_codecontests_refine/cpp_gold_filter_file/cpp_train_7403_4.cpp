#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
const int MOD = 1e9 + 7;
int d[MAX];
int cnt[26];
void cal(int x, int n) {
  for (int i = 0; i <= n; i++) d[i] = 0;
  d[0] = 1;
  for (int i = 0; i < 26; i++) {
    if (i == x) continue;
    for (int j = n; j >= cnt[i]; j--) d[j] |= d[j - cnt[i]];
  }
}
char s[MAX];
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, m, t;
    scanf("%lld%lld%lld%s", &n, &m, &t, s + 1);
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= t; i++) cnt[s[i] - 'A']++;
    long long ans = MOD;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] == 0) continue;
      cal(i, n);
      for (int j = max(0ll, n - cnt[i]); j <= n; j++) {
        if (d[j] == 0) continue;
        ans = min(ans, (n - j) * (m - (t - cnt[i] - j)));
      }
      cal(i, m);
      for (int j = max(0ll, m - cnt[i]); j <= m; j++) {
        if (d[j] == 0) continue;
        ans = min(ans, (m - j) * (n - (t - cnt[i] - j)));
      }
    }
    printf("%lld\n", max(0ll, ans));
  }
  return 0;
}
