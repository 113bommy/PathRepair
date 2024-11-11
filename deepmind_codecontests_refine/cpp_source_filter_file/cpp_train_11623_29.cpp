#include <bits/stdc++.h>
using namespace std;
long long v1, v2, v3, vm;
int main() {
  cin >> v1 >> v2 >> v3 >> vm;
  for (int i = 1; i <= 100; i++) {
    for (int j = i + 1; j <= 100; j++) {
      for (int k = j + 1; k <= 100; k++) {
        if (v3 <= i && 2 * v3 >= i) {
          if (v2 <= j && v2 * 2 >= j) {
            if (v1 <= k && v1 * 2 >= k) {
              if (vm <= i && 2 * vm >= i && 2 * vm < j) {
                cout << k << endl;
                cout << j << endl;
                cout << i << endl;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << -1;
  return 0;
}
