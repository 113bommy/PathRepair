#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, v3, vm;
  cin >> v1 >> v2 >> v3 >> vm;
  for (int i = 200; i > 0; i--) {
    for (int j = i - 1; j > 0; j--) {
      for (int k = j - 1; k > 0; k--) {
        if ((v1 <= i and 2 * v1 >= i) and (v2 <= j and 2 * v2 >= j) and
            (v3 <= k and 2 * v3 >= k) and
            (vm <= i and vm <= j and vm <= k and 2 * vm >= k and vm < j and
             vm < i)) {
          cout << i << endl << j << endl << k << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
