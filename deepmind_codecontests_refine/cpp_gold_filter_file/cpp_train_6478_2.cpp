#include <bits/stdc++.h>
using namespace std;
int r[103], b[103];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> r[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  int flag[102] = {0};
  for (int i = 1; i <= n; ++i) {
    if (b[i] == 1 && r[i] == 1) {
      flag[i] = 1;
    }
  }
  int ans = 0, ans2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (r[i] == 1 && !flag[i]) {
      ans++;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (b[i] == 1 && !flag[i]) {
      ans2++;
    }
  }
  if (ans == 0) {
    cout << -1 << endl;
  } else {
    if (ans > ans2) {
      cout << 1 << endl;
    } else {
      cout << ans2 / ans + 1 << endl;
    }
  }
  return 0;
}
