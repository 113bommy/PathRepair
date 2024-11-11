#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h;
  cin >> w >> h;
  int i, j;
  long long ans = 0;
  for (i = 2; i <= w; i += 2)
    for (j = 2; j <= h; j += 2) {
      ans += 1ll * (w - i + 1) * (h - j + 1);
    }
  cout << ans << endl;
}
