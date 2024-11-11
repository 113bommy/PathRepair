#include <bits/stdc++.h>
using namespace std;
int s, k, i, j;
int a[100];
int main() {
  while (~scanf("%d%d", &s, &k)) {
    memset(a, 0, sizeof(a));
    a[0] = 0;
    a[1] = 1;
    for (i = 2;; i++) {
      for (j = 1; j <= k && j <= i; j++) a[i] += a[i - j];
      if (a[i] > s) break;
    }
    int t = i, ans = 0, n = s;
    for (i = t; i > 0; i--) {
      if (n >= a[i]) {
        n -= a[i];
        ans++;
      }
    }
    printf("%d\n", ans + 1);
    cout << 0;
    for (i = t; i > 0; i--)
      if (s >= a[i]) {
        s -= a[i];
        printf(" %d", a[i]);
      }
    cout << endl;
  }
  return 0;
}
