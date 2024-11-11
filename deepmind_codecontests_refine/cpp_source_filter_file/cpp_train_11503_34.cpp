#include <bits/stdc++.h>
using namespace std;
int rocks[100010][2];
int n, m;
bool pos(int h) {
  for (int i = 0; i <= m; i++) {
    if (rocks[i][0] + abs(rocks[i][1] - h) <=
        rocks[i + 1][0] - abs(rocks[i + 1][1] - h))
      return true;
  }
  return false;
}
int main() {
  int d, h;
  cin >> n >> m;
  int l = 0, high = 300000010, mid;
  for (int i = 1; i <= m; i++) {
    cin >> rocks[i][0] >> rocks[i][1];
    if (rocks[i][1] > l) l = rocks[i][1];
    if (i != 1 &&
        rocks[i][0] - rocks[i - 1][0] < abs(rocks[i][1] - rocks[i - 1][1])) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  rocks[0][0] = 1;
  rocks[0][1] = rocks[1][1] + rocks[1][0];
  rocks[m + 1][0] = n;
  rocks[m + 1][1] = rocks[m][1] + (n - rocks[m][0]);
  while (l < high) {
    mid = l + (high - l + 1) / 2;
    if (pos(mid))
      l = mid;
    else
      high = mid - 1;
  }
  cout << l << endl;
  return 0;
}
