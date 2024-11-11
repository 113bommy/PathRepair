#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
int cmp(const void *A, const void *B) {
  int *a = (int *)A;
  int *b = (int *)B;
  return a[0] - b[0];
}
int main() {
  int n, m, i, cnt, x, y;
  int visc[maxn], visr[maxn];
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(visc, 0, sizeof(visc));
    memset(visr, 0, sizeof(visr));
    for (i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      visc[x] = 1;
      visr[y] = 1;
    }
    for (i = 2, cnt = 0; i < n; i++) {
      if (visc[i] == 0 || visr[i] == 0) {
        if (visc[i] == visr[i]) {
          if (i == (n + 1) / 2 && n % 2)
            cnt++;
          else
            cnt += 2;
        } else
          cnt++;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
