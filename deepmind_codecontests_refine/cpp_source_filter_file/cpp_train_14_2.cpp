#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int main() {
  int n;
  cin >> n;
  adj = vector<vector<int>>(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  string ans = "YES\n";
  int flag = 1;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() <= 2) {
      ans = "NO\n";
      flag = 0;
      break;
    }
  }
  cout << ans;
  return 0;
}
