#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n];
    bool ans = false;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] - a[i] == 1) {
        ans = true;
      }
    }
    if (ans)
      cout << "2"
           << "\n";
    else {
      cout << "1"
           << "\n";
    }
  }
}
