#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, b;
  cin >> m >> b;
  long long ans = 0;
  int x = 0;
  while (x <= b * m) {
    int y = b - x / m;
    ans = max(ans, (long long)(x + 1) * (y + 1) * (x + y) / 2);
    x += m;
  }
  cout << ans;
  return 0;
}
