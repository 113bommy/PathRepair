#include <bits/stdc++.h>
using namespace std;
const int MAX_STATE = 71;
const long long inf = 1e18;
pair<int, int> p[30];
int c[10], f[1 << 8];
int x, k, n, q, cnt;
struct matrix {
  long long A[MAX_STATE][MAX_STATE];
  matrix() {
    for (int i = 1; i < MAX_STATE; i++) {
      for (int j = 1; j < MAX_STATE; j++) A[i][j] = inf;
      A[i][i] = 0;
    }
  }
  matrix operator*(matrix B) {
    matrix r;
    for (int i = 1; i <= cnt; i++) r.A[i][i] = inf;
    for (int i = 1; i <= cnt; i++)
      for (int j = 1; j <= cnt; j++)
        for (int k = 1; k <= cnt; k++)
          r.A[i][j] = min(r.A[i][j], A[i][k] + B.A[k][j]);
    return r;
  }
  matrix operator^(int y) {
    matrix x, r;
    for (int i = 1; i <= cnt; i++)
      for (int j = 1; j <= cnt; j++) x.A[i][j] = A[i][j];
    if (!y) return x;
    while (y) {
      if (y & 1) r = r * x;
      x = x * x;
      y >>= 1;
    }
    return r;
  }
};
int calc(int x) {
  int sum = 0;
  while (x) {
    if (x & 1) sum++;
    x >>= 1;
  }
  return sum;
}
int main() {
  cin >> x >> k >> n >> q;
  for (int i = 1; i <= k; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= q; i++) scanf("%d%d", &p[i].first, &p[i].second);
  for (int i = 0; i < (1 << k); i++)
    if (calc(i) == x) f[i] = ++cnt;
  matrix R;
  for (int i = 1; i <= cnt; i++) R.A[i][i] = inf;
  for (int i = 1; i < (1 << k); i++) {
    if (!f[i]) continue;
    if (i & 1) {
      for (int j = 1; j <= k; j++) {
        if ((1 << j) & i) continue;
        R.A[f[i]][f[((1 << j) | i) >> 1]] = c[j];
      }
    } else
      R.A[f[i]][f[i >> 1]] = 0;
  }
  sort(p + 1, p + q + 1);
  matrix ans;
  long long sum = 0;
  int now = 1;
  for (int i = 1; i <= q; i++) {
    if (p[i].first > n - x) {
      sum += p[i].second;
      continue;
    }
    ans = ans * (R ^ (p[i].first - now));
    now = p[i].first;
    for (int j = 1; j < (1 << k); j += 2)
      if (f[j])
        for (int k = 1; k <= cnt; k++) ans.A[k][f[j]] += p[i].second;
  }
  ans = ans * (R ^ (n - x + 1 - now));
  cout << ans.A[1][1] + sum << endl;
  return 0;
}
