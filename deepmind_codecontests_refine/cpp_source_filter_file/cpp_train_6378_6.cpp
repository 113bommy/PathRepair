#include <bits/stdc++.h>
using namespace std;
int n, m, a[111111], t, x, val, res;
int block_size = 300, step[100002], nxt[100002];
int main() {
  scanf("%d%d", &n, &m);
  block_size = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    int j = i;
    for (; j / block_size == i / block_size && j <= n; j += a[j]) step[i]++;
    nxt[i] = j;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &t);
    if (t == 0) {
      scanf("%d%d", &x, &val);
      a[x] = val;
      for (int j = x; i / block_size == j / block_size && j >= 1; j--) {
        if (j + a[j] > n || (j + a[j]) / block_size > j / block_size)
          step[j] = 1, nxt[j] = a[j] + j;
        else
          step[j] = step[j + a[j]] + 1, nxt[j] = nxt[j + a[j]];
      }
    } else {
      res = 0;
      scanf("%d", &x);
      int j = x;
      for (j = x; nxt[j] <= n; j = nxt[j]) {
        res += step[j];
      }
      for (; j + a[j] <= n; j += a[j]) {
        res++;
      }
      printf("%d %d\n", j, res + 1);
    }
  }
}
