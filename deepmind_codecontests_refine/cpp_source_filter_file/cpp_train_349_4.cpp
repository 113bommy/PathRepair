#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
int n, m, us[N][N], u, v;
pair<int, int> pre[N][N];
vector<int> vc[N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> v >> u;
    vc[v].push_back(u);
    vc[u].push_back(v);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      us[i][j] = -1;
    }
  }
  queue<pair<int, int> > q;
  q.push({1, n});
  us[1][n] = 0;
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    if (us[n][1] != -1) break;
    for (auto x : vc[f.first]) {
      for (auto y : vc[f.second]) {
        if (x == y || us[x][y] != -1) continue;
        q.push({x, y});
        pre[x][y] = f;
        us[x][y] = us[f.first][f.second] + 1;
      }
    }
  }
  pair<int, int> p = {n, 1};
  vector<int> v1, v2;
  if (us[n][1] == -1) {
    cout << -1 << endl;
    return 0;
  }
  while (true) {
    v1.push_back(p.first);
    v2.push_back(p.second);
    if (p == make_pair(1, n)) break;
    p = pre[p.first][p.second];
  }
  reverse(v1.begin(), v1.end());
  reverse(v2.begin(), v2.end());
  cout << v1.size() << endl;
  for (auto i : v1) cout << i << ' ';
  cout << endl;
  for (auto i : v2) cout << i << ' ';
  cout << endl;
}
