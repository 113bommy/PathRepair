#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int main() {
  int x, z;
  cin >> x >> z;
  int b, c, d, k;
  int f, h;
  int ans = 0;
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < z * 2; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < z * 2; j += 2) {
      if (a[i][j] == 1 && a[i][j + 1] == 1) {
        ans++;
      } else if (a[i][j] == 0 && a[i][j + 1] == 1)
        ans++;
      else if (a[i][j] == 1 && a[i][j + 1] == 0)
        ans++;
    }
  }
  cout << ans;
  return 0;
}
