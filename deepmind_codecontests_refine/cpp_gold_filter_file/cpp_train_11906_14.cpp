#include <bits/stdc++.h>
using namespace std;
template <typename T>
T read1() {
  T t = 0;
  char k;
  bool vis = 0;
  do (k = getchar()) == '-' && (vis = 1);
  while ('0' > k || k > '9');
  while ('0' <= k && k <= '9')
    t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
  return vis ? -t : t;
}
int s, m, q, ans[600005], id[600005], qd[600005];
char str[505][505];
bitset<505> a[505][505], c[505][505];
struct {
  int x, y, a, b;
} b[600005];
void solve(int l, int r, int ql, int qr) {
  if (l > r || ql > qr) return;
  int mid = l + r >> 1;
  for (int i = s; i; --i)
    if (str[i][mid] == '.') {
      a[i][mid].reset();
      a[i][mid][i] = 1;
      a[i][mid] |= a[i + 1][mid];
    }
  for (int i = 1; i <= s; ++i)
    if (str[i][mid] == '.') {
      c[i][mid].reset();
      c[i][mid][i] = 1;
      c[i][mid] |= c[i - 1][mid];
    }
  for (int i = s; i; --i)
    for (int j = mid - 1; j >= l; --j)
      if (str[i][j] == '.') a[i][j] = a[i][j + 1] | a[i + 1][j];
  for (int i = 1; i <= s; ++i)
    for (int j = mid + 1; j <= r; ++j)
      if (str[i][j] == '.') c[i][j] = c[i][j - 1] | c[i - 1][j];
  int xl = ql - 1, xr = qr + 1;
  for (int i = ql; i <= qr; ++i)
    if (b[id[i]].b <= mid && b[id[i]].y >= mid)
      ans[id[i]] =
          (a[b[id[i]].a][b[id[i]].b] & c[b[id[i]].x][b[id[i]].y]).any();
    else if (b[id[i]].y < mid)
      qd[++xl] = id[i];
    else
      qd[--xr] = id[i];
  if (ql <= xl) memcpy(id + ql, qd + ql, xl - ql + 1 << 2);
  if (xr <= qr) memcpy(id + xr, qd + xr, qr - xr + 1 << 2);
  solve(l, mid - 1, ql, xl);
  solve(mid + 1, r, xr, qr);
}
int main() {
  s = read1<long long>(), m = read1<long long>();
  for (int i = 1; i <= s; ++i) scanf("%s", str[i] + 1);
  int q = read1<long long>();
  for (int i = 1; i <= q; id[i] = i, ++i)
    b[i].a = read1<long long>(), b[i].b = read1<long long>(),
    b[i].x = read1<long long>(), b[i].y = read1<long long>();
  solve(1, m, 1, q);
  for (int i = 1; i <= q; ++i) puts(ans[i] ? "Yes" : "No");
  return 0;
}
