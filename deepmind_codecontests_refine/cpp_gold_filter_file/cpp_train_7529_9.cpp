#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n][n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  long long o = n / 2, p = n / 2, x = 1, s = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if ((i == 0 && j == 0) || (j == n - 1 && i == 0) ||
          (j == 0 && i == n - 1) || (i == n - 1 && j == n - 1))
        s += a[i][j];
      else if (j >= o && j <= p) {
        s += a[i][j];
      }
    }
    o = o - x;
    p = p + x;
    if (o == 0) {
      x = -1;
    }
  }
  cout << s;
  return 0;
}
