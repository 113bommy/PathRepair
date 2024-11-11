#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 100;
long long n, h;
long double p;
long long x[N], arr[N];
int lft[N], ryt[N];
long double memo[N][N][2][2];
long double DP(int l, int r, int a, int b) {
  if (l > r) return 0;
  long double& ret = memo[l][r][a][b];
  if (ret != -1) return ret;
  ret = 0;
  if (a)
    ret += p * (min(x[l] - x[l - 1] - h, h) + DP(l + 1, r, 0, b));
  else
    ret += p * (min(x[l] - x[l - 1], h) + DP(l + 1, r, 0, b));
  int nxt = min(ryt[l], r);
  if (nxt == r) {
    if (!b)
      ret += (1 - p) * (x[r] - x[l] + min(x[r + 1] - h - x[r], h));
    else
      ret += (1 - p) * (x[r] - x[l] + min(x[r + 1] - x[r], h));
  } else
    ret += (1 - p) * (x[nxt] - x[l] + h + DP(nxt + 1, r, 1, b));
  if (!b)
    ret += (1 - p) * (min(x[r + 1] - h - x[r], h) + DP(l, r - 1, a, 1));
  else
    ret += (1 - p) * (min(x[r + 1] - x[r], h) + DP(l, r - 1, a, 1));
  nxt = max(l, lft[r]);
  if (nxt == l) {
    if (a)
      ret += p * (x[r] - x[l] + min(x[l] - x[l - 1] - h, h));
    else
      ret += p * (x[r] - x[l] + min(x[l] - x[l - 1], h));
  } else
    ret += p * (x[r] - x[nxt] + h, DP(l, nxt - 1, a, 0));
  ret *= 0.5;
  return ret;
}
int main() {
  cin >> n >> h >> p;
  for (int i = 1; i <= n; i++) cin >> x[i];
  sort(x + 1, x + n + 1);
  x[0] = -500000000;
  x[n + 1] = 500000000;
  for (int i = 0; i <= n + 1; i++) arr[i] = x[i];
  for (int i = 1; i <= n; i++) {
    int prev = i;
    for (int j = i - 1; j >= 1; j--) {
      if (abs(x[j] - x[prev]) < h)
        prev = j;
      else
        break;
    }
    lft[i] = prev;
    prev = i;
    for (int j = i + 1; j <= n; j++) {
      if (abs(x[j] - x[prev]) < h)
        prev = j;
      else
        break;
    }
    ryt[i] = prev;
  }
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= n + 1; j++)
      for (int k = 0; k < 2; k++)
        for (int x = 0; x < 2; x++) memo[i][j][k][x] = -1;
  cout << fixed << setprecision(12) << DP(1, n, 0, 1);
  return 0;
}
