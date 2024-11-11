#include <bits/stdc++.h>
using namespace std;
int q, n, k, d, a[1000005], p[200005], ans, s;
int main() {
  scanf("%d", &q);
  while (q--) {
    ans = 0, s = 0;
    scanf("%d%d%d", &n, &k, &d);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      p[a[i]] = 0;
    }
    for (int i = 1; i <= d; i++) {
      if (p[a[i]] == 0) s++;
      p[a[i]]++;
    }
    ans = s;
    for (int i = 1; i <= n - d; i++) {
      p[a[i]]--;
      if (p[a[i]] == 0) s--;
      if (p[a[i + d]] == 0) s++;
      p[a[i + d]]++;
      ans = min(s, ans);
    }
    printf("%d\n", ans);
  }
  return 0;
}
