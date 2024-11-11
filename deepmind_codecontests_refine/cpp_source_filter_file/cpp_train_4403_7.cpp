#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int first, last;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        first = i;
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == 1) {
        last = i;
        break;
      }
    }
    int ans = 0;
    for (int i = first; i <= last; i++) {
      if (a[i] == 0) {
        ans++;
      }
    }
    cout << ans << "\n";
  }
}
