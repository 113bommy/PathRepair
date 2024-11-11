#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001], b[1001], c[1001], d[1001], e[1001];
int ans[1001], cnt;
int main() {
  scanf("%d", &n);
  if (n > 10) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &e[i]);
  }
  for (int i = 1; i <= n; i++) {
    int flag = 0;
    for (int j = 1; j <= n; j++) {
      if (j == i) continue;
      for (int k = 1; k <= n; k++) {
        if (k == i || k == j) continue;
        long long check =
            (a[j] - a[i]) * (a[k] - a[i]) + (b[j] - b[i]) * (b[k] - b[i]) +
            (c[j] - c[i]) * (c[k] - c[i]) + (d[j] - d[i]) * (d[k] - d[i]) +
            (e[j] - e[i]) * (e[k] - e[i]);
        if (check > 0) flag = 1;
      }
    }
    if (!flag) ans[++cnt] = i;
  }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
