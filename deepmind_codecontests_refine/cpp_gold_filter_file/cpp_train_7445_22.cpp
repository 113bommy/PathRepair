#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], k, val, tans;
int siz[N], f[N], b[N], _n;
vector<int> v[N];
void upd(int &x, int &y, int z) {
  if (z > x) {
    y = x;
    x = z;
    return;
  }
  if (z == x) {
    y = x;
    return;
  }
  if (y <= z && z < x) {
    y = z;
    return;
  }
}
void dfs(int x, int fa) {
  int l = v[x].size() - 1, y;
  int m_1 = 0, m_2 = 0;
  siz[x] = 1;
  f[x] = 0;
  for (register int i = (0); i <= (l); ++i) {
    y = v[x][i];
    if (y == fa) continue;
    dfs(y, x);
    siz[x] += siz[y];
    if (f[y] == siz[y])
      f[x] += siz[y];
    else
      upd(m_1, m_2, f[y]);
  }
  f[x] = (f[x] + m_1 + 1) * (a[x] >= val);
  tans = max(tans, f[x] + m_2);
}
int rt = 1;
bool check(int x) {
  tans = 0;
  val = x;
  dfs(rt, 0);
  return tans >= k;
}
signed main() {
  int x, y;
  scanf("%d %d", &n, &k);
  for (register int i = (1); i <= (n); ++i) {
    scanf("%d", &a[i]), b[++_n] = a[i];
    if (a[rt] > a[i]) rt = i;
  }
  for (register int i = (2); i <= (n); ++i) {
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  sort(b + 1, b + 1 + _n);
  _n = unique(b + 1, b + 1 + _n) - (b + 1);
  int l = 1, r = _n, mid, ans = -1;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(b[mid]))
      l = mid + 1, ans = b[mid];
    else
      r = mid - 1;
  }
  printf("%d\n", ans);
  return 0;
}
