#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, k;
  cin >> w >> h >> k;
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += (w + h - 2) * 2;
    w -= 4;
    h -= 4;
  }
  cout << ans << endl;
  return 0;
}
