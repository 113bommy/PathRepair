#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int main() {
  int n;
  cin >> n;
  if (n & 1) {
    int ans = 2;
    for (int i = 5; i <= n; i += 2) {
      ans += (i - 3) + 2;
    }
    cout << ans << "\n";
    cout << "3 1 2 3\n";
    cout << "3 1 2 3\n";
    for (int i = 5; i <= n; i += 2) {
      cout << 3 << " " << 1 << " " << i - 1 << " " << i << "\n";
      cout << 3 << " " << 1 << " " << i - 1 << " " << i << "\n";
      for (int j = 2; j <= i - 2; j += 2) {
        cout << 4 << " " << j << " " << i - 1 << " " << j + 1 << " " << i
             << "\n";
        cout << 4 << " " << j << " " << i - 1 << " " << j + 1 << " " << i
             << "\n";
      }
    }
  } else {
    int ans = 3;
    for (int i = 6; i <= n; i += 2) {
      ans += (i - 4) + 3;
    }
    cout << ans << "\n";
    cout << "4 1 2 3 4\n";
    cout << "4 1 2 4 3\n";
    cout << "4 1 4 2 3\n";
    for (int i = 6; i <= n; i += 2) {
      cout << 3 << " " << 1 << " " << i - 1 << " " << i << "\n";
      cout << 3 << " " << 2 << " " << i - 1 << " " << i << "\n";
      cout << 4 << " " << 1 << " " << i - 1 << " " << 2 << " " << i << "\n";
      for (int j = 3; j <= i - 2; j += 2) {
        cout << 4 << " " << j << " " << i - 1 << " " << j + 1 << " " << i
             << "\n";
        cout << 4 << " " << j << " " << i - 1 << " " << j + 1 << " " << i
             << "\n";
      }
    }
  }
  return 0;
}
