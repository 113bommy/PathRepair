#include <bits/stdc++.h>
using namespace std;
long long q, h, w, a[610][610];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> q;
  long long i, j, val;
  while (q--) {
    cin >> h >> w;
    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++) cin >> a[i][j];
    val = 0;
    for (j = 1; j <= w; j++)
      val += (a[h / 2][j] - a[h / 2 + 1][j]) * (a[h / 2][j] - a[h / 2 + 1][j]);
    if (val <= 100 * w)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
