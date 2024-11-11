#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int n1 = n - k + 1;
    if (n1 > 0 && n1 % 2 != 0) {
      cout << "YES"
           << "\n";
      for (int i = 1; i < k; ++i) {
        cout << "1 ";
      }
      cout << n1 << "\n";
      continue;
    }
    int n2 = n - 2 * (k - 1);
    if (n2 > 0 && n2 % 2 == 0) {
      cout << "YES"
           << "\n";
      for (int i = 1; i < k; ++i) {
        cout << "2 ";
      }
      cout << n2 << "\n";
      continue;
    }
    cout << "NO"
         << "\n";
  }
  return 0;
}
