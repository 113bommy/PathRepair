#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int rtn = 0, cur = 0;
    while (d > a[cur] * cur && cur < n) {
      rtn += a[cur];
      d -= a[cur] * cur;
      cur++;
    }
    while (d - cur > 0 && cur < n) {
      rtn++;
      d -= cur;
    }
    cout << rtn << "\n";
  }
  return 0;
}
