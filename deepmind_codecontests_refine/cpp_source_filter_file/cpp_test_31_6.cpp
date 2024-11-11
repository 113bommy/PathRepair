#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 0)
        cout << a[i - 1] << " ";
      else
        cout << -1 * a[i + 1] << " ";
    }
    cout << endl;
  } else {
    for (int i = 1; i + 3 <= n; i++) {
      if (i % 2 == 0)
        cout << a[i - 1] << " ";
      else
        cout << -1 * a[i + 1] << " ";
    }
    int x, y;
    if (a[n - 2] + a[n - 1] + a[n] == 0) {
      cout << 1 << " " << 1 << " " << 1 << endl;
      return;
    }
    if (a[n - 2] + a[n - 1] != 0) {
      x = a[n - 2] + a[n - 1];
      y = a[n];
      cout << y << " " << y << " "
           << " " << -1 * x << endl;
    } else if (a[n - 2] + a[n] != 0) {
      x = a[n - 2] + a[n];
      y = a[n - 1];
      cout << -1 * x << " " << y << " " << y << endl;
    } else {
      x = a[n - 1] + a[n];
      y = a[n - 2];
      cout << y << " " << -1 * x << " " << y << endl;
    }
  }
}
int main() {
  int T = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  };
  return 0;
}
