#include <bits/stdc++.h>
using namespace std;
const int Inf = 1e9;
const int N = 2e5 + 1;
int a[N], b[N];
vector<int> v[N];
int dp[2][N];
int main() {
  int n, m, s, e;
  scanf("%d %d %d %d", &n, &m, &s, &e);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) {
    scanf("%d", b + i);
    v[b[i]].push_back(i);
  }
  int ans = 0;
  fill(dp[0], dp[0] + N, -1);
  for (int i = 1; i <= s / e; i++) {
    int last = -1;
    for (int j = 0; j < n; j++) {
      dp[i % 2][j] = -1;
      if ((i == 1 || last != -1) && v[a[j]].size() && v[a[j]].back() > last) {
        int it =
            upper_bound(v[a[j]].begin(), v[a[j]].end(), last) - v[a[j]].begin();
        if (i * e + j + 1 + v[a[j]][it] + 1 <= s) ans = i;
        dp[i % 2][j] = v[a[j]][it];
      }
      if (dp[1 - i % 2][j] != -1)
        last = min(last == -1 ? Inf : last, dp[1 - i % 2][j]);
    }
  }
  cout << ans << endl;
}
