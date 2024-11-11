#include <bits/stdc++.h>
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  if (n >= k && n >= m) {
    printf("Yes\n");
  } else {
    printf("No");
  }
  return 0;
}
