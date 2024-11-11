#include <bits/stdc++.h>
int n, k;
int c[1000001];
int main() {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::scanf("%d", c + i);
  for (int i = 2; i * i <= k; i++) {
    if (k % i) continue;
    int p = 1, flag = false;
    while (!(k % i)) p *= i, k /= i;
    for (int j = 1; j <= n; j++) {
      if (!(c[j] % p)) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      std::puts("No");
      return 0;
    }
  }
  if (k > 1) {
    int flag = false;
    for (int i = 1; i <= n; i++) {
      if (!(c[i] % k)) {
        flag = true;
        break;
      }
    }
    if (!flag) return std::puts("No"), 0;
  }
  std::puts("Yes");
  return 0;
}
