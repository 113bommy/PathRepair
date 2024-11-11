#include <bits/stdc++.h>
using namespace std;
int t, a[4][3], d[8], f[8];
bool valid(int x, int y, int z) {
  int a11 = a[1][1] - y - z, a12 = a[1][2] - d[3] - d[2] + y + z;
  int a21 = a[2][1] - x - z, a22 = a[2][2] - d[5] - d[2] + x + z;
  int a31 = a[3][1] - x - y, a32 = a[3][2] - d[5] - d[3] + x + y;
  if (a11 < 0 || a12 < 0 || a21 < 0 || a22 < 0 || a31 < 0 || a32 < 0)
    return false;
  int f1 = min({a11, a21, a31});
  int f2 = min({a12, a22, a32});
  if (d[1] > f1 + f2) return false;
  int ans1 = min(f1, d[1]);
  int ans4 = min(d[4], a11 - ans1);
  if (a12 < d[1] + d[4] - ans1 - ans4) return false;
  int ans6 = min(d[6], a21 - ans1);
  if (a22 < d[1] + d[6] - ans1 - ans6) return false;
  int ans7 = min(d[7], a31 - ans1);
  if (a32 < d[1] + d[7] - ans1 - ans7) return false;
  cout << ans1 << " " << z << " " << y << " " << ans4 << " " << x << " " << ans6
       << " " << ans7 << endl;
  return true;
}
int main() {
  cin >> t;
  while (t--) {
    for (int i = 1; i <= 2; i++)
      for (int j = 1; j <= 3; j++) cin >> a[j][i];
    for (int i = 1; i <= 7; i++) cin >> d[i];
    bool ok = false, tag = true;
    if (d[1] + d[2] + d[3] + d[4] > a[1][1] + a[1][2]) tag = false;
    if (d[1] + d[2] + d[5] + d[6] > a[2][1] + a[2][2]) tag = false;
    if (d[1] + d[3] + d[5] + d[7] > a[3][1] + a[3][2]) tag = false;
    for (int i = 0; i <= d[5] && tag; i++)
      for (int j = 0; j <= d[3] && tag; j++)
        for (int k = 0; k <= d[2] && tag; k++)
          if (valid(i, j, k)) ok = true, tag = false;
    if (!ok) cout << "-1";
  }
}
