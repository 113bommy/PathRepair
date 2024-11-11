#include <bits/stdc++.h>
using namespace std;
double dist(int x1, int y1, int x2, int y2) {
  int xd = x2 - x1;
  int yd = y2 - y1;
  return sqrt((xd * xd) + (yd * yd));
}
struct circle {
  int x, y, r;
  bool isInside(int x1, int y1) {
    double dis = dist(x, y, x1, y1);
    if (dis < (double)r)
      return true;
    else
      return false;
  }
};
int x1, x2, y_, y2, n;
std::vector<circle> arr;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> x1 >> y_ >> x2 >> y2;
  cin >> n;
  if (x1 > x2) swap(x1, x2);
  if (y_ > y2) swap(y_, y2);
  vector<vector<bool> > visited(x2 - x1 + 1, vector<bool>(y2 - y_ + 1, false));
  int x, y, r;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    cin >> x >> y >> r;
    circle c;
    c.x = x;
    c.y = y;
    c.r = r;
    arr.push_back(c);
  }
  int count = 0;
  int total = 0;
  for (__typeof(x2 + 1) i = (x1) - ((x1) > (x2 + 1));
       i != (x2 + 1) - ((x1) > (x2 + 1)); i += 1 - 2 * ((x1) > (x2 + 1))) {
    for (__typeof(n) k = (0) - ((0) > (n)); k != (n) - ((0) > (n));
         k += 1 - 2 * ((0) > (n))) {
      if (arr[k].isInside(i, y_) && (!visited[i - x1][0])) {
        count++;
        visited[i - x1][0] = true;
      }
      if (arr[k].isInside(i, y2) && (!visited[i - x1][y2 - y_])) {
        count++;
        visited[i - x1][y2 - y_] = true;
      }
    }
  }
  for (__typeof(y2) i = (y_ + 1) - ((y_ + 1) > (y2));
       i != (y2) - ((y_ + 1) > (y2)); i += 1 - 2 * ((y_ + 1) > (y2))) {
    for (__typeof(n) k = (0) - ((0) > (n)); k != (n) - ((0) > (n));
         k += 1 - 2 * ((0) > (n))) {
      if (arr[k].isInside(x1, i) && (!visited[0][i - y_])) {
        count++;
        visited[0][i - y_] = true;
      }
      if (arr[k].isInside(x2, i) && (!visited[x2 - x1][i - y_])) {
        count++;
        visited[x2 - x1][i - y_] = true;
      }
    }
  }
  total = 2 * (x2 - x1 + 1) + 2 * (y2 - y_ - 1);
  int ans = total - count;
  cout << ans;
  return 0;
}
