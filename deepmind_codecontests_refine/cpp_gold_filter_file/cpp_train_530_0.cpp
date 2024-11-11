#include <bits/stdc++.h>
using namespace std;
int W = 0;
int B = 1;
long long calc(int X1, int Y1, int X2, int Y2, int color) {
  if (X1 > X2 || Y1 > Y2) return 0;
  long long ans = 1ll * (X2 - X1 + 1) * (Y2 - Y1 + 1);
  if ((X1 + Y1) % 2 == color) ans++;
  return ans >> 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    int x[10], y[10], n, m;
    scanf("%d%d%d%d%d%d%d%d%d%d", &m, &n, &x[1], &y[1], &x[2], &y[2], &x[3],
          &y[3], &x[4], &y[4]);
    long long w = calc(1, 1, n, m, W) + calc(x[1], y[1], x[2], y[2], B) -
                  calc(x[3], y[3], x[4], y[4], W) -
                  calc(max(x[1], x[3]), max(y[1], y[3]), min(x[2], x[4]),
                       min(y[2], y[4]), B);
    printf("%lld %lld\n", w, 1ll * n * m - w);
  }
  return 0;
}
