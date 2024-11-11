#include <bits/stdc++.h>
int n;
int a[200005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int last = 0;
  int sol = 1;
  for (int i = 1; i <= n; ++i) {
    if (last) {
      if (a[i]) {
        --a[i];
      } else {
        sol = 0;
        break;
      }
    }
    last = a[i] & 1;
  }
  if (sol && !last) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
