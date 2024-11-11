#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, x, y, c = 0;
  bool a[1001][1001];
  memset(a, false, sizeof(a));
  cin >> n >> m >> k;
  for (int i = 1; i < k + 1; i++) {
    cin >> x >> y;
    a[x][y] = true;
    if (a[x + 1][y] == true) {
      if (a[x][y + 1] == 1 && a[x + 1][y + 1] == 1) {
        if (c == 0) c = i;
      } else if (a[x][y - 1] == 1 && a[x + 1][y - 1] == 1) {
        if (c == 0) c = i;
      }
    }
    if (a[x - 1][y] == true) {
      if (a[x][y + 1] == 1 && a[x + 1][y - 1] == 1) {
        if (c == 0) c = i;
      } else if (a[x][y - 1] == 1 && a[x - 1][y - 1] == 1) {
        if (c == 0) c = i;
      }
    }
  }
  cout << c;
}
