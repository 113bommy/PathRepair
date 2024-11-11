#include <bits/stdc++.h>
using namespace std;
int n, m, T;
vector<pair<int, int> > v[5001], vi[5001];
int d[5001][5001];
void out(int x, int y) {
  if (x > 1) {
    for (int i = 0; i < vi[y].size(); i++) {
      int xi = vi[y][i].first;
      int yi = vi[y][i].second;
      if (d[x][y] == d[x - 1][xi] + yi) {
        out(x - 1, xi);
        break;
      }
    }
  }
  cout << y + 1 << " ";
}
int main() {
  cin >> n >> m >> T;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    v[x].push_back(make_pair(y, z));
    vi[y].push_back(make_pair(x, z));
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) d[i][j] = 1e9 + 7;
  }
  d[1][0] = 0;
  for (int i = 1; i < n; i++) {
    for (int x = 0; x < n; x++) {
      for (int k = 0; k < v[x].size(); k++) {
        int xi = v[x][k].first;
        int yi = v[x][k].second;
        d[i + 1][xi] = min(d[i + 1][xi], d[i][x] + yi);
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    if (d[i][n - 1] <= T) {
      cout << i << "\n";
      out(i, n - 1);
      break;
    }
  }
  return 0;
}
