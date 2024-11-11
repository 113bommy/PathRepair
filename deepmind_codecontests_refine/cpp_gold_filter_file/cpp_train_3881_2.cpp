#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
} points[200005];
bool operator<(point p1, point p2) {
  if (p1.x == p2.x) return p1.y < p2.y;
  return p1.x < p2.x;
}
set<pair<int, int> > ans;
int main() {
  int n, k, i, j;
  cin >> n >> k;
  for ((i) = 0; (i) < (int)(n); (i)++) {
    int a, b;
    scanf("%d%d", &a, &b);
    points[i].x = 2 * a;
    points[i].y = 2 * b;
  }
  sort(points, points + n);
  if (k >= n) {
    cout << "-1" << endl;
    return 0;
  }
  for ((i) = 0; (i) < (int)(k + 1); (i)++)
    for ((j) = 0; (j) < (int)(k + 1); (j)++) {
      int xx = (points[i].x + points[n - 1 - j].x) / 2;
      int yy = (points[i].y + points[n - 1 - j].y) / 2;
      int cnt = 0;
      int a = 0, b = n - 1;
      while (a <= b) {
        if ((points[a].x + points[b].x) / 2 > xx) {
          b--;
          cnt++;
        } else if ((points[a].x + points[b].x) / 2 < xx) {
          a++;
          cnt++;
        } else if ((points[a].y + points[b].y) / 2 > yy) {
          b--;
          cnt++;
        } else if ((points[a].y + points[b].y) / 2 < yy) {
          a++;
          cnt++;
        } else {
          a++;
          b--;
        }
      }
      if (cnt <= k) {
        ans.insert(make_pair(xx, yy));
      }
    }
  printf("%d\n", ((int)(ans).size()));
  for (__typeof((ans).begin()) itr = (ans).begin(); itr != (ans).end(); itr++) {
    printf("%.2f %.2f\n", (double)(itr->first) / 2, (double)(itr->second) / 2);
  }
  cin.get();
  cin.get();
  return 0;
}
