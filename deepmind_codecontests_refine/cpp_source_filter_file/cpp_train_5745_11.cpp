#include <bits/stdc++.h>
using namespace std;
int nums[200005];
char s[200005];
signed main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &nums[i]);
    }
    for (int i = 1; i < n; i++) {
      if (nums[i + 1] - nums[i] > k + m) {
        printf("NO\n");
        goto L;
      } else {
        m += nums[i] - (nums[i + 1] - k);
        continue;
      }
    }
    printf("YES\n");
  L:;
  }
  return 0;
}
