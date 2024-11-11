#include <bits/stdc++.h>
using namespace std;
int a[1101], c[1101];
int main(void) {
  memset(a, 0, sizeof(a));
  memset(c, 0, sizeof(c));
  int p, q, l, r;
  cin >> p >> q >> l >> r;
  int count = 0;
  int i, j;
  for (i = 0; i < p; i++) {
    int x, y;
    cin >> x >> y;
    for (j = x; j <= y; j++) {
      a[j] = 1;
    }
  }
  for (i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    for (j = x; j <= y; j++) {
      c[j] = 1;
    }
  }
  for (i = l; i <= r; i++) {
    for (j = 0; j < 1001; j++) {
      if (c[j] == 1) {
        int x = j + i;
        if (a[x] == 1) {
          count++;
          break;
        }
      }
    }
  }
  cout << count;
  return 0;
}
