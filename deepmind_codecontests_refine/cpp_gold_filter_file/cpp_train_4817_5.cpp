#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    long long int n, i, x, s = 0, mx = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> x;
      s += x;
      mx = max(x, mx);
    }
    if (mx > (s / 2)) {
      cout << "T\n";
    } else {
      if (s % 2) {
        cout << "T\n";
      } else {
        cout << "HL\n";
      }
    }
  }
  return 0;
}
