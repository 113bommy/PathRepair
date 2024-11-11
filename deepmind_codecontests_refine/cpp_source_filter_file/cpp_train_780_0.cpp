#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << (x2 - x1) / 2LL * (y2 - y1 + 1) + (y2 - y1 + (x1 & x2) + 1) / 2
       << endl;
  return 0;
}
