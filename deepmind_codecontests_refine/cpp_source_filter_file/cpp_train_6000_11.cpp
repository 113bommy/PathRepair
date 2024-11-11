#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, a, b, c, d, ans, i, j;
  cin >> a >> b;
  cin >> c >> d;
  if (a != c && b != d) {
    i = abs(a - c);
    j = abs(b - d);
    ans = (2 * (i + j)) + 4;
    cout << ans << endl;
  } else {
    if (a == c) {
      i = abs(b - d);
      i = i + 1;
      ans = (2 * i) + 4;
    } else {
      j = abs(a - c);
      j + j + 1;
      ans = (2 * j) + 4;
    }
    cout << ans << endl;
  }
  return 0;
}
