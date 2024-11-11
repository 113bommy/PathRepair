#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x1, x2, y1, y2;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> x2 >> y1 >> y2;
    ans += (x2 - x1 + 1) * (y2 - y1 + 1);
  }
  cout << ans;
  return 0;
}
