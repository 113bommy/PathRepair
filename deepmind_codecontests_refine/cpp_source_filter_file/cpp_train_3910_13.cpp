#include <bits/stdc++.h>
using namespace std;
bool a[200001] = {0};
vector<int> adj[200001];
int sum[200001] = {0};
int ans = 0;
int k;
void dfs(int s, int par) {
  if (a[s]) {
    sum[s]++;
  }
  for (auto it = adj[s].begin(); it != adj[s].end(); ++it) {
    if (*it != par) {
      dfs(*it, s);
      sum[s] += sum[*it];
    }
  }
  if (par) {
    ans = ans + min(sum[s], 2 * k - sum[s]);
  }
}
int main() {
  int n, i, x, y;
  cin >> n >> k;
  for (i = 0; i < 2 * k; i++) {
    cin >> x;
    a[x] = 1;
  }
  for (i = 0; i < n - 1; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  cout << ans;
  return 0;
}
