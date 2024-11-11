#include <bits/stdc++.h>
using namespace std;
int a[1006];
int k;
int fun(int x) {
  int mid, high = k - 1, low = 0, i;
  while (high >= low) {
    mid = (low + high) >> 1;
    if (a[mid] < x) {
      low = mid + 1;
    } else if (a[mid] > x) {
      high = mid - 1;
    } else
      break;
  }
  if (a[mid] == x) return 999999999;
  if (a[mid] < x) {
    for (i = mid; a[i] < x && i < k; ++i)
      if (a[i] == x) return 999999999;
    return i + 1;
  } else {
    for (i = mid; a[i] >= x && i >= 0; --i)
      if (a[i] == x) return 999999999;
    return i + 1;
  }
}
int main() {
  int i, n, m, q, x, y;
  while (scanf("%d%d%d%d", &n, &m, &k, &q) != EOF) {
    for (i = 0; i < k; ++i) {
      scanf("%d%d", &x, &y);
      a[i] = (x - 1) * m + y;
    }
    sort(a, a + k);
    while (q--) {
      scanf("%d%d", &x, &y);
      i = fun((x - 1) * m + y);
      if (i == 999999999)
        puts("Waste");
      else
        switch (((x - 1) * m + y - i - 1) % 3) {
          case 0:
            puts("Carrots");
            break;
          case 1:
            puts("Kiwis");
            break;
          case 2:
            puts("Grapes");
            break;
        }
    }
  }
  return 0;
}
