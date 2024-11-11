#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k == 2) {
    if (n <= 4)
      cout << -1;
    else {
      cout << n - 1 << "\n";
      for (int i = 1; i + 1 <= n; i++) cout << i << " " << i + 1 << "\n";
    }
  } else if (k == 3) {
    if (n <= 3)
      cout << -1;
    else {
      cout << 1 + 2 * (n - 3) << "\n";
      cout << "2 3\n";
      for (int i = 4; i <= n; i++) {
        cout << "1 " << i << "\n";
        cout << "2 " << i << "\n";
      }
    }
  } else
    cout << -1;
  return 0;
}
