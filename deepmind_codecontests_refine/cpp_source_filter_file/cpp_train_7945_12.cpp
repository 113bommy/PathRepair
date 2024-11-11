#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  ;
  int ans = 0;
  int x[1100], y[1100];
  bool right, left, up, down;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (x[j] > x[i] && y[j] == y[i]) right = true;
      if (x[j] < x[i] && y[j] == y[i]) left = true;
      if (x[j] == x[i] && y[j] > y[i]) down = true;
      if (x[j] == x[i] && y[j] > y[i]) up = true;
    }
    if (up && down && left && right) ans++;
    up = false;
    down = false;
    left = false;
    right = false;
  }
  cout << ans << endl;
  return 0;
}
