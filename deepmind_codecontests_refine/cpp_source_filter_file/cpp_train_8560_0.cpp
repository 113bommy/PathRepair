#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, n, m;
    cin >> x >> n >> m;
    int flag = 0;
    while (n-- && x > 0) {
      x = x / 2;
      x = x + 10;
    }
    while (m-- && x > 0) {
      x = x - 10;
    }
    if (x > 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
