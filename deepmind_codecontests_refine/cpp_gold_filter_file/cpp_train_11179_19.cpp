#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, p = 1;
  cin >> n >> k;
  for (i = 1; i <= k; i++) {
    for (j = 1; j <= n; j++) {
      if (p + j >= n) {
        cout << n << " ";
        continue;
      }
      cout << p + j << " ";
    }
    p *= 2;
    cout << endl;
  }
  return 0;
}
