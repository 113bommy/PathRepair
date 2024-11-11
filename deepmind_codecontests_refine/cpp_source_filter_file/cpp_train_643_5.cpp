#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sx, sy;
  cin >> n >> sx >> sy;
  int x[n], y[n];
  int q1 = 0, q2 = 0, q3 = 0, q4 = 0, py1 = 0, px1 = 0, py2 = 0, nx2 = 0,
      ny3 = 0, nx3 = 0, ny4 = 0, px4 = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    if (x[i] > sx)
      q1++;
    else if (x[i] < sx)
      q2++;
    if (y[i] > sy)
      q3++;
    else if (y[i] < sy)
      q4++;
  }
  int Max = max(max(q1, q2), max(q3, q4));
  cout << Max << "\n";
  if (Max == q1)
    cout << sx + 1 << " " << sy << "\n";
  else if (Max == q2)
    cout << sx - 1 << " " << sy << "\n";
  else if (Max == q3)
    cout << sx << " " << sy + 1 << "\n";
  else if (Max == q1)
    cout << sx << " " << sy - 1 << "\n";
  return 0;
}
