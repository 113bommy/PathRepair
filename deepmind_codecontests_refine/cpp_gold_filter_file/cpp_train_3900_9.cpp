#include <bits/stdc++.h>
using namespace std;
int n, a[2001][2001];
long long lsum[4001], rsum[4001];
int xa, xb, ya, yb;
long long maxa, maxb;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &a[i][j]), lsum[i + j - 1] += a[i][j],
          rsum[i - j + n] += a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      long long ans = lsum[i + j - 1] + rsum[i - j + n] - a[i][j];
      if ((i + j) & 1) {
        if (ans >= maxb) maxb = ans, xb = i, yb = j;
      } else if (ans >= maxa)
        maxa = ans, xa = i, ya = j;
    }
  printf("%lld\n%d %d %d %d", maxa + maxb, xa, ya, xb, yb);
  return 0;
}
