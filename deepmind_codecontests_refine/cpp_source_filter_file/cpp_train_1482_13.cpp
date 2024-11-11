#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int maxm = 2e4 + 10;
const int maxk = 25;
int a[maxn][maxm];
int rsum[maxn][maxm];
int dp[maxn][maxm], tmp[maxm];
int lazy[maxm << 2], seg[maxm << 2];
int get_val(int v) { return seg[v] + lazy[v]; }
void pushup(int v) { seg[v] = max(get_val(v << 1), get_val(v << 1 | 1)); }
void pushdown(int v) {
  lazy[v << 1] += lazy[v];
  lazy[v << 1 | 1] += lazy[v];
  lazy[v] = 0;
}
void build(int l, int r, int v, int *arr) {
  lazy[v] = 0;
  if (l == r) {
    seg[v] = arr[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, v << 1, arr);
  build(mid + 1, r, v << 1 | 1, arr);
  pushup(v);
}
int ask(int l, int r, int ql, int qr, int v) {
  if (l > qr || ql > qr || ql > r) return 0;
  if (ql <= l && r <= qr) return get_val(v);
  int mid = (l + r) >> 1, res = 0;
  pushdown(v);
  if (ql <= mid) res = max(res, ask(l, mid, ql, qr, v << 1));
  if (qr > mid) res = max(res, ask(mid + 1, r, ql, qr, v << 1 | 1));
  pushup(v);
  return res;
}
void update(int l, int r, int ql, int qr, int v, int val) {
  if (l > qr || ql > qr || ql > r) return;
  if (ql <= l && r <= qr) {
    lazy[v] += val;
    return;
  }
  pushdown(v);
  int mid = (l + r) >> 1;
  if (ql <= mid) update(l, mid, ql, qr, v << 1, val);
  if (qr > mid) update(mid + 1, r, ql, qr, v << 1 | 1, val);
  pushup(v);
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      rsum[i][j] = a[i][j] + rsum[i][j - 1];
    }
  }
  for (int i = 1; i <= m - k + 1; ++i)
    dp[1][i] = rsum[1][i + k - 1] - rsum[1][i - 1] + rsum[2][i + k - 1] -
               rsum[2][i - 1];
  for (int i = 1; i <= n; ++i) {
    build(1, m, 1, dp[i]);
    for (int j = 1; j <= m - k + 1; ++j) {
      update(1, m, j, j, 1, -rsum[i + 1][j + k - 1] + rsum[i + 1][j - 1]);
      dp[i + 1][j] =
          max(dp[i + 1][j], ask(1, m, max(1, j - k + 1), j, 1) +
                                rsum[i + 1][j + k - 1] - rsum[i + 1][j - 1]);
      update(1, m, max(1, j - k + 1), j, 1, a[i + 1][j]);
    }
    build(1, m, 1, dp[i]);
    for (int j = 1; j <= m; ++j) {
      update(1, m, max(1, j - k + 1), j, 1, -a[i + 1][j]);
      if (j >= k)
        dp[i + 1][j - k + 1] =
            max(dp[i + 1][j - k + 1], ask(1, m, j - k + 1, j, 1) +
                                          rsum[i + 1][j] - rsum[i + 1][j - k]);
    }
    for (int j = 1; j <= m; ++j) tmp[j] = max(tmp[j - 1], dp[i][j]);
    for (int j = k + 1; j <= m; ++j) {
      int l = j, r = k - 1 + l;
      dp[i + 1][j] =
          max(dp[i + 1][j], tmp[j - k] + rsum[i + 1][r] - rsum[i + 1][l - 1]);
    }
    for (int j = m; j >= 1; --j) tmp[j] = max(tmp[j + 1], dp[i][j]);
    for (int j = m - k; j >= 1; --j) {
      int l = j, r = k - 1 + l;
      dp[i + 1][j] =
          max(dp[i + 1][j], tmp[j + k] + rsum[i + 1][r] - rsum[i + 1][l - 1]);
    }
    for (int j = 1; j <= m - k + 1; ++j)
      dp[i + 1][j] += rsum[i + 2][j + k - 1] - rsum[i + 2][j - 1];
  }
  printf("%d\n", *max_element(dp[n] + 1, dp[n] + 1 + m));
  return 0;
}
