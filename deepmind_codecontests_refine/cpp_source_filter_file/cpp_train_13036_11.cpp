#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int ans = 0;
    if (a[2]) {
      --a[2];
      ++ans;
    }
    if (a[1]) {
      --a[1];
      ++ans;
    }
    if (a[0]) {
      --a[0];
      ++ans;
    }
    if (a[2] && a[1]) {
      --a[2];
      --a[1];
      ++ans;
    }
    if (a[2] && a[0]) {
      --a[2];
      --a[0];
      ++ans;
    }
    if (a[1] && a[0]) {
      --a[1];
      --a[0];
      ++ans;
    }
    if (a[2] && a[1] && a[0]) {
      ++ans;
    }
    cout << ans;
  }
}
