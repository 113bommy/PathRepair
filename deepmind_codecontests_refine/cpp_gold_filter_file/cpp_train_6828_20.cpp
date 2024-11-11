#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
int a[N], p[N], k[N];
int n;
int q;
int tim[N][301];
int ans[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) scanf("%d%d", &p[i], &k[i]);
  for (int i = 1; i <= min(300, n); i++) {
    for (int j = n; j >= 1; j--) {
      int k = j + a[j] + i;
      if (k > n)
        tim[j][i] = 1;
      else
        tim[j][i] = tim[k][i] + 1;
    }
  }
  for (int i = 1; i <= q; i++) {
    if (k[i] <= 300)
      ans[i] = tim[p[i]][k[i]];
    else {
      int cnt = 0;
      int dd = p[i];
      while (dd <= n) {
        dd = dd + a[dd] + k[i];
        cnt++;
      }
      ans[i] = cnt;
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%d \n", ans[i]);
  }
  return 0;
}
