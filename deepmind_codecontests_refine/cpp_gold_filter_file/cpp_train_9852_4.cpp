#include <bits/stdc++.h>
using namespace std;
int a[1000006];
int main() {
  int n, m, c;
  cin >> n >> m >> c;
  int b = 0;
  int e = n + 1;
  a[e] = INT_MAX;
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    if (x <= c / 2) {
      int up = upper_bound(a, a + b + 1, x) - a;
      a[up] = x;
      b = max(b, up);
      printf("%d\n", up);
      fflush(stdout);
    } else {
      int d = lower_bound(a + e, a + n + 1, x) - a - 1;
      if (a[e] >= x) {
        e--;
        a[e] = x;
        printf("%d\n", e);
        fflush(stdout);
      } else {
        a[d] = x;
        printf("%d\n", d);
        fflush(stdout);
      }
    }
    if (b == e - 1) break;
  }
  return 0;
}
