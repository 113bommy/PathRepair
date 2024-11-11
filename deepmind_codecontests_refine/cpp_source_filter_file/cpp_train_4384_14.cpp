#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h;
  cin >> w >> h;
  int k;
  cin >> k;
  int ans = 0;
  while (k && w > 1 && h > 1) {
    ans += 2 * (w + h) - 4;
    w -= 2;
    h -= 2;
    --k;
  }
  cout << ans << endl;
}
