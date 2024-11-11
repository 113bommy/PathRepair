#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n, m, u, v, k, cnt, cnt2;
vector<int> g[N];
priority_queue<int, vector<int>, greater<int> > q;
bool visited[N];
int mx = INT_MIN;
const int fx[9] = {0, 0, 1, -1, 0, 1, 1, -1, -1};
const int fy[9] = {1, -1, 0, 0, 0, 1, -1, 1, -1};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
bool cycle;
void dfs(int x, int parent) {
  if (visited[x]) {
    cycle = true;
    return;
  }
  visited[x] = true;
  for (auto i : g[x]) {
    if (i == parent) {
      continue;
    }
    dfs(i, x);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i, 0);
      if (!cycle) {
        cnt++;
      }
      cycle = false;
    }
  }
  cout << cnt;
}
