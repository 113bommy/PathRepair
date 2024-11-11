#include <bits/stdc++.h>
using namespace std;
const long long N = (1e5) + 322;
const long long INF = (long long)(1e12);
const long long mod = 998244353;
const double eps = 1e-9;
int n, k, deg[N], dp[N], par[N];
vector<int> v[N];
queue<int> q;
void dfs(int x, int p = -1) {
  int cnt = 0;
  for (auto it : v[x]) {
    if (it == p) continue;
    cnt++;
    if (dp[it] + 1 != dp[x]) {
      cout << "No";
      exit(0);
    }
    dfs(it, p);
  }
  if ((int)(v[x].size()) == 1) return;
  if (cnt < 3) {
    cout << "No";
    exit(0);
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    if ((int)(v[i].size()) == 1) {
      q.push(i);
      dp[i] = 0;
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto it : v[x]) {
      if (dp[it] == -1) {
        dp[it] = dp[x] + 1;
        q.push(it);
      }
    }
  }
  int root = 0;
  for (int i = 1; i <= n; ++i) {
    if (dp[i] > k) {
      cout << "No";
      return 0;
    }
    if (dp[i] == k) {
      root = i;
    }
  }
  dfs(root);
  cout << "Yes";
  return 0;
}
