#include <bits/stdc++.h>
const int N = 1e3 + 10;
int n;
int l[N];
int k;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int r;
    scanf("%d%d", &l[i], &r);
    if (i == n) {
      l[i + 1] = r + 1;
    }
  }
  scanf("%d", &k);
  for (int i = 1; i <= n; i++) {
    if (k >= l[i] && k < l[i + 1]) {
      printf("%d\n", n - i + 1);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
