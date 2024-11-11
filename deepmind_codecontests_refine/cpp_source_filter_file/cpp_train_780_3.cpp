#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << ((y2 - y1) / 2 + 1) * (x2 - x1 + 1) - (x2 - x1) / 2;
  return 0;
}
