#include <bits/stdc++.h>
using namespace std;
int main() {
  long long r, x, y, x1, y1;
  cin >> r >> x >> y >> x1 >> y1;
  float d = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
  cout << ceil(1.0 * d / (2 * r));
}
