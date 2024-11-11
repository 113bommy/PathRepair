#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int b[n];
  int a[5] = {n, n / 2, n / 4, n / 8, n / 16};
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < 5; i++) {
    if (a[i] != 0) {
      for (int j = 0; j < n; j += a[i]) {
        if (is_sorted(b + j, b + j + a[i])) {
          cout << a[i] << "\n";
          return 0;
        }
      }
    }
    cout << "1"
         << "\n";
  }
  return 0;
}
