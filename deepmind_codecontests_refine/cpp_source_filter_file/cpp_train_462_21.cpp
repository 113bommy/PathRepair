#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, a, b, c, d;
  cin >> r >> a >> b >> c >> d;
  cout << ceil(sqrt((a - c) * (a - c) + (b - d) * (b - d)) / (2.0 * r));
  return 0;
}
