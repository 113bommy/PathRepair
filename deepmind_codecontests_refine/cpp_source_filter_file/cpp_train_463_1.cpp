#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r;
  int x, y;
  int nx, ny;
  cin >> r >> x >> y >> nx >> ny;
  double d = sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
  cout << ceil(d / (2.0 * r)) << '\n';
  return 0;
}
