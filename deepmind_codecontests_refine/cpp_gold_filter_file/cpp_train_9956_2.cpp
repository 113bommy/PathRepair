#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, cnt = 1;
  cin >> a >> b >> c;
  if (a % b == 0) {
    if (c == 0)
      cout << 1 << '\n';
    else
      cout << -1 << '\n';
    return 0;
  } else {
    int mod = a % b;
    if (a < b) a *= 10;
    while (cnt <= 100000) {
      mod = mod * 10;
      if (mod / b == c) {
        cout << cnt << '\n';
        return 0;
      }
      mod = mod % b;
      cnt++;
    }
  }
  cout << -1 << '\n';
}
