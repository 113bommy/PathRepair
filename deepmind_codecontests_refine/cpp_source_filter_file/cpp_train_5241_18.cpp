#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1);
int n;
bool initial[2000][2000];
bool blur[2000][2000];
pair<int, int> direction[8] = {
    make_pair(1, 0),  make_pair(1, 1),   make_pair(0, 1),  make_pair(-1, 1),
    make_pair(-1, 0), make_pair(-1, -1), make_pair(0, -1), make_pair(1, -1)};
pair<int, int> operator+(pair<int, int> l, pair<int, int> r) {
  return make_pair(l.first + r.first, l.second + r.second);
}
bool valid(pair<int, int> pos) {
  return pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < n;
}
int circle(int x, int y) {
  vector<pair<int, int> > front(1, make_pair(x, y));
  blur[x][y] = 0;
  for (size_t i = 0; i < front.size(); i++)
    for (auto m : direction) {
      auto next = front[i] + m;
      if (valid(next) && blur[next.first][next.second]) {
        front.push_back(next);
        blur[next.first][next.second] = 0;
      }
    }
  pair<double, double> centre = make_pair(0, 0);
  for (auto c : front)
    centre = make_pair(centre.first + 1.0 * c.first / front.size(),
                       centre.second + 1.0 * c.second / front.size());
  double radius = 0;
  for (auto c : front)
    radius = max(radius, sqrt(pow(c.first - centre.first, 2.0) +
                              pow(c.second - centre.second, 2.0)));
  radius += 0.5;
  if (radius < 6) return 0;
  return 1 + front.size() > (pow(radius, 2) * 2 + pow(radius, 2) * pi) / 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> initial[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      for (int di = -2; di <= 2; di++)
        for (int dj = -2; dj <= 2; dj++)
          if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < n &&
              initial[i + di][j + dj])
            cnt++;
      blur[i][j] = (cnt > 5 * 5 / 2);
    }
  int squares = 0, circles = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (blur[i][j]) {
        int ret = circle(i, j);
        if (ret == 1) squares++;
        if (ret == 2) circles++;
      }
  cout << circles << ' ' << squares << '\n';
  return 0;
}
