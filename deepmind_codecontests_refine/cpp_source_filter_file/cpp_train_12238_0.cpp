#include <bits/stdc++.h>
using namespace std;
int x[5005], a[5005], b[5005], c[5005], d[5005], s, t, n;
long long memo[5005][5005];
bool v[5005][5005];
long long solve(int i, int j, int k) {
  if (i == n) {
    if (j == 0 && k == 0) return 0;
    return (long long)(1e18);
  }
  if (j == 0 && k == 0 && i) return (long long)(1e18);
  long long &ret = memo[i][j];
  if (v[i][j]) return ret;
  v[i][j] = true;
  ret = (long long)(1e18);
  if (i == s) {
    if (j) ret = min(ret, solve(i + 1, j - 1, k) + x[i] + c[i]);
    ret = min(ret, solve(i + 1, j, k + 1) - x[i] + d[i]);
    return ret;
  }
  if (i == t) {
    if (k) ret = min(ret, solve(i + 1, j, k - 1) + x[i] + a[i]);
    ret = min(ret, solve(i + 1, j + 1, k) - x[i] + b[i]);
    return ret;
  }
  if (k && j)
    ret = min(ret, solve(i + 1, j - 1, k - 1) + 2 * x[i] + a[i] + c[i]);
  if (k) ret = min(ret, solve(i + 1, j, k) + a[i] + d[i]);
  if (j) ret = min(ret, solve(i + 1, j, k) + b[i] + c[i]);
  ret = min(ret, solve(i + 1, j + 1, k + 1) - 2 * x[i] + b[i] + d[i]);
  return ret;
}
int main() {
  cin >> n >> s >> t;
  s--, t--;
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  for (int i = 0; i < n; i++) scanf("%d", &d[i]);
  cout << solve(min(s, t), 0, 0);
  return 0;
}
