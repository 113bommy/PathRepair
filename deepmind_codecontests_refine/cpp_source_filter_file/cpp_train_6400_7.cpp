#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 123;
int n;
int q;
int a[maxn];
long long val[maxn], sum[maxn], t[maxn * 4];
void upd(int v, int tl, int tr, int pos, long long val) {
  if (!pos) return;
  if (tl == tr) {
    t[v] = val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    upd(v + v, tl, tm, pos, val);
  else
    upd(v + v + 1, tm + 1, tr, pos, val);
  t[v] = min(t[v + v], t[v + v + 1]);
}
int get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 1e9;
  if (tl == l && tr == r) return t[v];
  int tm = (tl + tr) / 2;
  return min(get(v + v, tl, tm, l, min(tm, r)),
             get(v + v + 1, tm + 1, tr, max(tm + 1, l), r));
}
map<int, int> mp;
vector<pair<int, int> > g[maxn];
int last[maxn];
int res[maxn];
int k;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mp[a[i]] = 1;
  }
  int sz = 0;
  for (int i = 0; i < 1e6; i++) t[i] = 1e9;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    it->second = ++sz;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
  }
  for (int i = 1; i <= k; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    g[r].push_back(make_pair(l, i));
  }
  for (int i = 1; i <= n; i++) {
    int diff = i - last[a[i]];
    upd(1, 1, n, last[a[i]], diff);
    last[a[i]] = i;
    for (int j = 0; j < g[i].size(); j++)
      res[g[i][j].second] = get(1, 1, n, g[i][j].first, i);
  }
  for (int i = 1; i <= k; i++) printf("%d\n", ((res[i] > 1e8) ? -1 : res[i]));
  return 0;
}
