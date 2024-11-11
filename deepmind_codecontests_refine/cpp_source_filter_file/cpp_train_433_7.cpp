#include <bits/stdc++.h>
using namespace std;
int a[55], ans[55], p[55], n, m, sum[55], tmp[55];
inline int calc(int *x) {
  sort(x + 1, x + n + 1);
  sort(x + n + 1, x + n + n + 1);
  int ret = 0;
  for (int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + x[i];
  }
  for (int i = 0; i <= n; i++) {
    ret = max(ret, sum[i] + sum[m] - sum[n + i]);
  }
  return ret;
}
int main() {
  srand(213123);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i + i - 1], &a[i + i]);
  sort(a + 1, a + n + n + 1);
  m = n + n - 2;
  for (int i = 1; i <= m; i++) {
    p[i] = ans[i] = a[i + 2];
  }
  double t = clock();
  n--;
  while ((clock() - t) <= 200) {
    for (int i = 1; i <= m; i++) {
      swap(p[rand() % m + 1], p[rand() % m + 1]);
    }
    int flag = 1;
    int val = calc(p);
    while (flag) {
      flag = 0;
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
          for (int k = 1; k <= m; k++) tmp[k] = p[k];
          swap(p[i], p[j + n]);
          if (calc(p) < val) {
            flag = 1;
            val = calc(p);
          } else {
            for (int k = 1; k <= m; k++) p[k] = tmp[k];
          }
        }
    }
    if (calc(ans) > val) {
      for (int i = 1; i <= m; i++) ans[i] = p[i];
    }
  }
  calc(ans);
  printf("%d ", a[1]);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  for (int i = m; i >= n + 1; i--) printf("%d ", ans[i]);
  printf("%d ", a[2]);
  return 0;
}
