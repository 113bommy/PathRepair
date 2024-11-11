#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2, a, b, c, n, ans = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    if (a * x1 + b * y1 + c > 0 && a * x2 + b * y2 + c < 0) {
      ans++;
    }
    if (a * x1 + b * y1 + c < 0 && a * x2 + b * y2 + c > 0) {
      ans++;
    }
  }
  cout << ans << endl;
}
