#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  double x, y;
  cin >> x >> y;
  x = y * log(x) - x * log(y);
  cout << (x > 0 ? ">" : x != 0 ? "<" : "=");
  return 0;
}
