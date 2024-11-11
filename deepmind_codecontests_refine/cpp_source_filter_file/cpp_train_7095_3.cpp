#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  bool f = false, s = false;
  while (!f && !s) {
    if (a < n)
      a++;
    else
      a = 1;
    if (b > 0)
      b--;
    else
      b = n;
    if (a == b) {
      cout << "YES" << endl;
      return 0;
    }
    if (a == x || b == y) {
      cout << "NO" << endl;
      return 0;
    }
  }
}
