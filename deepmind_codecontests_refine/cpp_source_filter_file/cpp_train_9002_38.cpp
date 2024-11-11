#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x1, y1, x2, y2;
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    ans += ((x2 - x2 + 1) * (y2 - y1 + 1));
  }
  cout << ans << endl;
  return 0;
}
