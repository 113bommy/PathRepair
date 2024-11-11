#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int n, m, k;
  while (t--) {
    cin >> n >> m >> k;
    if (n % 2 == 0 && k % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    if (n % 2 == 0 && k % 2 == 0) {
      if (m % 2 == 0)
        cout << "YES\n";
      else {
        if (k > n * (m - 1) / 2)
          cout << "NO\n";
        else
          cout << "YES\n";
      }
      continue;
    }
    if (m / 2 % 2 == 0) {
      if (k % 2 == 0 && k >= m / 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      if (k % 2 == 1 && k >= m / 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
