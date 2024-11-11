#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int r, h;
  cin >> r >> h;
  int ans = 0;
  if (h >= r) {
    ans += (h / r) * 2;
    h = h % r;
  }
  double needfor3 = (sqrt(3) / 2.0) * (r) + r;
  if (h + r >= needfor3 - 0.00001) {
    ans += 3;
  } else {
    if (h >= (r / 2.0) - 0.00001) {
      ans += 2;
    } else {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
