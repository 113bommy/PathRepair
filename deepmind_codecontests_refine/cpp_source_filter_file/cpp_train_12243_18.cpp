#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, f;
  char c;
  cin >> a >> c >> b;
  int ans = 0;
  for (int i = a;; i++) {
    if (i > 23) i = 0;
    for (; b < 60; b++) {
      if (a % 10 == b / 10 && a / 10 == b % 10) {
        f = 1;
        break;
      }
      ans++;
    }
    b = 0;
    if (f == 1) break;
  }
  cout << ans << endl;
  return 0;
}
