#include <bits/stdc++.h>
using namespace std;
int beat(int x, int y, int z, int t) {
  if (x > z && y > t)
    return 0;
  else if (x < z && y < t)
    return 2;
  else
    return 1;
}
int main() {
  int a[5], b[5];
  for (int i = 1; i <= 4; i++) cin >> a[i] >> b[i];
  int res[4];
  res[0] = beat(a[1], b[2], a[3], b[4]);
  res[1] = beat(a[2], b[1], a[3], b[4]);
  res[2] = beat(a[1], b[2], a[4], b[3]);
  res[3] = beat(a[2], b[1], a[4], b[3]);
  int R1 = (res[0] > res[2]) ? res[0] : res[2];
  int R2 = (res[1] > res[3]) ? res[1] : res[3];
  int ans = (R1 < R2) ? R1 : R2;
  if (ans == 0)
    cout << "Team 1";
  else if (ans == 1)
    cout << "Draw";
  else if (ans == 2)
    cout << "Team 2";
  return 0;
}
