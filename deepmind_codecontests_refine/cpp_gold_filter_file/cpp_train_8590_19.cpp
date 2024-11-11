#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, h, d;
  cin >> n >> d >> h;
  if (n - 1 < h || n - 1 < d || d < h || d > 2 * h) {
    cout << -1;
    return 0;
  }
  if (d == 1 && h == d && n != 2) {
    cout << -1;
    return 0;
  }
  int k = d - h;
  int l = 0;
  int yolo = h;
  for (int i = 2; i <= n; ++i) {
    if (h > 0) {
      cout << i - 1 << " " << i << "\n";
      h--;
      d--;
    } else if (d > 0) {
      if (l == 0) {
        cout << 1 << " " << i << "\n";
        l++;
        d--;
      } else {
        cout << i - 1 << " " << i << "\n";
        l++;
        d--;
      }
    } else {
      cout << yolo << " " << i << "\n";
    }
  }
  return 0;
}
