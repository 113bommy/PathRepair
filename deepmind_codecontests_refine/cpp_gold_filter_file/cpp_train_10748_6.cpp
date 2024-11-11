#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, x;
    cin >> n >> x;
    long long int odd = 0, even = 0;
    for (long long int i = 0; i < n; i++) {
      long long int xx;
      cin >> xx;
      if (xx % 2)
        odd++;
      else
        even++;
    }
    if (x == 1) {
      if (odd) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if (x == n) {
      if (odd % 2 == 0) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      if (odd && even) {
        cout << "YES\n";
      } else if (odd == 0) {
        cout << "NO\n";
      } else {
        if (x % 2 == 0) {
          cout << "NO\n";
        } else {
          cout << "YES\n";
        }
      }
    }
  }
}
