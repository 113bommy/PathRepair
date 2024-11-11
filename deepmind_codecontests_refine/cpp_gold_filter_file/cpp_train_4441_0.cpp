#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100010];
int d[100010];
void dfs(int s, int l) {
  d[l]++;
  for (auto f : adj[s]) {
    dfs(f, l + 1);
  }
}
signed main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a;
    cin >> a;
    adj[a - 1].push_back(i);
  }
  dfs(0, 0);
  int ans = 0;
  for (int i = 0; i < 100010; ++i) {
    ans += d[i] & 1;
  }
  cout << ans << endl;
  return 0;
}
