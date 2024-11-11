#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n, k;
    cin >> n >> k;
    int a[n];
    int b[k];
    int ico = 0, sum = 0, t = 0;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
      if (a[j] % 2 == 1) {
        ico++;
        if (ico - 1 < k - 1) b[ico - 1] = j + 1;
      }
    }
    if (ico % 2 != k % 2 || ico < k)
      cout << "NO";
    else {
      cout << "YES"
           << "\n";
      for (int j = 0; j < k - 1; j++) cout << b[j] << " ";
      cout << n << "\n";
    }
  }
}
