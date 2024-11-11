#include <bits/stdc++.h>
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    int M[3] = {0};
    int ans = 0;
    bool V[10000] = {false};
    for (int i = 0; i < n; i++) {
      int tmp;
      scanf("%d", &tmp);
      M[tmp % 3]++;
    }
    ans += M[0] / 3;
    ans += ((M[1]) >= (M[2]) ? (M[2]) : (M[1]));
    printf("%d\n", ans);
  }
  return 0;
}
