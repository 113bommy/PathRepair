#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] != a[i + 1]) {
        ok = false;
        break;
      }
    }
    if (ok == false)
      cout << 1 << endl;
    else
      cout << n << endl;
  }
  return 0;
}
