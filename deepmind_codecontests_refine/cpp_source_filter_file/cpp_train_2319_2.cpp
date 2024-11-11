#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, cnt, flag, flag1, flag2;
int a[2000005], b[2000005];
char s1[2000005], s2[2000005];
int ldis[2000005], mdis[2000005], ans[2000005];
int main(void) {
  while (scanf("%d", &t) != EOF) {
    while (t--) {
      scanf("%d", &n);
      for (int i = 1; i <= n; i++) {
        ldis[i] = 0;
        mdis[i] = 0;
        ans[i] = 10;
      }
      for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
      }
      for (int i = 1; i <= n; i++) {
        mdis[a[i]] = max(mdis[a[i]], i - ldis[a[i]]);
        ldis[a[i]] = i;
      }
      for (int i = 1; i <= n; i++) {
        mdis[a[i]] = max(mdis[a[i]], n + 1 - ldis[a[i]]);
      }
      for (int i = 1; i <= n; i++) {
        ans[mdis[a[i]]] = min(ans[mdis[a[i]]], a[i]);
      }
      for (int i = 2; i <= n; i++) {
        ans[i] = min(ans[i], ans[i - 1]);
      }
      for (int i = 1; i <= n; i++) {
        if (ans[i] > n) {
          printf("-1 ");
        } else {
          printf("%d ", ans[i]);
        }
      }
      printf("\n");
    }
  }
  return 0;
}
