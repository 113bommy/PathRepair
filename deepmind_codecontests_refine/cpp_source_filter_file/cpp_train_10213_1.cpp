#include <bits/stdc++.h>
using namespace std;
int n, k, x, y, tmp, ans, f[12], a[200005], dp[200005][11];
map<int, int> m[12];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  f[0] = 1;
  for (int i = 1; i <= 10; i++) {
    f[i] = f[i - 1] * 10 % k;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    y = x, tmp = 0;
    a[i] = log10(x) + 1;
    x %= k;
    for (int j = 0; j <= 10; j++) {
      dp[i][j] = f[j] * x % k;
      m[j][dp[i][j]]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    tmp = (k - dp[i][0]) % k;
    if (m[a[i]].count(tmp)) {
      ans += m[a[i]][tmp] - (dp[i][a[i]] == tmp);
    }
  }
  cout << ans << '\n';
}
