#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << ((y2 - y1) / 2 + 1) * (x2 - x1 + 1) - (x2 - x1) / 2;
  return 0;
}
