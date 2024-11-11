#include <bits/stdc++.h>
using namespace std;
int a[500100];
int n;
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int last = 1, ans = 0, r, l;
    for (int i = 2; i <= n + 1; i++) {
      if (a[i] == a[i - 1] || i == n + 1) {
        ans = max(ans, (i - last - 1) / 2);
        l = last + 1;
        r = i - 2;
        while (l <= r) {
          a[l++] = a[last];
          a[r--] = a[i - 1];
        }
        last = i;
      }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
  }
  return 0;
}
