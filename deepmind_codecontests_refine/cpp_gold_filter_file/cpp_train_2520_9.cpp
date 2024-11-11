#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793;
double dist(int x1, int y1, int x2, int y2) {
  long long dx = x2 - x1;
  long long dy = y2 - y1;
  return sqrt(dx * dx + dy * dy);
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  double t = 0;
  int px, py;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (i > 0) t += dist(x, y, px, py);
    px = x;
    py = y;
  }
  cout << setprecision(20) << t * k / 50;
}
