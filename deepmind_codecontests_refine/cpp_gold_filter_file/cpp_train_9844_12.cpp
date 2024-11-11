#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  set<long long> st;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] -= i;
    st.insert(a[i]);
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 1e17));
  dp[0][0] = 0;
  long long m = 0;
  vector<long long> b(n + 1);
  for (auto x : st) {
    b[m] = x;
    m++;
  }
  m--;
  for (long long i = 1; i <= n; i++) {
    long long mindp = dp[i - 1][0];
    for (long long j = 0; j <= m; j++) {
      mindp = min(mindp, dp[i - 1][j]);
      dp[i][j] = mindp + abs(a[i] - b[j]);
    }
  }
  long long ans = 1e18;
  for (long long i = 0; i <= m; i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans << endl;
}
