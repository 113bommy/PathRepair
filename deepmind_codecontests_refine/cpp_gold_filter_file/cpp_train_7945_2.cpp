#include <bits/stdc++.h>
using namespace std;
int a[202][2];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  bool flag[4];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i][0];
    int y = a[i][1];
    for (int ind = 0; ind <= 3; ind++) flag[ind] = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (flag[0] && flag[1] && flag[2] && flag[3]) break;
      int xx = a[j][0];
      int yy = a[j][1];
      if (!flag[0]) {
        if (x > xx && y == yy) flag[0] = 1;
      }
      if (!flag[1]) {
        if (x < xx && y == yy) flag[1] = 1;
      }
      if (!flag[2]) {
        if (x == xx && y < yy) flag[2] = 1;
      }
      if (!flag[3]) {
        if (x == xx && y > yy) flag[3] = 1;
      }
    }
    if (flag[0] && flag[1] && flag[2] && flag[3]) cnt++;
  }
  cout << cnt << endl;
}
