#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x;
  int y;
};
int main(int argc, char** argv) {
  int n, m, x, y, z, p;
  cin >> n >> m >> x >> y >> z >> p;
  y = y % 2;
  x = x % 4;
  z = z % 4;
  std::vector<Point> a(p);
  for (int i = 0; i < p; ++i) cin >> a[i].x >> a[i].y;
  for (int j = 0; j < x; ++j) {
    for (int i = 0; i < p; ++i) {
      Point tmp;
      tmp.x = a[i].y;
      tmp.y = n - a[i].x + 1;
      a[i] = tmp;
    }
    swap(m, n);
  }
  for (int j = 0; j < y; ++j)
    for (int i = 0; i < p; ++i) {
      Point tmp;
      tmp.x = a[i].x;
      tmp.y = m - a[i].y + 1;
      a[i] = tmp;
    }
  for (int j = 0; j < z; ++j) {
    for (int i = 0; i < p; ++i) {
      Point tmp;
      tmp.x = m - a[i].y + 1;
      tmp.y = a[i].x;
      a[i] = tmp;
    }
    swap(m, n);
  }
  for (int i = 0; i < p; ++i) cout << a[i].x << " " << a[i].y << std::endl;
  return 0;
}
