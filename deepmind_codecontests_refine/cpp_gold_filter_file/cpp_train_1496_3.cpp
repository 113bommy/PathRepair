#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, m;
bool vis[2 * N];
vector<int> adj[2 * N];
vector<int> order;
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = true;
  for (auto e : adj[x]) {
    dfs(e);
  }
  order.push_back(x);
}
int cnt;
int comp[2 * N];
void scc(int x) {
  if (vis[x]) return;
  vis[x] = true;
  comp[x] = cnt;
  for (auto e : adj[x]) {
    scc(e);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    x--, y--;
    if (t == 0) {
      adj[x + n].push_back(y);
      adj[y + n].push_back(x);
      adj[y].push_back(x + n);
      adj[x].push_back(y + n);
    } else {
      adj[y].push_back(x);
      adj[x].push_back(y);
      adj[x + n].push_back(y + n);
      adj[y + n].push_back(x + n);
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    vis[i] = false;
  }
  cnt = 0;
  reverse(order.begin(), order.end());
  for (auto e : order) {
    if (!vis[e]) {
      scc(e);
      cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (comp[i] == comp[i + n]) {
      cout << "Impossible\n";
      return 0;
    }
  }
  vector<int> trues;
  for (int i = 0; i < n; i++) {
    if (comp[i] > comp[i + n]) {
      trues.push_back(i + 1);
    }
  }
  cout << (int)trues.size() << '\n';
  for (auto e : trues) {
    cout << e << ' ';
  }
  cout << '\n';
  return 0;
}
