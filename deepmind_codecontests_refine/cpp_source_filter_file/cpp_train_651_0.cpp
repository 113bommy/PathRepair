#include <bits/stdc++.h>
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      printf("%d ", 200 + i * 2);
    }
    printf("\n");
  }
}
