#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>> adj;
void input();
long long d[50001][502] = {}, ans[50001], sum = 0;
void dfs(int cur, int prev) {
  d[cur][0] = 1;
  long long sub = 0;
  for (int p : adj[cur])
    if (p != prev) {
      dfs(p, cur);
      for (int i = 1; i <= k; i++) {
        d[cur][i] += d[p][i - 1];
        sub += d[p][i - 1] * d[p][k - 1 - i];
      }
    }
  for (int i = 0; i <= k; i++) ans[cur] += d[cur][i] * d[cur][k - i];
  ans[cur] = (ans[cur] - sub) / 2;
  sum += ans[cur];
}
int main() {
  ios_base::sync_with_stdio(false);
  input();
  dfs(1, 0);
  cout << sum;
}
void input() {
  cin >> n >> k;
  adj.resize(n + 1);
  int x, y;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}
