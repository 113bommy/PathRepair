#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, m, c[N + 9];
void Add(int p, int v) {
  for (; p <= n; p += p & -p) c[p] += v;
}
int Query(int p) {
  int res = 0;
  for (; p; p -= p & -p) res += c[p];
  return res;
}
void into() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    Add(l, 1);
    Add(r + 1, -1);
  }
}
int a[N + 9];
void Get_a() {
  for (int i = 1; i <= n; ++i) a[i] = Query(i);
}
int tr[N * 4 + 9];
void Build(int l, int r, int k) {
  tr[k] = 0;
  if (l == r) return;
  int mid = l + r >> 1;
  Build(l, mid, k << 1);
  Build(mid + 1, r, k << 1 | 1);
}
void Change(int p, int v, int l, int r, int k) {
  if (l == r) {
    tr[k] = max(tr[k], v);
    return;
  }
  int mid = l + r >> 1;
  p <= mid ? Change(p, v, l, mid, k << 1)
           : Change(p, v, mid + 1, r, k << 1 | 1);
  tr[k] = max(tr[k << 1], tr[k << 1 | 1]);
}
int Query_max(int L, int R, int l, int r, int k) {
  if (L <= l && R >= r) return tr[k];
  int mid = l + r >> 1, res = 0;
  if (L <= mid) res = max(res, Query_max(L, R, l, mid, k << 1));
  if (R > mid) res = max(res, Query_max(L, R, mid + 1, r, k << 1 | 1));
  return res;
}
int dp[2][N + 9], ans;
void Get_dp() {
  Build(0, m, 1);
  for (int i = 1; i <= n; ++i) {
    dp[0][i] = Query_max(0, a[i], 0, m, 1) + 1;
    Change(a[i], dp[0][i], 0, m, 1);
  }
  Build(0, m, 1);
  for (int i = n; i >= 1; --i) {
    dp[1][i] = Query_max(0, a[i], 0, m, 1) + 1;
    Change(a[i], dp[1][i], 0, m, 1);
    ans = max(ans, dp[0][i] + dp[1][i] - 1);
  }
}
void work() {
  Get_a();
  Get_dp();
}
void outo() { printf("%d\n", ans); }
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
