#include <bits/stdc++.h>
using namespace std;
long long x, i, n, last, mx, j, a[2000000], b[2000000];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    a[x] = 1;
  }
  last = 0;
  for (i = 0; i <= 1000001; i++) {
    b[i] = last;
    if (a[i]) last = i;
  }
  mx = 0;
  for (i = 0; i <= 1000000; i++) {
    if (a[i]) {
      j = 1;
      while (1) {
        if (i * j > 1000000) {
          if (b[1000001] > i) mx = max(mx, b[1000001] % i);
          break;
        }
        if (b[i * j] > i) mx = max(mx, b[i * j] % i);
        j++;
      }
    }
  }
  cout << mx << endl;
  return 0;
}
