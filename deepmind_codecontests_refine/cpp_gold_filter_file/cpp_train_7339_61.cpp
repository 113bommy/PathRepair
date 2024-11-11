#include <bits/stdc++.h>
using namespace std;
const int inf = 100;
int main() {
  int n = 8;
  char g[n][n];
  vector<pair<int, int> > b, w;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'B') b.push_back(make_pair(i, j));
      if (g[i][j] == 'W') w.push_back(make_pair(i, j));
    }
  }
  int minb = inf, minw = inf;
  int x, y;
  int tmp = 0;
  for (int i = 0; i < b.size(); i++) {
    tmp = 0;
    for (x = b[i].first + 1, y = b[i].second; x < n; x++) {
      if (g[x][y] == 'B') {
        tmp = 0;
      } else if (g[x][y] == 'W') {
        tmp = inf;
        break;
      } else
        tmp++;
    }
    minb = min(minb, tmp);
  }
  for (int i = 0; i < w.size(); i++) {
    tmp = 0;
    for (x = w[i].first - 1, y = w[i].second; x >= 0; x--) {
      if (g[x][y] == 'W') {
        tmp = 0;
      } else if (g[x][y] == 'B') {
        tmp = inf;
        break;
      } else
        tmp++;
    }
    minw = min(minw, tmp);
  }
  if (minb < minw) {
    printf("B\n");
  } else
    printf("A\n");
  return 0;
}
