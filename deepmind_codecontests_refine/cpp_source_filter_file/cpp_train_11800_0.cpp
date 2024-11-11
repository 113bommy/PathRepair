#include <bits/stdc++.h>
using namespace std;
const int maxn = 2020;
int n, k, alloc = 1, lcp[maxn], dp[2 * maxn][maxn];
string s[maxn];
int solve(int l, int r) {
  if (l >= r) return 0;
  int id = alloc++;
  int mn = l + 1;
  for (int i = l + 1; i <= r; i++)
    if (lcp[i] < lcp[mn]) mn = i;
  int lid = solve(l, mn - 1), rid = solve(mn, r);
  for (int i = 0; i <= (mn - l); i++) {
    for (int j = 0; j <= (r - mn + 1); j++) {
      int tmp = dp[lid][j] + dp[rid][j] + i * j * lcp[mn];
      dp[id][i + j] = max(dp[id][i + j], tmp);
    }
  }
  return id;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n);
  for (int i = 1; i < n; i++) {
    while (lcp[i] < s[i].size() && lcp[i] < s[i - 1].size() &&
           s[i][lcp[i]] == s[i - 1][lcp[i]])
      lcp[i]++;
  }
  cout << dp[solve(0, n - 1)][k] << endl;
  return 0;
}
