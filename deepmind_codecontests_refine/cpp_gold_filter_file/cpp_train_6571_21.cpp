#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
using ll = int64_t;
const int MAX_N = 3;
const int MAX_X = 1000;
pair<int, int> points[MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int d(int x0, int y0, int x1, int y1) { return abs(x0 - x1) + abs(y0 - y1); }
void print_path(int x0, int y0, int x1, int y1, bool print_first) {
  if (print_first) cout << x0 << " " << y0 << "\n";
  while (x0 != x1 || y0 != y1) {
    for (int k = 0; k < 4; k++) {
      int nx = x0 + dx[k];
      int ny = y0 + dy[k];
      if (d(nx, ny, x1, y1) < d(x0, y0, x1, y1)) {
        x0 = nx;
        y0 = ny;
        break;
      }
    }
    cout << x0 << " " << y0 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < MAX_N; i++) {
    int x, y;
    cin >> x >> y;
    points[i] = {x, y};
  }
  int result = std::numeric_limits<int>::max();
  int start_x = -1, start_y = -1;
  for (int x = 0; x <= MAX_X; x++) {
    for (int y = 0; y <= MAX_X; y++) {
      int current_result = 0;
      for (int i = 0; i < 3; i++) {
        auto p = points[i];
        current_result += d(x, y, p.first, p.second) + 1;
      }
      current_result -= (MAX_N - 1);
      if (current_result < result) {
        result = current_result;
        start_x = x;
        start_y = y;
      }
    }
  }
  cout << result << endl;
  for (int i = 0; i < MAX_N; i++) {
    print_path(start_x, start_y, points[i].first, points[i].second, i == 0);
  }
  return 0;
}
