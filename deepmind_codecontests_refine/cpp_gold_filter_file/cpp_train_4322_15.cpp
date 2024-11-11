#include <bits/stdc++.h>
using namespace std;
bool vis[2001][2001][2][2];
double f[2001][2001][2][2];
int n;
double h, p;
int nxt[3001], pre[3001];
double nxtlen[3001], prelen[3001];
double x[3001];
double Dp(int l, int r, int mask1, int mask2) {
  if (l > r) return 0.0;
  if (vis[l][r][mask1][mask2]) return f[l][r][mask1][mask2];
  vis[l][r][mask1][mask2] = true;
  double tmp = 0.0;
  tmp +=
      0.5 * (1 - p) * (Dp(nxt[l], r, 1, mask2) + x[min(nxt[l] - 1, r)] - x[l]);
  if (nxt[l] >= r + 1) {
    if (mask2 == 1)
      tmp += 0.5 * (1 - p) * min(h, x[r + 1] - x[r]);
    else
      tmp += 0.5 * (1 - p) * min(h, max(x[r + 1] - x[r] - h, 0.0));
  } else
    tmp += 0.5 * (1 - p) * h;
  tmp += 0.5 * p * (Dp(l, pre[r], mask1, 0) + x[r] - x[max(pre[r] + 1, l)]);
  if (pre[r] + 1 <= l) {
    if (mask1 == 0)
      tmp += 0.5 * p * min(h, x[l] - x[l - 1]);
    else
      tmp += 0.5 * p * min(h, max(x[l] - x[l - 1] - h, 0.0));
  } else
    tmp += 0.5 * p * h;
  if (mask1 == 0)
    tmp += 0.5 * p * (Dp(l + 1, r, 0, mask2) + min(h, x[l] - x[l - 1]));
  else
    tmp += 0.5 * p *
           (Dp(l + 1, r, 0, mask2) + min(h, max(x[l] - x[l - 1] - h, 0.0)));
  if (mask2 == 0)
    tmp += 0.5 * (1 - p) *
           (Dp(l, r - 1, mask1, 1) + min(h, max(x[r + 1] - x[r] - h, 0.0)));
  else
    tmp += 0.5 * (1 - p) * (Dp(l, r - 1, mask1, 1) + min(h, x[r + 1] - x[r]));
  f[l][r][mask1][mask2] = tmp;
  return tmp;
}
int main() {
  scanf("%d %lf %lf", &n, &h, &p);
  for (int i = 1; i <= n; i++) scanf("%lf", &x[i]);
  sort(x + 1, x + 1 + n);
  for (int i = 1; i <= n; i++) {
    int tmp = i + 1;
    while (tmp <= n && x[tmp] - x[tmp - 1] < h) ++tmp;
    --tmp;
    nxt[i] = tmp + 1;
    nxtlen[i] = x[tmp] + h - x[i];
  }
  for (int i = n; i >= 1; i--) {
    int tmp = i - 1;
    while (tmp && x[tmp + 1] - x[tmp] < h) --tmp;
    ++tmp;
    pre[i] = tmp - 1;
    prelen[i] = x[i] - x[tmp] + h;
  }
  x[0] = -999999999.0, x[n + 1] = 999999999.0;
  printf("%.9f\n", Dp(1, n, 0, 0));
  return 0;
}
