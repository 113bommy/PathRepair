#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d, min1, min2;
  cin >> n;
  for (int i = 0; i < 4; i++) {
    cin >> a >> b >> c >> d;
    min1 = min(a, b);
    min2 = min(c, d);
    if (min1 + min2 <= n) {
      cout << i + 1 << " " << min1 << " " << n - min1;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
