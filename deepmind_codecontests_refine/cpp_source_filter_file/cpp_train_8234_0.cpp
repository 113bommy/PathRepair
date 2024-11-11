#include <bits/stdc++.h>
using namespace std;
int main() {
  int L = 0, R = 0, r, n, i, a[1000];
  cin >> n >> r;
  for (i = 0; i < n; i++) cin >> a[i];
  int x;
  int count = 0;
  while (L < n && R < n) {
    R = L + r - 1;
    if (R < n && a[R] == 1) {
      count++;
      L = R + r;
    } else {
      x = L - r;
      for (i = R - 1; i >= L - r + 1 && i > -1; i--) {
        if (i < n && a[i] == 1) {
          count++;
          L = i + r;
          break;
        }
      }
      if (i == x || i == -1) {
        count = -1;
        break;
      }
    }
  }
  cout << count;
  return 0;
}
