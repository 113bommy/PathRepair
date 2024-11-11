#include <bits/stdc++.h>
using namespace std;
vector<bool> vis;
vector<int> v[200001];
int parent[200001];
vector<int> ans;
void bfs(int n, int p) {
  int h;
  queue<int> q;
  q.push(n);
  vis[n] = true;
  parent[1] = 0;
  while (!q.empty()) {
    h = q.front();
    q.pop();
    for (auto i = v[h].begin(); i != v[h].end(); i++) {
      if (!vis[*i]) {
        q.push(*i);
        parent[*i] = h;
        vis[*i] = true;
      }
    }
  }
  int temp = p;
  while (temp >= 1) {
    ans.push_back(temp);
    temp = parent[temp];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, n, edge, a, b;
  cin >> n;
  vis.assign(n, false);
  for (i = 2; i <= n; i++) {
    cin >> a;
    v[a].push_back(i);
  }
  bfs(1, n);
  for (i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}
