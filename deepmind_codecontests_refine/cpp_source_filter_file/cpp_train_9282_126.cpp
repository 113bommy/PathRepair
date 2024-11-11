#include <bits/stdc++.h>
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  if ((n >= m) && (n >= k)) {
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}
