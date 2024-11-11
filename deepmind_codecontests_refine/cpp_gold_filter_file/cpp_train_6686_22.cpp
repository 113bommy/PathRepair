#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int a[52][20002], psum[52][20002], dp[52][20002];
int segTree[20002 * 4], lazy[20002 * 4];
void setlazy(int ptr, int s, int e) {
  segTree[ptr] += lazy[ptr];
  if (s != e) {
    lazy[ptr * 2] += lazy[ptr];
    lazy[ptr * 2 + 1] += lazy[ptr];
  }
  lazy[ptr] = 0;
}
void update(int ptr, int s, int e, int l, int r, int val) {
  if (lazy[ptr]) setlazy(ptr, s, e);
  if (r < s || e < l) return;
  if (l <= s && e <= r) {
    segTree[ptr] += val;
    if (s != e) {
      lazy[ptr * 2] += val;
      lazy[ptr * 2 + 1] += val;
    }
    return;
  }
  update(ptr * 2, s, (s + e) / 2, l, r, val);
  update(ptr * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
  segTree[ptr] = max(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}
int getVal(int ptr, int s, int e, int l, int r) {
  if (r < s || e < l) return 0;
  if (l <= s && e <= r) return segTree[ptr];
  return max(getVal(ptr * 2, s, (s + e) / 2, l, r),
             getVal(ptr * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      psum[i][j] = psum[i][j - 1] + a[i][j];
    }
  }
  m = m - k + 1;
  for (int i = 1; i <= m; i++)
    dp[1][i] = psum[1][i + k - 1] - psum[1][i - 1] + psum[2][i + k - 1] -
               psum[2][i - 1];
  for (int i = 2; i <= n; i++) {
    memset(segTree, 0, sizeof segTree);
    memset(lazy, 0, sizeof lazy);
    for (int j = 1; j <= m; j++) update(1, 1, m, j, j, dp[i - 1][j]);
    for (int j = 1; j <= k; j++) update(1, 1, m, 1, j, -a[i][j]);
    for (int j = 1; j <= m; j++) {
      int res = getVal(1, 1, m, 1, m);
      dp[i][j] = res + psum[i][j + k - 1] - psum[i][j - 1] +
                 psum[i + 1][j + k - 1] - psum[i + 1][j - 1];
      if (j != m) {
        update(1, 1, m, max(1, j - k + 1), j, a[i][j]);
        update(1, 1, m, j + 1, j + 1 + k - 1, -a[i][j + k]);
      }
    }
  }
  cout << *max_element(dp[n] + 1, dp[n] + m + 1) << "\n";
}
