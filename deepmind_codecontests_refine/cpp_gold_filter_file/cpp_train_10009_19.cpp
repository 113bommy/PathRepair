#include <bits/stdc++.h>
using namespace std;
int const N = 1005;
int n, m, neww[N][N], matrix[N][N], maxx[N], cnt = 1, last = -1;
vector<vector<int> > col(N);
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    pair<int, int> p[m + 5];
    cnt = 1;
    for (int y = 0; y < m; y++) {
      cin >> matrix[i][y];
      p[y] = {matrix[i][y], y};
    }
    sort(p, p + m);
    for (int z = 0; z < m; z++) {
      if (z && p[z].first != p[z - 1].first) cnt++;
      neww[i][p[z].second] = cnt;
    }
    maxx[i] = cnt;
  }
  for (int i = 0; i < m; i++) {
    unordered_map<int, bool> mp;
    for (int y = 0; y < n; y++) {
      if (!mp[matrix[y][i]]) col[i].push_back(matrix[y][i]);
      mp[matrix[y][i]] = 1;
    }
    sort(col[i].begin(), col[i].end());
    for (int z = 0; z < n; z++) {
      int idx = upper_bound(col[i].begin(), col[i].end(), matrix[z][i]) -
                col[i].begin();
      int les = 0, more = 0, tmp = 0;
      more = (col[i].size() - idx);
      les = col[i].size() - more - 1;
      if (les >= neww[z][i]) tmp = (les - neww[z][i] + 1);
      neww[z][i] = max(more + neww[z][i] + tmp, tmp + maxx[z]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int y = 0; y < m; y++) cout << neww[i][y] << " ";
    cout << endl;
  }
  return 0;
}
