#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a[10], ans = 0;
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }
    sort(a, a + 3);
    if (a[0]) {
      a[0]--;
      ans++;
    }
    if (a[1]) {
      a[1]--;
      ans++;
    }
    if (a[2]) {
      a[2]--;
      ans++;
    }
    if (a[0] && a[2]) {
      ans++;
      a[0]--;
      a[2]--;
    }
    if (a[2] && a[1]) {
      a[2]--;
      a[1]--;
      ans++;
    }
    if (a[1] && a[0]) {
      a[1]--;
      a[0]--;
      ans++;
    }
    if (a[0] and a[1] and a[2]) ans++;
    cout << ans << endl;
  }
  return 0;
}
