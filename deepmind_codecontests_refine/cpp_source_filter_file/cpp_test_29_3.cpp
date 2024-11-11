#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long c1 = 0, c0 = 0;
    long long k = 1;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1)
        c1++;
      else if (a[i] == 0)
        c0++;
    }
    int ans = c1 * (k << c0);
    cout << ans << endl;
  }
  return 0;
}
