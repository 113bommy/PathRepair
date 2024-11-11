#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t, m, j, s, r, l;
  long long k, i, p = 0, h = 0, x = 0, y;
  t = 1;
  for (i = 0; i < t; i++) {
    cin >> n >> k;
    h = 0;
    p = 0;
    int a[n];
    for (j = 0; j < n; j++) {
      cin >> a[j];
      p += a[j];
    }
    if (p % k == 0) {
      p = p / k;
      h = 0;
      int b[k];
      for (j = 0, l = 0; j < n; j++) {
        if (h < p) {
          x++;
          h += a[j];
        }
        if (h == p) {
          b[l] = x;
          l++;
          x = 0;
          h = 0;
        } else if (h > p)
          break;
      }
      if (j == n) {
        std::cout << "YES" << std::endl;
        for (j = 0; j < k; j++) cout << b[j] << " ";
      } else
        std::cout << "NO" << std::endl;
    } else
      std::cout << "NO" << std::endl;
  }
}
