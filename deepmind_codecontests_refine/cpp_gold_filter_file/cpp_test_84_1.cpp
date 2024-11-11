#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010, MAXM = 1000010;
int t, n, k, mu[MAXM], phi[MAXM];
long long sumphi[MAXM], dp[MAXM][30];
void solve(int l, int r, int xl, int xr, int k) {
  if (l > r) {
    return;
  }
  int mid = (l + r) >> 1, np = 0;
  long long nw = 0, nv = 1e18;
  for (int l = min(xr, mid - 1) + 2, r; l <= mid; l = r + 1) {
    r = mid / (mid / l);
    nw += sumphi[mid / l] * (r - l + 1);
  }
  for (int i = min(xr, mid - 1); i >= xl; i--) {
    nw += sumphi[mid / (i + 1)];
    if (dp[i][k - 1] + nw < nv) {
      nv = dp[i][k - 1] + nw;
      np = i;
    }
  }
  assert(xl <= np && np <= xr);
  dp[mid][k] = nv;
  solve(l, mid - 1, xl, np, k);
  solve(mid + 1, r, np, xr, k);
  return;
}
int main() {
  for (int i = 1; i <= MAXN - 10; i++) {
    mu[i] = 1, phi[i] = i;
    int cpi = i;
    for (int j = 2; j * j <= cpi; j++) {
      if (cpi % j == 0) {
        int cnt = 0;
        while (cpi % j == 0) {
          cpi /= j, cnt++;
        }
        if (cnt > 1) {
          mu[i] = 0;
        } else {
          mu[i] = -mu[i];
        }
        phi[i] = phi[i] / j * (j - 1);
      }
    }
    if (cpi > 1) {
      mu[i] = -mu[i], phi[i] = phi[i] / cpi * (cpi - 1);
    }
    sumphi[i] = sumphi[i - 1] + phi[i];
    dp[i][1] = 1ll * i * (i + 1) / 2;
  }
  for (int i = 2; i <= 20; i++) {
    solve(i, MAXN - 10, i - 1, MAXN - 10, i);
  }
  scanf("%d", &t);
  for (int ii = 1; ii <= t; ii++) {
    scanf("%d%d", &n, &k);
    if (k <= 20) {
      printf("%lld\n", dp[n][k]);
    } else {
      printf("%d\n", n);
    }
  }
  return 0;
}
