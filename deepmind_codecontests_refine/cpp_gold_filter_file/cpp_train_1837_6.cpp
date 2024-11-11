#include <bits/stdc++.h>
using namespace std;
int k;
double n, m, r;
double mox[]{0, 0, -1, 1};
double moy[]{1, -1, 0, 0};
map<int, int> visited[100003];
priority_queue<pair<double, pair<double, double> > > q;
bool valid(double x, double y) {
  return (x >= 1 && x <= n && y >= 1 && y <= m);
}
double solve(double x, double y) {
  double sx = min(x, r) + min(n - x + 1, r) - 1;
  double sy = min(y, r) + min(m - y + 1, r) - 1;
  return (sy - r + 1) * (sx - r + 1);
}
int main() {
  scanf("%lf %lf %lf %d", &n, &m, &r, &k);
  double midx = floor((n + 1) / 2), midy = floor((m + 1) / 2);
  q.push({solve(midx, midy), {midx, midy}});
  visited[(int)midx][(int)midy] = 1;
  double tot = 0;
  int cnt = 0;
  while (1) {
    pair<double, pair<double, double> > curr = q.top();
    q.pop();
    double x = curr.second.first;
    double y = curr.second.second;
    double cost = curr.first;
    tot += cost;
    cnt++;
    if (cnt == k) break;
    for (int i = 0; i < 4; i++) {
      double _x = x + mox[i];
      double _y = y + moy[i];
      if (valid(_x, _y) && !visited[(int)_x][(int)_y]) {
        q.push({solve(_x, _y), {_x, _y}});
        visited[(int)_x][(int)_y] = 1;
      }
    }
  }
  printf("%0.9lf\n", tot / ((n - r + 1) * (m - r + 1)));
  return 0;
}
