#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > v[1000001];
vector<pair<int, int> > edge;
int in[100001], out[1000001], ans[1000001];
queue<int> q;
int main() {
  int i, j, n, m, x, y, z, no;
  cin >> n >> m;
  for (i = 1; i <= m; i++) ans[i] = -1;
  edge.push_back(make_pair(-1, -1));
  for (i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    v[x].push_back(make_pair(y, make_pair(z, i)));
    v[y].push_back(make_pair(x, make_pair(z, i)));
    edge.push_back(make_pair(x, y));
    out[x] += z;
    out[y] += z;
  }
  q.push(1);
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (i = 0; i < v[x].size(); i++) {
      y = v[x][i].first;
      z = v[x][i].second.first;
      no = v[x][i].second.second;
      if (ans[no] != -1) continue;
      if (edge[no].first == x && edge[no].second == y)
        ans[no] = 0;
      else
        ans[no] = 1;
      out[y] -= z;
      in[y] += z;
      if (out[y] == in[y] && y != n) q.push(y);
    }
  }
  for (i = 1; i <= m; i++) cout << ans[i] << endl;
  return 0;
}
