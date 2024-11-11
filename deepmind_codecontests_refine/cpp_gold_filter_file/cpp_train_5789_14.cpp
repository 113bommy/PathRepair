#include <bits/stdc++.h>
using namespace std;
int light[4][4];
int main() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) cin >> light[i][j];
  }
  bool flag = false;
  for (int i = 0; i < 4; ++i) {
    if (light[i][3] == 1) {
      if ((light[i][0] | light[i][1] | light[i][2] | light[(i + 2) % 4][1]) |
          light[(i + 1) % 4][0] | light[(i + 3) % 4][2]) {
        flag = true;
        break;
      }
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
