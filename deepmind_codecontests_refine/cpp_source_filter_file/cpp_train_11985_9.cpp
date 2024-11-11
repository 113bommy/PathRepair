#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;
vector<int> adj[N];
vector<pair<int, int> > que[N];
int n, level[N];
long long check[N], ans[N];
void dfs(int x, int p) {
  for (int i = 0; i < adj[x].size(); i++) {
    if (adj[x][i] != p) {
      level[adj[x][i]] = level[x] + 1;
      dfs(adj[x][i], x);
    }
  }
}
void solve(int x, int p, long long sum) {
  sum += check[level[x]];
  for (int i = 0; i < que[x].size(); i++) {
    sum += que[x][i].second;
    check[min(level[x] + que[x][i].first + 1, n - 1)] -= que[x][i].second;
  }
  ans[x] = sum;
  for (int i = 0; i < adj[x].size(); i++) {
    if (adj[x][i] != p) {
      solve(adj[x][i], x, sum);
    }
  }
  for (int i = 0; i < que[x].size(); i++) {
    check[min(level[x] + que[x][i].first + 1, n - 1)] += que[x][i].second;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j, k, q, l;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> j >> k;
    adj[j].push_back(k);
    adj[k].push_back(j);
  }
  cin >> q;
  for (i = 1; i <= q; i++) {
    cin >> j >> k >> l;
    que[j].push_back({k, l});
  }
  dfs(1, 1);
  solve(1, 1, 0);
  for (i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
