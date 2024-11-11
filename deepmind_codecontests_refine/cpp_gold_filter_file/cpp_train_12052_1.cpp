#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}
const int M = 1e9 + 7, N = 2e5 + 5;
vector<int> g[N], typ(N);
vector<vector<int>> cost(N, vector<int>(105, -1));
vector<int> vis(N, false);
queue<int> q;
void bfs(int i) {
  while (!q.empty()) {
    int te = q.front();
    q.pop();
    for (auto x : g[te]) {
      if (!vis[x]) {
        vis[x] = true;
        q.push(x);
        cost[x][i] = cost[te][i] + 1;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    for (int i = 1; i < n + 1; i++) cin >> typ[i];
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    for (int i = 1; i < k + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (typ[j] == i) {
          q.push(j);
          cost[j][i] = 0;
          vis[j] = true;
        }
      }
      bfs(i);
      for (int j = 1; j < n + 1; j++) vis[j] = false;
    }
    for (int i = 1; i < n + 1; i++)
      sort(cost[i].begin() + 1, cost[i].begin() + k + 1);
    for (int i = 1; i < n + 1; i++) {
      long long ans = 0;
      for (int j = 1; j < s + 1; j++) {
        ans += cost[i][j];
      }
      cout << ans << " ";
    }
  }
}
