#include <bits/stdc++.h>
using namespace std;
const int INF = 1000;
const int N = 500 + 10;
int n, m, k, dp[N][N], ans[N][N];
string s[N];
void solve(int t) {
  vector<int> a;
  for (int i = 0; i < s[t].size(); i++)
    if (s[t][i] == '1') a.push_back(i + 1);
  for (int i = a.size(); i <= k; i++) ans[t][i] = 0;
  for (int i = 0; i < a.size(); i++) {
    ans[t][i] = INF;
    for (int j = 0; j <= i; j++)
      ans[t][i] = min(ans[t][i], a[a.size() - i + j - 1] - a[j] + 1);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    solve(i);
  }
  for (int i = 0; i <= k; i++) dp[0][i] = ans[0][i];
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= k; j++) {
      dp[i][j] = INF;
      for (int z = 0; z <= j; z++)
        dp[i][j] = min(dp[i - 1][j - z] + ans[i][z], dp[i][j]);
    }
  cout << dp[n - 1][k] << endl;
}
