#include <bits/stdc++.h>
using namespace std;
const int N = 4100, M = 66000, lim = 2.2e6 + 1;
int a[N], ans[M], n, m, k, L[M], R[M], _l[N], _r[N], b[N], g[N], d[N];
int tmp[N], L0[N], R0[N], L1[N], R1[N];
int A[300][300], B[300][300];
int U[lim], V[lim];
inline int merge(int x, int y) {
  if (!x || !y) return x | y;
  ++k;
  U[k] = x, V[k] = y;
  return k;
}
void solve(int l, int r) {
  if (l == r) {
    int x = b[d[l]];
    A[x][x] = d[l];
    return;
  }
  const int mid = (l + r) / 2;
  solve(l, mid), solve(mid + 1, r);
  int i = l, j = mid + 1, t = 0;
  while (i <= mid && j <= r)
    if (d[i] < d[j])
      tmp[++t] = d[i++];
    else
      tmp[++t] = d[j++];
  while (i <= mid) tmp[++t] = d[i++];
  while (j <= r) tmp[++t] = d[j++];
  i = l, j = mid + 1;
  for (int x = 1; x <= t; ++x) {
    while (i <= mid && d[i] < tmp[x]) ++i;
    while (j <= r && d[j] < tmp[x]) ++j;
    L0[x] = i <= mid ? b[d[i]] : 299, L1[x] = j <= r ? b[d[j]] : 299;
  }
  i = mid, j = r;
  for (int x = t; x; --x) {
    while (i >= l && d[i] > tmp[x]) --i;
    while (j > mid && d[j] > tmp[x]) --j;
    R0[x] = i >= l ? b[d[i]] : 0, R1[x] = j > mid ? b[d[j]] : 0;
  }
  for (i = 1; i <= t; ++i)
    for (j = i; j <= t; ++j)
      B[b[tmp[i]]][b[tmp[j]]] = merge(A[L0[i]][R0[j]], A[L1[i]][R1[j]]);
  for (i = 1; i <= t; ++i)
    for (j = i; j <= t; ++j) A[b[tmp[i]]][b[tmp[j]]] = B[b[tmp[i]]][b[tmp[j]]];
  for (i = l; i <= r; ++i) d[i] = tmp[i - l + 1];
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m, k = n;
  for (int i = 1, x; i <= n; ++i) cin >> x, a[x] = g[x] = i;
  for (int i = 1; i <= m; ++i) cin >> L[i] >> R[i];
  for (int l = 1, r = 256; l <= n; l += 256, r += 256) {
    r = min(r, n);
    int len = r - l + 1;
    sort(g + l, g + r + 1);
    for (int i = l; i <= r; ++i) b[g[i]] = i - l + 1;
    for (int i = l; i <= r; ++i) d[i - l + 1] = a[i];
    solve(1, n);
    for (int i = 1, it = 1; i <= n; ++i) {
      while (it <= len && d[it] < i) ++it;
      _l[i] = it;
    }
    for (int i = n, it = len; i; --i) {
      while (it && d[it] > i) --it;
      _r[i] = it;
    }
    for (int i = 1; i <= m; ++i) ans[i] = merge(ans[i], A[_l[L[i]]][_r[R[i]]]);
  }
  cout << k << '\n';
  for (int i = n + 1; i <= k; ++i) cout << U[i] << ' ' << V[i] << '\n';
  for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i == m];
  return 0;
}
