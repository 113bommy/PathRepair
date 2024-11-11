#include <bits/stdc++.h>
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
char ss[300005];
int a[300005], sum[300005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    scanf(" %s", ss);
    for (int i = 0; i < n; i++) {
      if (ss[i] == '+')
        a[i] = 1;
      else
        a[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 0)
        sum[i] = sum[i - 1] - a[i - 1];
      else
        sum[i] = sum[i - 1] + a[i - 1];
    }
    while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      if (sum[r] - sum[l - 1] == 0)
        printf("0\n");
      else if (abs(sum[r] - sum[l - 1]) % 2 == 1)
        printf("1\n");
      else
        printf("2\n");
    }
  }
  return 0;
}
