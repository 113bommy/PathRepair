#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, m, n, l, ans;
  int v[6000];
  int s[6000];
  int a[6000];
  while (scanf("%d", &n) != EOF) {
    memset(v, 0, sizeof(v));
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      v[a[i]] = 1;
    }
    ans = 0;
    k = 0;
    for (i = 1; i <= 5000; i++) {
      k += v[i];
      if (i >= n) k -= v[i - n];
      ans = max(k, ans);
    }
    printf("%d\n", n - ans);
  }
}
