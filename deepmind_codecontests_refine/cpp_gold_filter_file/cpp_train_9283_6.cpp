#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0)
    cout << "NO";
  else {
    cout << "YES \n";
    int LEN = 2 * n + 1;
    int a[LEN];
    for (int k = 1; k <= n; k++) {
      int k_pair = (n + k) % (2 * n);
      if (k % 2 == 1) {
        a[k] = 2 * k - 1;
        a[k_pair] = 2 * k;
      } else {
        a[k] = 2 * k;
        a[k_pair] = 2 * k - 1;
      }
    }
    for (int j = 0; j < LEN - 1; j++) {
      cout << a[j] << " ";
    }
    cout << endl;
  }
}
