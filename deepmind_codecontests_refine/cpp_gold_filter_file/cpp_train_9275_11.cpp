#include <bits/stdc++.h>
using namespace std;
int dp[100005][3], a[100005];
vector<int> adj[100005];
int fun(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (j == 0) {
    for (auto it : adj[i]) {
      if (fun(it, 1 - j)) return dp[i][j] = 1;
    }
    return dp[i][j] = 0;
  }
  if (j == 1) {
    for (auto it : adj[i]) {
      if (fun(it, 1 - j) == 0) return dp[i][j] = 0;
    }
    return dp[i][j] = 1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + a[i]; j <= n; j += a[i]) {
      if (a[j] > a[i]) adj[i].push_back(j);
    }
    for (int j = i - a[i]; j >= 1; j -= a[i]) {
      if (a[j] > a[i]) adj[i].push_back(j);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (fun(i, 0))
      cout << "A";
    else
      cout << "B";
  }
  cout << endl;
  return 0;
}
