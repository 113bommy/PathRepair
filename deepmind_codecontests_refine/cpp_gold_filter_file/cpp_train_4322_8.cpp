#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
double dp[N][N][2][2];
int vis[N][N][2][2];
int n, h;
double p;
int ne[N], pre[N];
int v[N];
double solve(int L, int R, int b1 = 0, int b2 = 0) {
  if (L == R)
    return (1 - p) * min(h, (R != n - 1 ? (v[R + 1] - b2 * h) - v[R] : h)) +
           (p)*min(h, (L != 0 ? v[L] - (v[L - 1] + b1 * h) : h));
  if (L > R) return 0;
  double &ret = dp[L][R][b1][b2];
  if (vis[L][R][b1][b2]) return ret;
  vis[L][R][b1][b2] = 1;
  ret = 0;
  int nee = min(R, ne[L]);
  int pree = max(L, pre[R]);
  int c1 = min(h, L != 0 ? v[L] - (v[L - 1] + b1 * h) : h);
  int c2 = min(h, R != n - 1 ? v[R + 1] - b2 * h - v[R] : h);
  ret += (solve(L + 1, R, 0, b2) + c1) * 0.5 * (p);
  ret += (solve(nee + 1, R, 1, b2) + (v[nee] - v[L] + (nee == R ? c2 : h))) *
         0.5 * (1 - p);
  ret += (solve(L, R - 1, b1, 0) + c2) * 0.5 * (1 - p);
  ret += (solve(L, pree - 1, b1, 1) + (v[R] - v[pree] + (pree == L ? c1 : h))) *
         0.5 * (p);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> h >> p;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v, v + n);
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1 || v[i + 1] - v[i] >= h)
      ne[i] = i;
    else
      ne[i] = ne[i + 1];
  }
  for (int i = 0; i < n; i++) {
    if (i == 0 || v[i] - v[i - 1] >= h)
      pre[i] = i;
    else
      pre[i] = pre[i - 1];
  }
  cout << fixed << setprecision(10) << solve(0, n - 1);
}
