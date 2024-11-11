#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t) {
    int x, y;
    cin >> x >> y;
    if (2 * x <= y)
      cout << x << " " << 2 * x << endl;
    else
      cout << -1 << " " << -1 << endl;
    t--;
  }
  return 0;
}
