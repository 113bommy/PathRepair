#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  int a[101];
  cin >> m;
  int total = 0;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    total += a[i];
  }
  int x, y;
  cin >> x >> y;
  int ans = 0;
  int temp = 0;
  if (total > 2 * x || total < 2 * y) {
    for (int i = 0; i < m; i++) {
      temp += a[i];
      if (temp >= x && temp <= y && total - temp <= y && total - temp >= x) {
        ans = i + 2;
        if (ans > m) ans = 0;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
