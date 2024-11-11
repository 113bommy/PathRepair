#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b;
  if (a <= b || a == 9 && b == 1) {
    c = b - a;
    if (a == 9 && b == 1)
      cout << 9 << " " << 10 << endl;
    else if (c > 1)
      cout << -1 << endl;
    else if (c == 1)
      cout << (b * 100) - 1 << " " << b * 100 << endl;
    else
      cout << b * 100 << " " << (b * 100) + 1 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
