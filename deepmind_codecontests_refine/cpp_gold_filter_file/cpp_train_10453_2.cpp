#include <bits/stdc++.h>
using namespace std;
int w[100006], sum[100006];
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  int n, L, R, QL, QR, i;
  memset(sum, 0, sizeof(sum));
  scanf("%d%d%d%d%d", &n, &L, &R, &QL, &QR);
  for (i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    sum[i] = sum[i - 1] + w[i];
  }
  int ans = 0x7fffffff;
  for (i = 0; i <= n; i++) {
    int a = i;
    int b = n - i;
    int tot = sum[i] * L + R * (sum[n] - sum[n - b]);
    if (a > b)
      tot += QL * (a - b - 1);
    else if (a < b)
      tot += QR * (b - a - 1);
    ans = min(ans, tot);
  }
  printf("%d\n", ans);
  return 0;
}
