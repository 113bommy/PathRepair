#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    if (x <= 14) {
      cout << "NO\n";
      continue;
    }
    if (x % 14 == 1 || x % 14 == 2 || x % 14 == 3 || x % 14 == 4 ||
        x % 14 == 5 || x % 14 == 6) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
