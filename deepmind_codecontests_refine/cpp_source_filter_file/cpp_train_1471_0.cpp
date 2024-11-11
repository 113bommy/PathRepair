#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
struct Point {
  long long x, y;
} P[maxn];
int main() {
  int n;
  cin >> n;
  long long xmax = -0x3f3f3f3f, xmin = 0x3f3f3f3f, ymax = -0x3f3f3f3f,
            ymin = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    cin >> P[i].x >> P[i].y;
    xmax = max(xmax, P[i].x);
    xmin = min(xmin, P[i].x);
    ymax = max(ymax, P[i].y);
    ymin = min(ymin, P[i].y);
  }
  long long ans = -1;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, 2 * (max(P[i].x - xmin, xmax - P[i].x) +
                        max(P[i].y - ymin, ymax - P[i].y)));
  }
  cout << ans << " ";
  ans = 2 * (xmax - xmin + ymax - ymin);
  for (int i = 4; i < n; i++) cout << ans << " ";
  cout << ans << endl;
}
