#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, n, cx = 0, cy = 0;
  cin >> n;
  vector<bool> visx(100, false), visy(100, false);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    visx[x] = true;
    visy[y] = true;
  }
  for (int i = 0; i < 100; i++) {
    if (visx[i] == true) cx++;
    if (visy[i] == true) cy++;
  }
  cout << min(cx, cy);
  return 0;
}
