#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, x1[N], x2[N], Y1[N], Y2[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x1[i] >> x2[i] >> Y1[i] >> Y2[i];
    double sx = 0, sy = 0, sm = 0;
    for (int j = i; j > 1; --j) {
      int d = abs(x1[j] - x2[j]);
      int m = d * d * d;
      double cx = (x1[j] + x2[j]) / 2.0, cy = (Y1[j] + Y2[j]) / 2.0;
      sx += cx * m;
      sy += cy * m;
      sm += m;
      if (sx / sm > max(x1[j - 1], x2[j - 1]) ||
          sx / sm < min(x1[j - 1], x2[j - 1]) ||
          sy / sm > max(Y1[j - 1], Y2[j - 1]) ||
          sy / sm < min(Y1[j - 1], Y2[j - 1])) {
        cout << i - 1;
        return 0;
      }
    }
  }
  cout << n;
}
