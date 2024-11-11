#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> n >> x >> y;
    cout << max(1, x + y - n + 1) << ' ' << min(n, x + y - 1) << '\n';
  }
  return 0;
}
