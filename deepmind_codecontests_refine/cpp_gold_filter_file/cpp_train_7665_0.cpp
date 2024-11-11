#include <bits/stdc++.h>
using namespace std;
bool se[1000001] = {0};
void seive(long long int n) {
  for (long long int i = 2; i <= n; i++) {
    if (se[i]) {
      continue;
    }
    for (long long int u = 2 * i; u <= n; u += i) {
      se[u] = true;
    }
  }
}
const int N = 1e9 + 7;
vector<vector<int>> g(300001);
vector<int> in(300001);
int dp[300001][26];
queue<int> q;
int main() {
  long long int t;
  t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = '0' + s;
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      in[y]++;
    }
    for (int i = 1; i <= n; i++) {
      if (in[i] == 0) {
        q.push(i);
      }
    }
    int ans = INT_MIN;
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      dp[t][s[t] - 'a']++;
      for (int i = 0; i < 26; i++) {
        ans = max(ans, dp[t][i]);
      }
      n--;
      for (auto ad : g[t]) {
        for (int j = 0; j < 26; j++) {
          dp[ad][j] = max(dp[ad][j], dp[t][j]);
        }
        in[ad]--;
        if (in[ad] == 0) {
          q.push(ad);
        }
      }
    }
    if (n > 0) {
      cout << -1;
    } else {
      cout << ans;
    }
  }
  return 0;
}
