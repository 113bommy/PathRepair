#include <bits/stdc++.h>
using namespace std;
int f[360365], g[360365], K;
int work(int a, int b) {
  g[a] = 0;
  for (int i = a; i > b; i--) {
    for (int j = 2; j <= K; j++) {
      int x = i % j;
      g[i - x] = min(g[i - x], g[i] + 1);
    }
    g[i - 1] = min(g[i - 1], g[i] + 1);
  }
  return g[b];
}
int main() {
  long long a, b, t1, t2;
  scanf("%I64d%I64d%d", &a, &b, &K);
  int n = 360360;
  for (int i = 0; i <= n; i++) g[i] = f[i] = (1 << 29);
  f[n] = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = 2; j <= K; j++) {
      int x = i % j;
      f[i - x] = min(f[i - x], f[i] + 1);
    }
    f[i - 1] = min(f[i - 1], f[i] + 1);
  }
  t1 = a / n;
  t2 = b / n;
  if (t1 == t2) {
    printf("%d\n", work(a - t1 * n, b - t2 * n));
  } else {
    printf("%I64d\n",
           work(a - t1 * n, 0) + f[b - t2 * n] + f[0] * (t1 - t2 - 1));
  }
}
