#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, ans = 0, pw = 1;
  cin >> a >> b;
  while (a || b) {
    c = (3 + (b % 3 - a % 3)) % 3;
    ans += c * pw;
    pw *= 3;
    a /= 3;
    b /= 3;
  }
  cout << ans << endl;
  return 0;
}
