#include <bits/stdc++.h>
int ma[100005];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k + 1; i++) {
    if (i & 1)
      printf("%d ", i / 2 + 1);
    else
      printf("%d ", k + 2 - i / 2);
  }
  int s = (k + 1) / 2 + 1;
  int e = k + 2 - (k + 1) / 2;
  for (int i = s + 1; i < e - 1; i++) {
    printf("%d ", i);
  }
  for (int i = k + 2; i <= n; i++) {
    printf("%d ", i);
  }
  if (s + 1 <= e - 1) printf("%d\n", e - 1);
  return 0;
}
