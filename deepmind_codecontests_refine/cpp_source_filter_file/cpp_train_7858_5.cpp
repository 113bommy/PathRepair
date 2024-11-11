#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, cnt = 1, ans = -1;
  cin >> n;
  cin >> x;
  for (int i = 1; i < n; i++) {
    cin >> y;
    if (y >= x)
      cnt++;
    else
      cnt = 1;
    ans = max(ans, cnt);
    x = y;
  }
  cout << ans;
  return 0;
}
