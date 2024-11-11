#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], d[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    d[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] < d[i + 1])
        d[i] = a[i];
      else
        d[i] = d[i + 1];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == d[i]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
