#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h;
  cin >> w >> h;
  long long ans = 0;
  for (int x = 0; x <= w; x++) {
    for (int y = 0; y <= h; y++) {
      ans += (((h - y) / 2) * min(w - x, x - 0));
    }
  }
  cout << ans << '\n';
  return 0;
}
