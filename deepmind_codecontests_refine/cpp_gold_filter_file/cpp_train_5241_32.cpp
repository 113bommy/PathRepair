#include <bits/stdc++.h>
using namespace std;
int a[2200][2200], b[2200][2200], v[2200][2200];
vector<pair<int, int> > p;
inline double max(double x, double y) { return x > y ? x : y; }
void clear_noise(int n) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int black_pixel = 0;
      for (int dx = -2; dx <= 2; dx++)
        for (int dy = -2; dy <= 2; dy++)
          black_pixel += a[i + dx + 3][j + dy + 3];
      if (black_pixel >= 12) b[i][j] = 1;
    }
}
void dfs(int x, int y) {
  v[x][y] = 1;
  p.push_back(make_pair(x, y));
  for (int dx = -1; dx <= 1; dx++)
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x + dx;
      int ny = y + dy;
      if (!b[nx][ny] || v[nx][ny]) continue;
      dfs(nx, ny);
    }
}
void classify(const vector<pair<int, int> >& p, int& circle, int& square) {
  int n = p.size();
  if (n <= 150) return;
  int sumx = 0;
  int sumy = 0;
  for (int i = 0; i < n; i++) {
    sumx += p[i].first;
    sumy += p[i].second;
  }
  double avgx = 1.0 * sumx / n;
  double avgy = 1.0 * sumy / n;
  double radius = 0;
  for (int i = 0; i < n; i++)
    radius = max(radius, hypot(p[i].first - avgx, p[i].second - avgy));
  if (radius * radius * 2.5 < n)
    circle++;
  else
    square++;
}
int main() {
  int n, circle_count, square_count;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i + 3][j + 3];
  clear_noise(n);
  circle_count = square_count = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (!b[i][j] || v[i][j]) continue;
      p.clear();
      dfs(i, j);
      classify(p, circle_count, square_count);
    }
  cout << circle_count << " " << square_count << endl;
  return 0;
}
