#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  int c = 0;
  while (a != x and b != y) {
    a++, b--;
    if (a == n + 1) a = 1;
    if (b == 0) b = n;
    if (a == b) {
      c = 1;
      break;
    }
  }
  ((c == 1) ? cout << "YES" : cout << "NO");
}
