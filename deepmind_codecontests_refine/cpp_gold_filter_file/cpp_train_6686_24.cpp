#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int maxm = 2e4 + 5;
int a[maxn][maxm], dp[maxm], nxt[maxm], sum[maxn][maxm];
int n, m, k;
int w[maxm * 4], f[maxm * 4];
void push(int k) {
  if (f[k]) {
    f[k << 1] += f[k], f[k << 1 | 1] += f[k];
    w[k << 1] += f[k], w[k << 1 | 1] += f[k];
    f[k] = 0;
  }
}
void up(int k) { w[k] = max(w[k << 1], w[k << 1 | 1]); }
void build(int k, int l, int r) {
  if (l == r) {
    w[k] = dp[l], f[k] = 0;
    return;
  }
  w[k] = f[k] = 0;
  int mid = l + r >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  up(k);
}
void change(int k, int l, int r, int val, int a, int b) {
  if (a <= l && r <= b) {
    w[k] += val, f[k] += val;
    return;
  }
  push(k);
  int mid = l + r >> 1;
  if (a <= mid) change(k << 1, l, mid, val, a, b);
  if (b > mid) change(k << 1 | 1, mid + 1, r, val, a, b);
  up(k);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i <= n - 1; i++)
    for (int j = 0; j <= m - 1; j++) cin >> a[i][j];
  for (int i = 0; i <= n - 1; i++)
    for (int j = 0; j <= k - 1; j++) sum[i][0] += a[i][j];
  for (int i = 0; i <= n - 1; i++)
    for (int j = 1; j <= m - k; j++)
      sum[i][j] = sum[i][j - 1] + a[i][j + k - 1] - a[i][j - 1];
  for (int i = 0; i <= m - k; i++) nxt[i] = sum[0][i] + sum[1][i];
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 0; j <= m - k; j++) dp[j] = nxt[j], nxt[j] = 0;
    int tmp = 0;
    for (int j = k - 1; j >= 0; j--) {
      tmp += a[i][j];
      dp[j] -= tmp;
    }
    build(1, 0, m - k);
    for (int j = 0; j <= m - k; j++) {
      nxt[j] = w[1] + sum[i][j] + sum[i + 1][j];
      change(1, 0, m - k, a[i][j], max(0, j - k + 1), j);
      change(1, 0, m - k, -a[i][j + k], j + 1, min(j + k, m - k));
    }
  }
  int res = 0;
  for (int i = 0; i <= m - k; i++) res = max(res, nxt[i]);
  cout << res << "\n";
}
