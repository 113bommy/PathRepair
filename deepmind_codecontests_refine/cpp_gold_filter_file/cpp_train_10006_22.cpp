#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n;
  cin >> n;
  for (i = 1; n > 0; ++i) {
    cout << 0 << ' ' << i - 1 << "\n";
    if (n > 1) cout << 0 << ' ' << -i << "\n";
    if (n > 2) cout << i << ' ' << 0 << "\n";
    if (n > 3) cout << -i << ' ' << 0 << "\n";
    n -= 4;
  }
}
