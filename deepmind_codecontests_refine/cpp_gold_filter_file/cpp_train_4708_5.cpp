#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a, x = 0, y = 0, i;
    for (i = 0; i < n; i++) {
      cin >> a;
      if (a % 2 == 0)
        x++;
      else
        y++;
    }
    if (y == 0)
      cout << "NO\n";
    else if (x == 0 && n % 2 == 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
