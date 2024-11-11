#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  if (n == 1) {
    if (y * y >= x)
      cout << y << endl;
    else
      cout << -1 << endl;
    return 0;
  }
  if (y - (n - 1) <= 0)
    cout << -10 << endl;
  else {
    y -= (n - 1);
    x -= (n - 1);
    if (y * y >= x) {
      for (int(i) = (0); (i) < int(n - 1); ++(i)) cout << 1 << endl;
      cout << y << endl;
    } else
      cout << -1 << endl;
  }
  cin.sync();
  cin.get();
  return 0;
}
