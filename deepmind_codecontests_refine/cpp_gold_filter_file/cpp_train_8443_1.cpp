#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n][4];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 4; ++j) cin >> a[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (a[j][0] < a[i][0] && a[j][1] < a[i][1] && a[j][2] < a[i][2])
        a[j][3] = INT_MAX;
    }
  int mine = INT_MAX, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i][3] < mine) {
      mine = a[i][3];
      ans = i + 1;
    }
  }
  cout << ans << endl;
}
