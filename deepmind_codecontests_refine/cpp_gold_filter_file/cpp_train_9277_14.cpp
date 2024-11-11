#include <bits/stdc++.h>
inline int in() {
  int x = 0;
  char c = getchar();
  bool f = false;
  while (c < '0' || c > '9') f |= c == '-', c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
const int N = 105;
int t[N], f[N * N][N], tot;
int main() {
  int n = in(), res = 1;
  for (int i = 1; i <= n; ++i) {
    int a = in();
    if (!t[a]) ++tot;
    ++t[a];
  }
  if (tot <= 2) {
    printf("%d\n", n);
    return 0;
  }
  f[0][0] = 1;
  for (int i = 1; i <= 100; ++i)
    if (t[i]) {
      for (int j = 10000; j; --j)
        for (int k = 1; k <= n; ++k)
          for (int l = 1; l <= t[i] && l <= k && l * i <= j; ++l)
            f[j][k] += f[j - l * i][k - l];
    }
  for (int i = 1; i <= 100; ++i)
    if (t[i])
      for (int j = 1; j <= t[i]; ++j)
        if (f[i * j][j] == 1) res = std::max(res, j);
  printf("%d\n", res);
  return 0;
}
