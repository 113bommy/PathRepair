#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  cin >> a >> b >> c >> d;
  int tem = 0x3f3f3f3f;
  if (d >= a || d >= b) {
    return cout << -1, 0;
  }
  for (int i = c; i <= c + c; i++) {
    if (i <= d + d && i >= d) {
      tem = i;
      break;
    }
  }
  if (tem == 0x3f3f3f3f) {
    return cout << -1, 0;
  } else {
    cout << a + a << '\n' << b + b << '\n' << tem << '\n';
  }
  return 0;
}
