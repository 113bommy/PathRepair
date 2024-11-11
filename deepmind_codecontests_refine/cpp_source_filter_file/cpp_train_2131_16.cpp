#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, d, a, t = 0, ans = 0;
  cin >> n;
  for (i = n + 1; i <= 1000000000; i++) {
    d = i;
    if (d < 0) d = d * -1;
    while (d > 0) {
      a = d % 10;
      if (a == 8) {
        t = 1;
        break;
      }
      d = d / 10;
    }
    if (t == 1) {
      break;
    }
    ans++;
  }
  cout << ans + 1;
  return 0;
}
