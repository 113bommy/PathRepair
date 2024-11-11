#include <bits/stdc++.h>
using namespace std;
constexpr int fn = 5000;
vector<vector<int>> adj(fn + 1, vector<int>());
vector<int> tsz(fn + 1);
bool dp[fn + 1] = {false};
int r = fn;
int x = 0;
int dfs(int cur, int par, int n) {
  tsz[cur] = 0;
  vector<int> s;
  for (int ch : adj[cur]) {
    if (ch != par) {
      int num = dfs(ch, cur, n);
      s.push_back(num);
      tsz[cur] += num;
    }
  }
  if (n - 1 - tsz[cur] >= 1) {
    s.push_back(n - 1 - tsz[cur]);
  }
  if (s.size() >= 2) {
    vector<bool> dp1(n + 1, false);
    dp1[0] = true;
    for (int now : s) {
      for (int i = n; i >= 0; i--) {
        if (dp1[i] && i + now < n - 1) {
          dp1[i + now] = true;
          if (!dp[i + now]) {
            x++;
            dp[i + now] = true;
          }
        }
      }
    }
  }
  return tsz[cur] + 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1, n);
  cout << x << endl;
  for (int i = 1; i <= n - 2; i++) {
    if (dp[i]) {
      cout << i << " " << n - 1 - i << endl;
    }
  }
  int l;
  cin >> l;
  return 0;
}
