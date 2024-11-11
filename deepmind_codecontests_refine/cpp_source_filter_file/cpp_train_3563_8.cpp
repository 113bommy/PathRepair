#include <bits/stdc++.h>
const int MAX_N = 80;
const int MAX_K = 10;
int n, k, a[MAX_N][MAX_N], f[MAX_K][MAX_N], ans = 0x7fffffff;
bool b[MAX_N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
  for (int i = n / 2 + 1; i < n; ++i) b[i] = true;
  for (int t = 0; t < 12345; ++t) {
    std::random_shuffle(b + 1, b + n);
    for (int i = 1; i < n; ++i) f[0][i] = a[0][i];
    for (int i = 1; i < k; ++i)
      for (int j = 0; j < n; ++j)
        if (i & 1 ^ b[j]) {
          f[i][j] = 0x7fffffff;
          for (int k = 0; k < n; ++k)
            if (b[j] ^ b[k]) f[i][j] = std::min(f[i][j], f[i - 1][k] + a[k][j]);
        }
    ans = std::min(ans, f[k - 1][0]);
  }
  printf("%d\n", ans);
  return 0;
}
