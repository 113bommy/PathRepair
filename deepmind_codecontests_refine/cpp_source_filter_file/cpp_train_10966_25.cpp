#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j <= 4; j++) {
      for (int z = 0; z <= 4; z++) {
        for (int q = 0; q <= 4; q++) {
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
