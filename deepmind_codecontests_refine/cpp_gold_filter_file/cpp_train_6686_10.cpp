#include <bits/stdc++.h>
using namespace std;
const int N = 53;
const int M = 20005;
int ar[N][M];
int dp[N][M];
int tmp[M];
int seg[M * 4], lazy[M * 4];
int a[N];
void init(int pos, int l, int r) {
  lazy[pos] = 0;
  seg[pos] = 0;
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  init(pos * 2, l, mid);
  init(pos * 2 + 1, mid + 1, r);
}
void push(int pos, int l, int r) {
  if (lazy[pos] != 0) {
    seg[pos] += lazy[pos];
    if (l != r) {
      lazy[pos * 2] += lazy[pos];
      lazy[pos * 2 + 1] += lazy[pos];
    }
    lazy[pos] = 0;
  }
}
void update(int pos, int l, int r, int ql, int qr, int val) {
  push(pos, l, r);
  if (r < ql || qr < l) {
    return;
  }
  if (ql <= l && r <= qr) {
    lazy[pos] = val;
    push(pos, l, r);
    return;
  }
  int mid = (l + r) / 2;
  update(pos * 2, l, mid, ql, qr, val);
  update(pos * 2 + 1, mid + 1, r, ql, qr, val);
  seg[pos] = max(seg[pos * 2], seg[pos * 2 + 1]);
}
int query(int pos, int l, int r, int ql, int qr) {
  push(pos, l, r);
  if (r < ql || qr < l) {
    return 0;
  }
  if (ql <= l && r <= qr) {
    return seg[pos];
  }
  int mid = (l + r) / 2;
  return max(query(pos * 2, l, mid, ql, qr),
             query(pos * 2 + 1, mid + 1, r, ql, qr));
}
void solve() {
  int n, m, k;
  scanf("%d %d %d ", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d ", &ar[i][j]);
      ar[i][j] += ar[i][j - 1];
    }
  }
  for (int i = 1; i + k - 1 <= m; ++i) {
    dp[1][i] = ar[1][i + k - 1] - ar[1][i - 1];
    dp[1][i] += ar[2][i + k - 1] - ar[2][i - 1];
  }
  for (int i = 2; i <= n; ++i) {
    tmp[0] = 0;
    for (int j = 1; j + k - 1 <= m; ++j) {
      tmp[j] = max(tmp[j - 1], dp[i - 1][j]);
    }
    int sufVal = 0;
    init(1, 1, m);
    for (int j = m - k + 1; j; --j) {
      int vv = sufVal;
      if (j - 1 - k + 1 >= 0) {
        vv = max(vv, tmp[j - k]);
      }
      dp[i][j] = ar[i + 1][j + k - 1] - ar[i + 1][j - 1] + vv +
                 ar[i][j + k - 1] - ar[i][j - 1];
      int ad = ar[i + 1][j + k - 1] - ar[i + 1][j - 1] + ar[i][j + k - 1] -
               ar[i][j - 1];
      if (j + k <= m)
        update(1, 1, m, j + 1, m, ar[i][j + k] - ar[i][j + k - 1]);
      update(1, 1, m, j, j, dp[i - 1][j] - ar[i][j + k - 1] + ar[i][j - 1]);
      dp[i][j] =
          max(dp[i][j], query(1, 1, m, j, min(j + k - 1, m - k + 1)) + ad);
      sufVal = max(sufVal, dp[i - 1][j + k - 1]);
    }
    init(1, 1, m);
    for (int j = 1; j + k - 1 <= m; ++j) {
      int ad = ar[i + 1][j + k - 1] - ar[i + 1][j - 1] + ar[i][j + k - 1] -
               ar[i][j - 1];
      if (j - 1 >= 1) update(1, 1, m, 1, j - 1, ar[i][j - 1] - ar[i][j - 2]);
      update(1, 1, m, j, j, dp[i - 1][j] - ar[i][j + k - 1] + ar[i][j - 1]);
      dp[i][j] = max(dp[i][j], query(1, 1, m, max(1, j - k + 1), j) + ad);
    }
  }
  int ret = 0;
  for (int i = 1; i + k - 1 <= m; ++i) {
    ret = max(ret, dp[n][i]);
  }
  printf("%d\n", ret);
}
int main() {
  solve();
  return 0;
}
