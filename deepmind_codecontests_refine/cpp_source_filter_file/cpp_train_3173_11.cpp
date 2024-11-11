#include <bits/stdc++.h>
using namespace std;
int n, k, MIN = 1e7, c;
int a[110], col[110][110];
int main() {
  scanf("%d%d", &n, &k);
  c = -1e7;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    MIN = min(MIN, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= MIN; j++) col[i][j] = 1;
  }
  for (int i = 1; i <= n; i++) c = max(c, a[i] - MIN);
  if (c > k) {
    printf("NO");
    return 0;
  } else {
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
      int t = 2;
      for (int j = 1; j <= MIN; j++) printf("1 ");
      for (int j = MIN + 1; j <= a[i]; j++) printf("%d ", t), t++;
      printf("\n");
    }
  }
  return 0;
}
