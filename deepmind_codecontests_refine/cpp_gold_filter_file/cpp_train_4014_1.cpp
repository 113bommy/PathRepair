#include <bits/stdc++.h>
using namespace std;
int x, y;
int d;
int n;
pair<int, int> co[205];
bool ok(int cx, int cy) {
  cx -= 205;
  cy -= 205;
  int dsq = cx * cx + cy * cy;
  return dsq <= d * d;
}
int res[205 * 4][205 * 4][4];
bool calc(int cx, int cy, int st) {
  if (res[cx][cy][st] != -1) return res[cx][cy][st];
  if (!ok(cx, cy)) {
    res[cx][cy][st] = 1;
    return true;
  }
  for (int i = (1); i <= (signed)(n); i++) {
    int nx = cx + co[i].first, ny = cy + co[i].second;
    if (!calc(nx, ny, 3 ^ st)) {
      res[cx][cy][st] = 1;
      return true;
    }
  }
  if ((st & 1 == 0) && !calc(cy, cx, (st | 1) ^ 3)) {
    res[cx][cy][st] = 1;
    return true;
  }
  res[cx][cy][st] = 0;
  return false;
}
int main() {
  cin >> x >> y >> n >> d;
  x += 205;
  y += 205;
  for (int i = (1); i <= (signed)(n); i++) {
    cin >> co[i].first >> co[i].second;
  }
  memset(res, -1, sizeof res);
  if (calc(x, y, 0)) {
    cout << "Anton\n";
  } else {
    cout << "Dasha\n";
  }
  return 0;
}
