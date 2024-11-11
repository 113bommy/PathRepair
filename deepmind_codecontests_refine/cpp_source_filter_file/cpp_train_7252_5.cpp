#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, x[2][4], y[2][4];
  pair<int, int> p[2][4];
  for (j = 0; j < 2; j++) {
    for (i = 0; i < 4; i++) {
      cin >> x[j][i] >> y[j][i];
      p[j][i] = {x[j][i], y[j][i]};
    }
  }
  sort(p[0], p[0] + 4);
  sort(p[1], p[1] + 4);
  int a = p[1][0].first + p[1][0].second, b = p[1][2].first + p[1][2].second;
  int c = p[1][1].second - p[1][1].first, d = p[1][2].second - p[1][1].first;
  set<pair<int, int>> s;
  for (i = -100; i <= 100; i++) {
    for (j = -100; j <= 100; j++) {
      if (i + j > a && i + j < b && i - j > c && i - j < d) {
        s.insert({i, j});
      }
    }
  }
  a = p[0][0].first, b = p[0][0].second, c = p[0][3].first, d = p[0][3].second;
  for (i = a; i <= c; i++) {
    for (j = b; j <= d; j++) {
      pair<int, int> q = {i, j};
      if (s.count(q)) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
