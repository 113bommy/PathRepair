#include <bits/stdc++.h>
using namespace std;
int n, k;
int f[1001][1001];
int check() {
  if (n == 1) return 0;
  for (int i = 1; i <= n; ++i) {
    int l = k, c = 0;
    for (int j = i % n + 1; l; j = j % n + 1) {
      ++c;
      if (c > n) return 0;
      if (i == j) continue;
      if (f[j][i]) continue;
      f[i][j] = 1;
      --l;
    }
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &k);
  if (!check())
    puts("-1");
  else {
    printf("%d\n", n * k);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (f[i][j]) printf("%d %d\n", i, j);
  }
}
