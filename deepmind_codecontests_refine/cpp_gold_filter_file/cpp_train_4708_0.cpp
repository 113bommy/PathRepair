#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(0);
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      if (x % 2) {
        a++;
      } else {
        b++;
      }
    }
    if (n % 2) {
      if (a) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (a > 0 & b > 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
