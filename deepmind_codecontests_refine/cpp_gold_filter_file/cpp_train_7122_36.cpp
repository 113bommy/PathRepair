#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, pair<int, int> > > edge;
vector<int> mark, mark2, mark3;
int ans = 0;
int main() {
  scanf("%d%d", &n, &m);
  if (m == 0) {
    cout << ans << endl;
  } else {
    mark = vector<int>(n, 0);
    mark2 = vector<int>(n, 0);
    mark3 = vector<int>(n, 0);
    int x, y, w;
    for (int k = 0; k < m; k++) {
      cin >> x >> y >> w;
      edge.push_back(make_pair(w, pair<int, int>(x - 1, y - 1)));
    }
    for (int i = 0; i < edge.size(); i++) {
      x = edge[i].second.first;
      y = edge[i].second.second;
      w = edge[i].first;
      mark2[x] += w;
      mark3[x] = mark2[x] - mark[x];
      mark[y] += w;
    }
    for (int i = 0; i < edge.size(); i++) {
      x = edge[i].second.first;
      mark3[x] = mark2[x] - mark[x];
    }
    for (int i = 0; i < n; i++) {
      if (mark3[i] > 0) ans += mark3[i];
    }
    cout << ans << endl;
  }
  return 0;
}
