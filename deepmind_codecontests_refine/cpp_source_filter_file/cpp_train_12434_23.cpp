#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const int INF = 1 << 30;
int n, m, s, e;
int a[N], b[N], dp[305][N];
vector<int> v[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> s >> e;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    v[b[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) v[a[i]].push_back(INF);
  for (int i = 1; i <= s / e; i++) dp[i][0] = INF;
  for (int i = 0; i <= n + 100; i++) dp[0][i] = 0;
  int ans;
  for (int i = 1; i <= s / e; i++) {
    for (int j = 1; j <= n; j++) {
      int it = lower_bound(v[a[j]].begin(), v[a[j]].end(),
                           min(dp[i - 1][j - 1] + 1, INF)) -
               v[a[j]].begin();
      dp[i][j] = min(v[a[j]][it], dp[i][j - 1]);
      if (j + i * e + dp[i][j] <= s) ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
