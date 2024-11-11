#include <bits/stdc++.h>
using namespace std;
int s[50500][11];
unordered_map<int, int> pos;
int roth[50500][11];
int loth[50500][11];
const int mx = 1 << 16;
array<vector<int>, 11> ltree, lflag, rtree, rflag;
vector<int> cnttree(2 * mx), cntflag(2 * mx);
void push(vector<int> &tree, vector<int> &flag, int i, int l, int r) {
  if (flag[i]) {
    tree[i << 1] = tree[i << 1 | 1] = tree[i];
    flag[i << 1] = flag[i << 1 | 1] = 1;
  }
  flag[i] = 0;
}
int query(vector<int> &tree, vector<int> &flag, int i, int l, int r, int u,
          int v) {
  if (u <= l && r <= v) return tree[i];
  push(tree, flag, i, l, r);
  int mid = (l + r) / 2;
  int lans = 0, rans = 0;
  if (u < mid) lans = query(tree, flag, i << 1, l, mid, u, v);
  if (mid < v) rans = query(tree, flag, i << 1 | 1, mid, r, u, v);
  tree[i] = tree[i << 1] + tree[i << 1 | 1];
  return lans + rans;
}
void range_update(vector<int> &tree, vector<int> &flag, int i, int l, int r,
                  int u, int v, int val) {
  if (u <= l && r <= v) {
    tree[i] = val;
    flag[i] = 1;
    return;
  }
  push(tree, flag, i, l, r);
  int mid = (l + r) / 2;
  if (u < mid) range_update(tree, flag, i << 1, l, mid, u, v, val);
  if (mid < v) range_update(tree, flag, i << 1 | 1, mid, r, u, v, val);
  tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
int getrnk(int j, int v) {
  return query(ltree[j], lflag[j], 1, mx, 2 * mx, mx, mx + v + 1) +
         query(rtree[j], rflag[j], 1, mx, 2 * mx, mx, mx + v + 1);
}
void insrt(int j, int x) {
  range_update(ltree[j], lflag[j], 1, mx, 2 * mx, mx + x, mx + x + 1, 1);
  range_update(rtree[j], rflag[j], 1, mx, 2 * mx, mx + x, mx + x + 1, 1);
}
int getpos(int j, int rnk) {
  int l = -1, r = mx;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (getrnk(j, mid) < rnk)
      l = mid;
    else
      r = mid;
  }
  return r;
}
int main() {
  fill((ltree).begin(), (ltree).end(), vector<int>(2 * mx));
  fill((rtree).begin(), (rtree).end(), vector<int>(2 * mx));
  fill((lflag).begin(), (lflag).end(), vector<int>(2 * mx));
  fill((rflag).begin(), (rflag).end(), vector<int>(2 * mx));
  int n, k;
  scanf("%d%d", &(n), &(k));
  int topr = -1, topcnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) scanf("%d", &(s[i][j]));
  }
  for (int j = 1; j <= k; j++) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = s[i][j];
    sort((v).begin(), (v).end());
    pos.clear();
    for (int i = 0; i < n; i++) pos[v[i]] = i;
    for (int i = 0; i < n; i++) s[i][j] = pos[s[i][j]];
  }
  for (int i = 0; i < n; i++) {
    int minrnk = INT_MAX, maxrnk = -1;
    for (int j = 1; j <= k; j++) {
      int rnk = getrnk(j, s[i][j]);
      minrnk = min(minrnk, rnk);
      maxrnk = max(maxrnk, rnk);
    }
    if (minrnk == maxrnk && minrnk % 2 == 0) {
      int r = s[i][1];
      if (r > topr) {
        topr = r;
        topcnt = 1;
      }
      for (int j = 1; j <= k; j++) {
        insrt(j, s[i][j]);
        loth[r][j] = s[i][j];
        roth[r][j] = s[i][j];
      }
      range_update(cnttree, cntflag, 1, mx, 2 * mx, mx + r, mx + r + 1, 1);
    } else {
      if (minrnk % 2 == 0) minrnk++;
      if (maxrnk % 2 == 1) maxrnk++;
      int oldl = getpos(1, minrnk);
      int oldr = getpos(1, maxrnk);
      int cnt = 0;
      cnt = query(cnttree, cntflag, 1, mx, 2 * mx, mx + oldl, mx + oldr + 1);
      cnt++;
      int newl = min(oldl, s[i][1]);
      int newr = max(oldr, s[i][1]);
      for (int j = 1; j <= k; j++) {
        int l = loth[oldl][j];
        int r = roth[oldr][j];
        loth[oldl][j] = roth[oldr][j] = 0;
        range_update(ltree[j], lflag[j], 1, mx, 2 * mx, mx + l, mx + r + 1, 0);
        range_update(rtree[j], rflag[j], 1, mx, 2 * mx, mx + l, mx + r + 1, 0);
        l = min(l, s[i][j]);
        r = max(r, s[i][j]);
        loth[newl][j] = l;
        roth[newr][j] = r;
        range_update(ltree[j], lflag[j], 1, mx, 2 * mx, mx + l, mx + l + 1, 1);
        range_update(rtree[j], rflag[j], 1, mx, 2 * mx, mx + r, mx + r + 1, 1);
      }
      range_update(cnttree, cntflag, 1, mx, 2 * mx, mx + s[i][1],
                   mx + s[i][1] + 1, 1);
      if (newr >= topr) {
        topr = newr;
        topcnt = cnt;
      }
    }
    printf("%d\n", topcnt);
  }
  return 0;
}
