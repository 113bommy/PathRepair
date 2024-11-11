#include <bits/stdc++.h>
int main() {
  int n, ans = 0, a;
  int p[10001];
  memset(p, 0, sizeof(p));
  bool flag = true;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    p[a] = i + 1;
  }
  for (int j = 10000; j >= 1; j--) {
    if (p[j] > 0 && flag) {
      printf("%d ", p[j]);
      flag = false;
    } else if (p[j] > 0) {
      printf("%d\n", j);
      break;
    }
  }
  return 0;
}
