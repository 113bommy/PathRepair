#include <bits/stdc++.h>
using namespace std;
const double kPi = acos(-1.0);
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
int col[1700][1700];
char was[1700][1700];
vector<int> answer;
double kEps = 1e-1;
double Sqr(double x) { return x * x; }
bool IsRay(double x, double y, double cx, double cy, double sx, double sy) {
  int n = 0;
  for (int i = 0; i < 8; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && ny >= 0 && col[nx][ny] == 1) {
      ++n;
    }
  }
  return Sqr(x - cx) + Sqr(y - cy) > Sqr(sx + 4) && n <= 3;
}
int Solve(int x, int y) {
  double sx = 0, sy = 0;
  int q = 0;
  queue<pair<int, int> > Q;
  Q.push(pair<int, int>(x, y));
  was[x][y] = 1;
  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();
    ++q;
    int x = cur.first, y = cur.second;
    sx += x;
    sy += y;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || col[nx][ny] == 0 || was[nx][ny] == 1) {
        continue;
      }
      Q.push(pair<int, int>(nx, ny));
      was[nx][ny] = 1;
    }
  }
  double cx = sx / q, cy = sy / q;
  cerr << cx << " " << cy << endl;
  sy = 0;
  sx = 1000000;
  int qq = 0;
  Q.push(pair<int, int>(x, y));
  was[x][y] = 2;
  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();
    int x = cur.first, y = cur.second;
    bool side = false;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || col[nx][ny] == 0) {
        side = true;
      }
      if (nx < 0 || ny < 0 || col[nx][ny] == 0 || was[nx][ny] == 2) {
        continue;
      }
      Q.push(pair<int, int>(nx, ny));
      was[nx][ny] = 2;
    }
    if (side) {
      sx = min(sx, sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y)));
      sy = max(sy, sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y)));
    }
  }
  cerr << sx << " " << sy << endl;
  vector<double> angles;
  Q.push(pair<int, int>(x, y));
  was[x][y] = 10;
  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();
    int x = cur.first, y = cur.second;
    if (IsRay(x, y, cx, cy, sx, sy)) {
      angles.push_back(atan2(y - cy, x - cx));
    }
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || col[nx][ny] == 0 || was[nx][ny] == 10) {
        continue;
      }
      Q.push(pair<int, int>(nx, ny));
      was[nx][ny] = 10;
    }
  }
  cerr << angles.size() << endl;
  int ret = 0;
  sort(angles.begin(), angles.end());
  if (angles.empty()) {
    return 0;
  }
  if (angles.size() == 1) {
    return 1;
  }
  ret = 1;
  for (int i = 1; i < angles.size(); ++i) {
    if (angles[i] - angles[i - 1] > kEps) {
      ++ret;
    }
  }
  if (angles[0] - angles.back() + 2 * kPi < kEps) {
    --ret;
  }
  return ret;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> col[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (col[i][j] == 1 && !was[i][j]) {
        answer.push_back(Solve(i, j));
      }
    }
  }
  sort(answer.begin(), answer.end());
  cout << answer.size() << endl;
  for (int i = 0; i < answer.size(); ++i) {
    cout << answer[i] << " ";
  }
  return 0;
}
