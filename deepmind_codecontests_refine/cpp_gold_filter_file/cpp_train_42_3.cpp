#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> X[N];
vector<int> Y[N];
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> points;
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    X[x].push_back(y);
    Y[y].push_back(x);
    points.push_back({x, y});
    s.insert({x, y});
  }
  for (int i = 0; i < N; i++) {
    sort(X[i].begin(), X[i].end());
    sort(Y[i].begin(), Y[i].end());
  }
  long long res = 0;
  for (auto p : points) {
    int x = upper_bound(Y[p.second].begin(), Y[p.second].end(), p.first) -
            Y[p.second].begin();
    int y = upper_bound(X[p.first].begin(), X[p.first].end(), p.second) -
            X[p.first].begin();
    while (x < ((int)Y[p.second].size()) && y < ((int)X[p.first].size())) {
      if (Y[p.second][x] - p.first == X[p.first][y] - p.second) {
        res += s.count({Y[p.second][x], X[p.first][y]});
        x++, y++;
      } else if (Y[p.second][x] - p.first > X[p.first][y] - p.second) {
        y++;
      } else {
        x++;
      }
    }
  }
  cout << res << '\n';
  return 0;
}
