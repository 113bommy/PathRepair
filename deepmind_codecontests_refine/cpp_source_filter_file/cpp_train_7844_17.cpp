#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n == 1 || n % 2 == 0) {
      printf("-1\n");
      continue;
    }
    int ans = 0;
    for (int i = n; i >= 2; i--) {
      if (a[i] || a[i - 1] > 0) {
        int maxn = max(a[i], a[i - 1]);
        a[i] -= maxn;
        a[i - 1] -= maxn;
        a[i / 2] -= maxn;
        ans += maxn;
      }
    }
    if (a[1] > 0) ans += a[1];
    printf("%d\n", ans);
  }
}
