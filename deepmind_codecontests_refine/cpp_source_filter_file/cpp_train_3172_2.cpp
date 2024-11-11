#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;
  int minx = x;
  int miny = y;
  int maxx = x;
  int maxy = y;
  n--;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
  }
  int m = max((maxx - minx), (maxy - miny));
  cout << m * m << endl;
  return 0;
}
