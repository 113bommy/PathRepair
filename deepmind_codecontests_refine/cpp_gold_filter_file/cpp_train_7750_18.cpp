#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, f = 0;
  cin >> n >> k;
  long long int a[n][2];
  for (i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  long long int b[n];
  long long int c[n];
  for (i = 0; i < n; i++) {
    b[i] = a[i][0];
    c[i] = a[i][1];
  }
  long long int t = 0;
  for (i = 0; i < n; i++) {
    if (b[i] < k) {
      if (100 - c[i] >= t && c[i] != 0) t = 100 - c[i];
    }
  }
  long long int d[n];
  for (i = 0; i < n; i++) d[i] = b[i];
  sort(d, d + n);
  if (k < d[0])
    cout << -1;
  else if (k == d[0]) {
    for (i = 0; i < n; i++) {
      if (b[i] == k && c[i] == 0) {
        cout << 0;
        f++;
        break;
      }
    }
    for (i = 0; i < n; i++) {
      if (b[i] == k && c[i] > 0 && f == 0) {
        cout << -1;
        break;
      }
    }
  } else
    cout << t;
  return 0;
}
