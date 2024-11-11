#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  while (cin >> x >> y) {
    if (x == 0 && y == 0) {
      cout << "0" << endl;
      continue;
    }
    int n = max(abs(x), abs(y)), sum = (n - 1) * 4 + 3;
    if (-n <= x && x < n && y == n)
      --sum;
    else if (x == n && -(n - 1) < y && y <= n)
      sum -= 2;
    else if (-(n - 1) < x && x <= n && y == -n + 1)
      sum -= 3;
    else if (-n < x && x <= n + 1 && y == -n)
      ++sum;
    cout << sum << endl;
  }
  return 0;
}
