#include <bits/stdc++.h>
int cnt[121212], fcnt[121212], R[121212];
int D[501][5001];
int max(int a, int b) {
  if (a < b) return b;
  return a;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int i, j;
  for (i = 0; i < n * k; i++) {
    int c;
    scanf("%d", &c);
    cnt[c]++;
  }
  for (i = 0; i < n; i++) {
    int f;
    scanf("%d", &f);
    fcnt[f]++;
  }
  for (i = 1; i <= k; i++) scanf("%d", &R[i]);
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= i * k; j++) {
      for (int p = 0; p <= k && p <= j - i + 1; p++) {
        D[i][j] = max(D[i][j], D[i - 1][j - p] + R[p]);
      }
    }
  }
  long long ans = 0;
  for (i = 1; i <= 100000; i++)
    if (cnt[i] && fcnt[i]) {
      int x = cnt[i], y = fcnt[i];
      if (x > y * k) x = y * k;
      ans += D[y][x];
    }
  printf("%lld", ans);
  return 0;
}
