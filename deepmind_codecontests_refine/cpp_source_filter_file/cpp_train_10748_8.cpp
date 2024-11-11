#include <bits/stdc++.h>
using namespace std;
int offset[] = {1, 0, -1, 0, 1};
const int MXN = 2e5 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, n;
    cin >> n >> x;
    long long int even = 0, odd = 0;
    for (long long int i = 0; i < n; i++) {
      long long int temp;
      cin >> temp;
      if (temp & 1)
        odd++;
      else
        even++;
    }
    if (odd == 0)
      cout << "NO\n";
    else {
      odd--;
      x--;
      if (even >= x)
        cout << "YES\n";
      else {
        if (even == 0 && x % 2 == 0)
          cout << "NO\n";
        else {
          long long int req = x - even;
          req = (req + 1) / 2 * 2;
          x -= req;
          if (req > odd || x < 0)
            cout << "NO\n";
          else
            cout << "YES\n";
        }
      }
    }
  }
  return 0;
}
