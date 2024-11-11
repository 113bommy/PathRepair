#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, dp[N], cost[N], prefq[N], pref[2][N];
string s;
int check(int idx) {
  int q = prefq[idx + m - 1] - prefq[idx - 1];
  bool b = (idx & 1);
  int p = pref[b][idx + m - 1] - pref[b][idx - 1];
  if (p + q != m) return INT_MAX;
  return q;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s >> m;
  for (int i = (1); i < (n + 1); i++) {
    prefq[i] = prefq[i - 1] + (s[i - 1] == '?');
    pref[0][i] = pref[0][i - 1];
    pref[1][i] = pref[1][i - 1];
    if (s[i - 1] != '?') {
      if (i % 2) {
        if (s[i - 1] == 'a') pref[0][i]++;
        if (s[i - 1] == 'b') pref[1][i]++;
      } else {
        if (s[i - 1] == 'b') pref[0][i]++;
        if (s[i - 1] == 'a') pref[1][i]++;
      }
    }
  }
  dp[0] = 0;
  for (int i = (1); i < (n + 1); i++) {
    dp[i] = dp[i - 1];
    cost[i] = cost[i - 1];
    int c = check(i - m + 1);
    if (i >= m && c < INT_MAX &&
        (1 + dp[i - m] > dp[i] ||
         (1 + dp[i - m] == dp[i] && c + cost[i - m] < cost[i]))) {
      dp[i] = 1 + dp[i - m];
      cost[i] = c + cost[i - m];
    }
  }
  cout << cost[n] << '\n';
}
