#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], c[100010], d[100010], e[100010];
inline bool check(int i, int j, int k) {
  int res1 = (a[j] - a[i]) * (a[k] - a[i]) + (b[j] - b[i]) * (b[k] - b[i]) +
             (c[j] - c[i]) * (c[k] - c[i]) + (d[j] - d[i]) * (d[k] - d[i]) +
             (e[j] - e[i]) * (e[k] - e[i]);
  if (res1 > 0) return 0;
  return 1;
}
int n, cnt, Ans[100010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i < (n + 1); i++)
    scanf("%d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &e[i]);
  if (n > 10)
    puts("0");
  else {
    for (int i = 1; i <= n; i++) {
      int flag = 1;
      for (int j = 1; j <= n; j++) {
        if (j == i) continue;
        for (int k = j + 1; k <= n; k++) {
          if (k == i) continue;
          if (!check(i, j, k)) {
            flag = 0;
            break;
          }
        }
        if (flag == 0) break;
      }
      if (flag) Ans[++cnt] = i;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d\n", Ans[i]);
  }
}
