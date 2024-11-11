#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 || y1 == y2 || x1 == x2 && y1 == y2)
      cout << 1;
    else
      cout << (x2 - x1) * (y2 - y1) + 1;
    cout << endl;
  }
}
