#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, m, max = 0;
  cin >> n >> k;
  cout << "\n";
  int a[n];
  int b[5001] = {0};
  int d[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]] = b[a[i]] + 1;
  }
  cout << "\n";
  for (i = 0; i <= 5000; i++) {
    if (max < b[i]) max = b[i];
  }
  if (max > k) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    m = 1;
    for (i = 0; i <= 5000; i++) {
      if (b[i] != 0) {
        for (j = 0; j < n; j++) {
          if (i == a[j]) {
            d[j] = m;
            m++;
            if (m > k) m = 1;
          }
        }
      }
    }
    for (i = 0; i < n; i++) cout << d[i];
  }
}
