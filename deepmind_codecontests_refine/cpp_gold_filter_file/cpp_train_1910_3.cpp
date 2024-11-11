#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long int x, y, count = 1;
} points[250];
vector<vector<Point> > qq(1000001);
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> points[i].x >> points[i].y;
    if (points[i].x <= n) {
      if (qq[points[i].x].size() == 0)
        qq[points[i].x].push_back(points[i]);
      else
        qq[points[i].x][0].count++;
    }
  }
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      if (points[i].x != points[j].x && points[i].y != points[j].y &&
          ((abs(points[i].x - points[j].x) * points[i].y) %
               abs(points[i].y - points[j].y) ==
           0)) {
        long long x =
            points[i].x - (points[i].y * (points[i].x - points[j].x)) /
                              (points[i].y - points[j].y);
        if (x > 0 && x <= n) {
          bool found = false;
          for (unsigned int q = 0; q < qq[x].size(); q++) {
            if (((qq[x][q].x - x) * points[i].y) ==
                (qq[x][q].y * (points[i].x - x))) {
              found = true;
              if (qq[x][q].x == points[i].x) qq[x][q].count++;
              break;
            }
          }
          if (!found) {
            points[i].count = 2;
            qq[x].push_back(points[i]);
          }
        }
      }
    }
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    long long int max_count = 1;
    for (unsigned int j = 0; j < qq[i].size(); j++) {
      max_count = max(max_count, qq[i][j].count);
    }
    ans += max_count;
  }
  cout << ans << endl;
}
