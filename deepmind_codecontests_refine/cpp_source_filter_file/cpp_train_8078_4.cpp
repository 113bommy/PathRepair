#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 + 5;
int a[MAX];
int b[MAX];
int n, x, y, ans = 0;
void bl(int x1, int y1, int x2, int y2) {
  if ((x1 + x2 <= x) && (y1 <= y) && (y2 <= y)) {
    ans = max(ans, x1 * y1 + x2 * y2);
  }
  if ((y1 + y2 <= y) && (x1 <= x) && (x2 <= x)) {
    ans = max(ans, x1 * y1 + x2 * y2);
  }
}
int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= i; j++) {
      bl(a[i], b[i], a[j], b[j]);
      bl(a[i], b[i], b[j], a[j]);
      bl(b[i], a[i], a[j], b[j]);
      bl(b[i], a[i], b[j], a[j]);
    }
  }
  cout << ans << endl;
  return 0;
}
