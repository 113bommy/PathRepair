#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, i;
    cin >> n >> k;
    if (n % 2) {
      if (n < k || (n - k) % 2)
        cout << "NO\n";
      else {
        cout << "YES\n" << n - k + 1 << " ";
        for (i = 1; i < k; i++) cout << 1 << " ";
        cout << "\n";
      }
    } else {
      if (n < 2 * k || (n - 2 * k) % 2) {
        if (n < k || (n - k) % 2)
          cout << "NO\n";
        else {
          cout << "YES\n" << n - k + 1 << " ";
          for (i = 1; i < k; i++) cout << 1 << " ";
          cout << "\n";
        }
      } else {
        cout << "YES\n" << n - 2 * k + 2 << " ";
        for (i = 1; i < k; i++) cout << 2 << " ";
        cout << "\n";
      }
    }
  }
}
