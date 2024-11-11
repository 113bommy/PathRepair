#include <bits/stdc++.h>
using namespace std;
const int maxn = 120000;
const int INF = 0x3fffffff;
struct Seg {
  int l, r;
  int maxx, minn;
} seg[maxn << 2];
int fa[maxn], arr[maxn], st[maxn];
int n, a;
map<int, int> dt;
map<int, int> dp;
void build(int l, int r, int n) {
  seg[n].l = l;
  seg[n].r = r;
  seg[n].maxx = 0;
  seg[n].minn = INF;
  if (l == r) return;
  int m = (l + r) >> 1;
  build(l, m, n << 1);
  build(m + 1, r, n << 1 | 1);
  return;
}
void insertval(int x, int d, int n) {
  if (seg[n].l == seg[n].r && seg[n].l == x) {
    seg[n].maxx = d;
    seg[n].minn = d;
    return;
  }
  int m = (seg[n].l + seg[n].r) >> 1;
  if (x <= m)
    insertval(x, d, n << 1);
  else
    insertval(x, d, n << 1 | 1);
  seg[n].maxx = max(seg[n << 1].maxx, seg[n << 1 | 1].maxx);
  seg[n].minn = min(seg[n << 1].minn, seg[n << 1 | 1].minn);
  return;
}
int querymax(int l, int r, int n) {
  if (seg[n].l >= l && seg[n].r <= r) return seg[n].maxx;
  int m = (seg[n].l + seg[n].r) >> 1;
  if (r <= m)
    return querymax(l, r, n << 1);
  else if (l >= m + 1)
    return querymax(l, r, n << 1 | 1);
  else
    return max(querymax(l, m, n << 1), querymax(m + 1, r, n << 1 | 1));
}
int querymin(int l, int r, int n) {
  if (seg[n].l >= l && seg[n].r <= r) return seg[n].minn;
  int m = (seg[n].l + seg[n].r) >> 1;
  if (r <= m)
    return querymin(l, r, n << 1);
  else if (l >= m + 1)
    return querymin(l, r, n << 1 | 1);
  else
    return min(querymin(l, m, n << 1), querymin(m + 1, r, n << 1 | 1));
}
int main() {
  scanf("%d", &n);
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    st[i] = arr[i];
  }
  sort(st + 1, st + n + 1);
  for (int i = 1; i <= n; i++) dt[st[i]] = i;
  a = dt[arr[1]];
  insertval(a, a, 1);
  dp[a] = 1;
  for (int i = 2; i <= n; i++) {
    a = dt[arr[i]];
    int mx = querymax(1, a, 1);
    int mi = querymin(a, n, 1);
    if (dp[mx] >= dp[mi]) {
      fa[i] = mx;
      dp[a] = dp[mx] + 1;
    } else {
      fa[i] = mi;
      dp[a] = dp[mi] + 1;
    }
    insertval(a, a, 1);
  }
  for (int i = 2; i <= n; i++) {
    printf("%d", st[fa[i]]);
    if (i != n)
      putchar(' ');
    else
      putchar('\n');
  }
  return 0;
}
