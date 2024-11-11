#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  Point(int x0, int y0) : x(x0), y(y0) {}
  Point() : x(0), y(0) {}
};
int t;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
int n, m;
long long maxx;
int d[100005][4];
int a[100005], h[100005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> h[i];
  }
  memset(d, 0, sizeof(d));
  d[0][0] = 1;
  d[0][1] = 0;
  if (a[1] - a[0] > h[1])
    d[0][2] = 1;
  else
    d[0][2] = 0;
  int res = 0;
  for (int i = 1; i < n; i++) {
    int dis = a[i] - a[i - 1];
    if (h[i] < dis) d[i][0] = max(d[i - 1][0] + 1, d[i - 1][1] + 1);
    if (h[i] + h[i - 1] < dis) d[i][0] = max(d[i][0], d[i - 1][2] + 1);
    d[i][1] = max(d[i - 1][0], d[i - 1][1]);
    if (h[i - 1] < dis) d[i][1] = max(d[i][1], d[i - 1][2]);
    if (h[i] < a[i + 1] - a[i] || i == n - 1)
      d[i][2] = max(d[i - 1][0] + 1, d[i - 1][1] + 1);
    if (h[i - 1] < dis) d[i][2] = max(d[i][2], d[i - 1][2] + 1);
    res = max(res, max(d[i][0], max(d[i][1], d[i][2])));
  }
  cout << res;
}
