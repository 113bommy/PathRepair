#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  int f = 1;
  while (true) {
    if (a == b) {
      f = 0;
      cout << "YES\n";
      break;
    }
    if (a == x || y == b) {
      break;
    }
    a++;
    y--;
    if (a == n + 1) a = 1;
    if (y == 0) y = n;
  }
  if (f) {
    cout << "NO\n";
  }
}
