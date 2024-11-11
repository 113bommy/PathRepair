#include <bits/stdc++.h>
using namespace std;
const int Z = (int)3e3 + 111;
const int N = (int)3e5 + 111;
const int INF = (int)1e9 + 111;
const int MOD = (int)1e9 + 7;
vector<int> g[N];
bool used[N];
int cnt[N], ans;
int dfs(int v) {
  used[v] = 1;
  for (int to : g[v])
    if (!used[to])
      if (!dfs(to)) cnt[v] = 1 - cnt[v];
  return cnt[v];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (n % 2) {
    cout << -1;
    return 0;
  }
  dfs(1);
  for (int i = 1; i <= n; i++) ans += cnt[i];
  cout << --ans;
  return 0;
}
