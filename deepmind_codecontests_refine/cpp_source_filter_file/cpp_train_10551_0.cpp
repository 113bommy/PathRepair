#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    int ans = 0;
    while (a != 1 && b != 1 && c != 1) {
      ans += (a + b + c - 3) * 2;
      a--;
      b--;
      c--;
    }
    if (a == 1) {
      ans += b * c;
    } else if (b == 1) {
      ans += a * c;
    } else if (c == 1) {
      ans += b * c;
    }
    cout << ans << endl;
  }
}
