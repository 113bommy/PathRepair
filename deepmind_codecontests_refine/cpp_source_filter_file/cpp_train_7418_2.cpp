#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n <= 30) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      if (n == 36 || n == 40 || n == 44) {
        cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 1 << endl;
      } else {
        cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << endl;
      }
    }
  }
  return 0;
};
