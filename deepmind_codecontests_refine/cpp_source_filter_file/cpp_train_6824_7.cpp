#include <bits/stdc++.h>
using namespace std;
void fast();
long long arr[100000 + 50];
string s[100000 + 50][2];
int comp[100000 + 50][2][2];
int n;
long long dp[100000 + 50][5];
long long minCost(long long i, long long last) {
  if (i == n) return 0;
  if (dp[i][last] != -1) return dp[i][last];
  long long ret = 1e18;
  if (comp[i - 1][last][0] == 1) ret = min(ret, minCost(i + 1, 0));
  if (comp[i - 1][last][1] == 1) ret = min(ret, minCost(i + 1, 1) + arr[i]);
  return dp[i][last] = ret;
}
int main() {
  fast();
  cin >> n;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    cin >> s[i][0];
    s[i][1] = s[i][0];
    reverse(s[i][1].begin(), s[i][1].end());
  }
  for (int i = 1; i < n; i++) {
    if (s[i - 1][1] <= s[i][0]) comp[i - 1][1][0] = 1;
    if (s[i - 1][0] <= s[i][0]) comp[i - 1][0][0] = 1;
    if (s[i - 1][0] <= s[i][1]) comp[i - 1][0][1] = 1;
    if (s[i - 1][1] <= s[i][1]) comp[i - 1][1][1] = 1;
  }
  long long ans = min(minCost(1, 0), 1 + minCost(1, 1));
  if (ans == 1e18)
    cout << -1;
  else
    cout << ans;
  return 0;
}
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
