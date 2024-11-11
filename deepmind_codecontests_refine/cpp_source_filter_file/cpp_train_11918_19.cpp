#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int h[N], d[N], n;
int64_t disl[N], la[N], l[N];
int64_t disr[N], ra[N], r[N];
int64_t st1[N][20], st2[N][20];
void preprocess() {
  int i, j;
  for (j = 1; (1 << j) <= n; j++) {
    for (i = 0; i + (1 << j) - 1 < n; i++) {
      int t1 = st1[i][j - 1], t2 = st1[i + (1 << (j - 1))][j - 1];
      st1[i][j] = (2 * h[t1] + disl[t1] > 2 * h[t2] + disl[t2]) ? t1 : t2;
    }
  }
  for (j = 1; (1 << j) <= n; j++) {
    for (i = 0; i + (1 << j) - 1 < n; i++) {
      st2[i][j] = max(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int ql, qr;
int64_t query(int l, int r) {
  if (l >= r || l < 0 || r >= n) return 0LL;
  int lg = log2(r - l + 1), ind, t1, t2;
  int64_t temp = 0;
  t1 = st1[l][lg], t2 = st1[r - (1 << lg) + 1][lg];
  ind = (2 * h[t1] + disl[t1] > 2 * h[t2] + disl[t2]) ? t1 : t2;
  if (ind > ql) {
    lg = log2(ind - ql);
    temp = max(st2[ql][lg], st2[ind - (1 << lg)][lg]);
    temp += 2 * h[ind] + disl[ind];
  }
  return max(temp, query(ind + 1, r));
}
int main() {
  int m, i;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &d[i]);
    if (i) disl[i] = disl[i - 1] + (int64_t)d[i - 1];
  }
  for (i = 0; i < n; i++) scanf("%d", &h[i]);
  int64_t temp = 2LL * h[0];
  l[0] = temp;
  st2[0][0] = temp;
  for (i = 1; i < n; i++) {
    la[i] = max(la[i - 1], 2 * h[i] + disl[i] + temp);
    temp = max(temp, 2 * h[i] - disl[i]);
    l[i] = max(l[i - 1], 2 * h[i] + disl[i]);
    st1[i][0] = i;
    st2[i][0] = 2 * h[i] - disl[i];
  }
  preprocess();
  disr[n - 1] = 0;
  for (i = n - 2; i >= 0; i--) {
    disr[i] = disr[i + 1] + d[i];
  }
  temp = 2 * h[n - 1];
  r[n - 1] = temp;
  for (i = n - 2; i >= 0; i--) {
    ra[i] = max(ra[i + 1], 2 * h[i] + disr[i] + temp);
    temp = max(temp, 2 * h[i] - disr[i]);
    r[i] = max(r[i + 1], 2 * h[i] + disr[i]);
  }
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int64_t ans = 0;
    if (a > b) {
      ql = b, qr = a - 2;
      printf("%I64d\n", query(b, a - 2));
      continue;
    }
    if (a - 2 >= 0) ans = max(ans, la[a - 2]);
    if (b < n) ans = max(ans, ra[b]);
    if (a - 2 >= 0 && b < n) ans = max(ans, l[a - 2] + r[b] + d[n - 1]);
    printf("%I64d\n", ans);
  }
}
