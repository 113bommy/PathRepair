#include <bits/stdc++.h>
int main() {
  int n, k, i, j;
  std::cin >> n >> k;
  int* x = new int[n];
  int* a = (int*)calloc(n + 2, sizeof(int));
  int* b = (int*)calloc(n + 2, sizeof(int));
  int* c = (int*)calloc(n + 2, sizeof(int));
  for (i = 0; i < k; i++) {
    scanf("%d", x + i);
    a[x[i]] = 1;
    if (a[x[i] - 1]) b[x[i] - 1] = 1;
    if (a[x[i] + 1]) c[x[i] + 1] = 1;
  }
  int ans = 3 * n - 2;
  for (i = 0; i < n + 2; i++) ans -= a[i] + b[i] + c[i];
  std::cout << ans << '\n';
  return 0;
}
