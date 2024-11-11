#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << max(fabs(x1 - x2), fabs(y1 - y2));
  return 0;
}
