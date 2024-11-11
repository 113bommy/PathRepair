#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, i, t, c, x;
  long long a[1003], d, e, f;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    d = 0, e = 0, f = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 > 0)
        d++;
      else
        e++;
    }
    if (d == 0)
      cout << "No";
    else {
      for (i = 1; i <= x; i += 2) {
        if (d >= i && e >= n - i) {
          f++;
          break;
        }
      }
      if (f > 0)
        cout << "Yes";
      else
        cout << "No";
    }
    cout << "\n";
  }
  return 0;
}
