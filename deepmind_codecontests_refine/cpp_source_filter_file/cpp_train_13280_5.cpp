#include <bits/stdc++.h>
using namespace std;
int n, k, x, y, sum, ans, a[10000005], cnt[10000005];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    a[x]++;
    cnt[x]++;
  }
  for (int i = 10000000; i > 0; i--) {
    ans += cnt[i];
    if (ans >= k) {
      printf("%d\n", i);
      return 0;
    }
    cnt[i / 2] += a[i];
    a[i / 2] += a[i];
    a[(i + 1) / 2] += a[i];
  }
  printf("-1\n");
  return 0;
}
