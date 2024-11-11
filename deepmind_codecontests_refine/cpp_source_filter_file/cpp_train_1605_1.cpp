#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], sl[maxn], sr[maxn];
int sql[maxn], sqr[maxn];
int main() {
  ios::sync_with_stdio(false);
  int n, l, r, ql, qr;
  int ans = 0, tmp;
  scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
  for (int i = 1; i < n + 1; ++i) scanf("%d", &a[i]);
  int i, j, k;
  int n_ = n / 2;
  sql[0] = sqr[0] = 0;
  sl[0] = sr[0] = 0;
  for (i = 1; i <= n; ++i) {
    sql[i] = sql[i - 1] + ql;
    sqr[i] = sqr[i - 1] + qr;
    sl[i] = sl[i - 1] + a[i] * l;
  }
  for (i = n, j = 1; i > 0; ++j, --i) sr[j] = sr[j - 1] + a[i] * r;
  if (l == r) {
    ans = sl[n];
  } else if (l < r) {
    ans = INT_MAX;
    for (k = 0; k <= n_; ++k) {
      j = n - k - k - 1;
      j = (j < 0) ? 0 : j;
      tmp = sr[k] + sl[n - k] + ql * j;
      ans = min(tmp, ans);
    }
  } else {
    ans = INT_MAX;
    for (k = 0; k < n_; ++k) {
      j = n - k - k - 1;
      j = (j < 0) ? 0 : j;
      tmp = sl[k] + sr[n - k] + qr * j;
      ans = min(tmp, ans);
    }
  }
  printf("%d\n", ans);
  return 0;
}
