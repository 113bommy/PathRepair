#include <bits/stdc++.h>
using namespace std;
map<int, int> in;
vector<int> vis;
map<int, vector<int>> hmap;
void bfs(int v) {
  queue<int> q;
  vis[v] = 1;
  q.push(v);
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    for (auto i : hmap[p]) {
      if (vis[i] == -1) {
        q.push(i);
        vis[i] = 1;
        cout << p + 1 << " " << i + 1 << endl;
      }
    }
  }
}
void solve() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  vis = vector<int>(n, -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    a--, b--;
    hmap[a].push_back(b);
    hmap[b].push_back(a);
    in[a]++;
    in[b]++;
  }
  int mxin = -1, mxdg = -1;
  for (int i = 0; i < n; i++) {
    if (in[i] > mxdg) {
      mxin = i;
      mxdg = in[i];
    }
  }
  bfs(mxin);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
