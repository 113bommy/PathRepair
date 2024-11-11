#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, x, y;
  cin >> n >> a >> x >> b >> y;
  bool flag = false;
  while (a != x && b != y) {
    a = a % n + 1;
    if (b - 1 > 0)
      b = b = -1;
    else
      b = n;
    if (a == b) flag = true;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
