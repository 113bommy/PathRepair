#include <bits/stdc++.h>
using namespace std;
const int MAN = 8;
struct Point {
  int x;
  int y;
  Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
  Point operator-(const Point& b) { return Point(x - b.x, y - b.y); }
  int operator*(const Point& b) { return x * b.x + y * b.y; }
  int dis2() { return x * x + y * y; }
};
Point a[MAN];
int chk[MAN];
Point d[MAN];
int seq[MAN];
bool Verify() {
  int dis = (d[0] - d[1]).dis2();
  for (int i = 0; i < 4; ++i) {
    if ((d[(i + 1) % 4] - d[i]).dis2() != dis) return false;
  }
  for (int i = 0; i < 4; ++i) {
    int j = (i + 1) % 4;
    int k = (i + 2) % 4;
    if ((d[j] - d[i]) * (d[k] - d[j]) != 0) {
      return false;
    }
  }
  for (int i = 0; i < 4; ++i) {
    int j = (i + 1) % 4 + 4;
    int k = (i + 2) % 4 + 4;
    if ((d[j] - d[i + 4]) * (d[k] - d[j + 4]) != 0) {
      return false;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < 4; ++i) {
    if (i) cout << " ";
    cout << seq[i];
  }
  cout << endl;
  for (int i = 4; i < 8; ++i) {
    if (i > 4) cout << " ";
    cout << seq[i];
  }
  cout << endl;
  return true;
}
bool dfs(int x) {
  if (x == 8) {
    return Verify();
  }
  bool ans = false;
  for (int i = 0; i < 8; ++i) {
    if (chk[i] == 0) {
      seq[x] = i + 1;
      d[x] = a[i];
      chk[i] = 1;
      ans = dfs(x + 1);
      chk[i] = 0;
      if (ans) return ans;
    }
  }
  return false;
}
int main() {
  int n;
  for (int i = 0; i < 8; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  memset(chk, 0, sizeof(chk));
  if (!dfs(0)) {
    cout << "NO" << endl;
  }
  return 0;
}
