#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, x, y, i, j;
  bool mark = false;
  cin >> n >> a >> x >> b >> y;
  if (a > x) x += n;
  if (b < y) b += n;
  for (i = 1; i <= 1000; i++) {
    a++;
    b--;
    if (a == x || b == y) break;
    if (a % n == b % n) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
