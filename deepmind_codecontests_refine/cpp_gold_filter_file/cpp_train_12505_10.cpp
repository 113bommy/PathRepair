#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, m, n;
  int flag = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    for (j = i; j <= n; j++) {
      if (j % i == 0 && i * j > n && j / i < n) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
  }
  if (flag == 1) {
    printf("%d %d\n", j, i);
  } else
    printf("-1");
  return 0;
}
