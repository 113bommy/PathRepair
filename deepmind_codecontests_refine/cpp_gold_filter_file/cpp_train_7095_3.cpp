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
    b--;
    if (a == n + 1) a = 1;
    if (b == 0) b = n;
  }
  if (f) {
    cout << "NO\n";
  }
}
