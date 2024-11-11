#include <bits/stdc++.h>
const int MAXN = 1005;
int a[MAXN];
int cnt[MAXN];
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) + 1) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if ((j - i) * k == a[j] - a[i]) {
          cnt[i]++;
        }
      }
    }
    int mm = 0;
    int p = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] > mm && cnt[i] - (i - 1) * k > 0) {
        mm = cnt[i];
        p = i;
      }
    }
    printf("%d\n", n - mm);
    for (int i = 1; i <= n; i++) {
      if ((i - p) * k != a[i] - a[p]) {
        if (a[i] - a[p] > (i - p) * k) {
          printf("- %d %d\n", i, a[i] - a[p] - (i - p) * k);
        } else {
          printf("+ %d %d\n", i, (i - p) * k - a[i] + a[p]);
        }
      }
    }
  }
  return 0;
}
