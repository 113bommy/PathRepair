#include <bits/stdc++.h>
using namespace std;
long long memo[52][52];
long long nCr(int n, int r) {
  if (n < r) return 0;
  if (n == r) return 1;
  if (!r) return 1;
  long long &ret = memo[n][r];
  if (~ret) return ret;
  return ret = nCr(n - 1, r - 1) + nCr(n - 1, r);
}
const int N = 52;
double memo2[N][N][2];
int n, m, mx = -1, a[N];
double solve(int idx, int remst, bool f) {
  if (idx == m) return (!remst && f ? 1.0 : 0.0);
  double &ret = memo2[idx][remst][f];
  if (ret == ret) return ret;
  ret = 0.0;
  double p = 1.0;
  for (int i = 0; i <= remst && ((i + a[idx] - 1) / a[idx]) <= mx; ++i) {
    ret += nCr(remst, i) * p *
           solve(idx + 1, remst - i, f || (((i + a[idx] - 1) / a[idx]) == mx));
    p *= 1.0 / m;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) cin >> a[i];
  memset(memo, -1, sizeof(memo));
  double res = 0.0;
  for (int i = 1; i <= n; ++i) {
    mx = i;
    memset(memo2, -1, sizeof memo2);
    res += i * solve(0, n, false);
  }
  cout << fixed << setprecision(5) << res << "\n";
}
