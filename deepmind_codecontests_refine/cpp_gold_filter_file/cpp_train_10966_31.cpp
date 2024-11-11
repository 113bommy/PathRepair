#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int z = 0; z <= n; z++) {
        for (int q = 0; q <= n; q++) {
          if (2 * i + 3 * j + 4 * q + 5 * z == k && i + j + q + z == n) {
            cout << i;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
