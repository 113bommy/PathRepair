#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, i, a, b = 0;
    bool f = true;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++) cin >> v[i];
    for (i = 0; i < n; i++) {
      if (v[i] % 2 == 0) {
        cout << 1 << endl << i + 1 << endl;
        f = false;
        break;
      }
      if (v[i] % 2 == 1 && b != 0) {
        cout << 1 << endl << b << ' ' << i + 1 << ' ' << endl;
        f = false;
        break;
      }
      if (v[i] % 2 == 1 && b == 0) b = i + 1;
    }
    if (f) cout << -1 << endl;
  }
}
