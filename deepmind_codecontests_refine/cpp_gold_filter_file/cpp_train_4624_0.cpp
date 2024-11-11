#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  int dist() const { return abs(x) + abs(y); }
  bool operator<(const point& p) const { return dist() < p.dist(); }
};
string dir(int x, int y) {
  if (x > 0)
    return "R";
  else if (x < 0)
    return "L";
  if (y > 0)
    return "U";
  else if (y < 0)
    return "D";
  assert(false);
}
void go(int x, int y) {
  if (x != 0) printf("1 %d %s\n", abs(x), dir(x, 0).c_str());
  if (y != 0) printf("1 %d %s\n", abs(y), dir(0, y).c_str());
  puts("2");
  if (y != 0) printf("1 %d %s\n", abs(y), dir(0, -y).c_str());
  if (x != 0) printf("1 %d %s\n", abs(x), dir(-x, 0).c_str());
  puts("3");
}
int main() {
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  sort(p.begin(), p.end());
  int ans = 2 * n;
  for (int i = 0; i < n; i++) {
    ans += 2 * (2 - (p[i].x == 0) - (p[i].y == 0));
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    go(p[i].x, p[i].y);
  }
  return 0;
}
