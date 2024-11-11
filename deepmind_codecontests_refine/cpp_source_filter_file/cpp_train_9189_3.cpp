#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    if (abs(y1 - y2) == 0) {
      cout << abs(x1 - x2) << endl;
    } else if (abs(x1 - x2) == 0) {
      cout << abs(y1 - y2) << endl;
    } else {
      cout << abs(x1 - y1) + abs(x2 - y2) + 2 << endl;
    }
  }
  return 0;
}
