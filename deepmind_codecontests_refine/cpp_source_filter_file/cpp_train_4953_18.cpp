#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 2 && n >= 5) {
    cout << n - 1 << '\n';
    for (int i = 1; i < n; i++) {
      cout << i << " " << i + 1 << '\n';
    }
    return 0;
  } else if (k == 3 && n >= 4) {
    cout << n - 1 << '\n';
    cout << 1 << " " << 2 << '\n';
    cout << 2 << " " << 3 << '\n';
    cout << 3 << " " << 4 << '\n';
    for (int i = 5; i <= n; i++) {
      cout << 1 << " " << n << '\n';
      cout << 3 << " " << n << '\n';
    }
  } else {
    cout << -1;
  }
  return 0;
}
