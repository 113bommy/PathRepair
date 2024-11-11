#include <bits/stdc++.h>
int main() {
  int n, x;
  while (scanf("%d %d", &n, &x) != EOF) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (n % i == 0 && (x / i) <= n) cnt++;
    }
    printf("%d\n", cnt);
  }
}
