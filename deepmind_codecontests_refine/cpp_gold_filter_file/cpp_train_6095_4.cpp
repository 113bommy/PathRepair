#include <bits/stdc++.h>
using namespace std;
bool flag;
int mp[110][110];
int n, lx, rx, ly, ry;
int main() {
  scanf("%d", &n);
  lx = ly = 0x3f3f3f3f;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%1d", &mp[i][j]);
      if (mp[i][j] != 0) {
        if (i == 1 || j == 1 || i == n || j == n) {
          flag = 1;
        }
        lx = min(lx, i);
        ly = min(ly, j);
        rx = max(rx, i);
        ry = max(ry, j);
      }
    }
  }
  if (flag || lx == 0x3f3f3f3f || ly == 0x3f3f3f3f || rx == 0 || ry == 0 ||
      rx - lx <= 1 || ry - ly <= 1) {
    cout << "No\n";
    return 0;
  }
  if (mp[lx][ly] != 1 || mp[lx][ry] != 1 || mp[rx][ry] != 1 ||
      mp[rx][ly] != 1) {
    cout << "No\n";
    return 0;
  }
  for (int j = ly + 1; j < ry; ++j) {
    if (mp[lx][j] != 2 || mp[rx][j] != 2) {
      cout << "No\n";
      return 0;
    }
  }
  for (int i = lx + 1; i < rx; ++i) {
    if (mp[i][ly] != 2 || mp[i][ry] != 2) {
      cout << "No\n";
      return 0;
    }
  }
  for (int i = lx + 1; i < rx; ++i) {
    for (int j = ly + 1; j < ry; ++j) {
      if (mp[i][j] != 4) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
  return 0;
}
