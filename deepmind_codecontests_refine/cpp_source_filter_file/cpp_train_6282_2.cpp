#include <bits/stdc++.h>
using namespace std;
int hcf(int x, int y) {
  if (x < 0) x = -x;
  if (y < 0) y = -y;
  int X = max(x, y);
  int Y = min(x, y);
  while (X % Y != 0) {
    int r = X % Y;
    X = Y;
    Y = r;
  }
  return Y;
}
int main() {
  int n, m;
  cin >> n >> m;
  int ar[105], br[105];
  for (int i = 0; i <= n; i++) cin >> ar[i];
  for (int i = 0; i <= m; i++) cin >> br[i];
  if (n > m) {
    if (ar[0] * br[0] > 0)
      cout << "Infinity";
    else
      cout << "-Infinity";
  } else if (n == m) {
    int h = hcf(ar[0], br[0]);
    ar[0] = ar[0] / h;
    br[0] = br[0] / h;
    if (ar[0] * br[0] > 0)
      cout << abs(ar[0]) << "/" << abs(br[0]);
    else
      cout << "-" << abs(ar[0]) << "/" << abs(br[0]);
  } else
    cout << 0 << "/" << br[0];
}
