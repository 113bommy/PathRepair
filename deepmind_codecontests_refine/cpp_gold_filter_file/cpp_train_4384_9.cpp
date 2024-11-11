#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w, k, ans = 0;
  cin >> h >> w >> k;
  for (int i = 0; i < k; ++i) ans += 2 * h + 2 * (w - 2), h -= 4, w -= 4;
  cout << ans;
}
