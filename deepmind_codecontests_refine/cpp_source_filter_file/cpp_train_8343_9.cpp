#include <bits/stdc++.h>
using namespace std;
const int mxn = (2e5) + 5;
long long a[mxn];
int n, m;
vector<pair<int, int> > v[mxn];
long long st[mxn * 4];
long long laz[mxn * 4];
long long arr[mxn];
void pros(int p, int l, int r) {
  st[p] += laz[p];
  if (l != r) {
    laz[p * 2] += laz[p];
    laz[p * 2 + 1] += laz[p];
  }
  laz[p] = 0;
}
void udp(int p, int l, int r, int i, int j, int x) {
  pros(p, l, r);
  if (r < i || l > j) return;
  if (l >= i && r <= j) {
    laz[p] = x;
    pros(p, l, r);
    return;
  }
  int md = (l + r) / 2;
  udp(p * 2, l, md, i, j, x);
  udp(p * 2 + 1, md + 1, r, i, j, x);
  st[p] = max(st[p * 2], st[p * 2 + 1]);
}
long long rmq(int p, int l, int r, int i, int j) {
  pros(p, l, r);
  if (r < i || l > j) return 0;
  if (l >= i && r <= j) return st[p];
  int md = (l + r) / 2;
  long long x = rmq(p * 2, l, md, i, j);
  long long y = rmq(p * 2 + 1, md + 1, r, i, j);
  return max(x, y);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m; ++i) {
    int l, r, p;
    scanf("%d%d%d", &l, &r, &p);
    v[r].push_back(make_pair(l, p));
  }
  long long dp = 0;
  for (int r = 1; r <= n; ++r) {
    udp(1, 1, n, 1, r, -a[r]);
    for (int j = 0; j < v[r].size(); ++j)
      udp(1, 1, n, 1, v[r][j].first, v[r][j].second);
    dp = max(dp, rmq(1, 1, n, 1, r));
    udp(1, 1, n, r + 1, r + 1, dp);
  }
  printf("%I64d\n", dp);
  return 0;
}
