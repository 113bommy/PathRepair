#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int top;
long long res;
long long ans[maxn];
int prt[maxn * 2], siz[maxn * 2][2];
pair<int, int> sta[maxn];
map<pair<int, int>, int> mp;
struct node {
  int l, r;
  vector<pair<int, int> > v;
} tree[maxn * 4];
void build(int k, int l, int r) {
  tree[k].l = l;
  tree[k].r = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
}
void update(int k, int l, int r, pair<int, int> p) {
  if (tree[k].l >= l && tree[k].r <= r) {
    tree[k].v.push_back(p);
    return;
  }
  int mid = (tree[k].l + tree[k].r) >> 1;
  if (mid >= l) update(k << 1, l, r, p);
  if (mid < r) update(k << 1 | 1, l, r, p);
}
int getpa(int x) { return prt[x] == x ? x : getpa(prt[x]); }
void Merge(int x, int y) {
  x = getpa(x);
  y = getpa(y);
  if (x == y) return;
  if (siz[x][0] + siz[x][1] > siz[y][0] + siz[y][1]) swap(x, y);
  prt[x] = y;
  res += (long long)siz[x][0] * siz[y][1] + (long long)siz[x][1] * siz[y][0];
  siz[y][0] += siz[x][0];
  siz[y][1] += siz[x][1];
  sta[++top] = make_pair(x, y);
}
void Reset(int x, int y) {
  prt[x] = x;
  siz[y][0] -= siz[x][0];
  siz[y][1] -= siz[x][1];
  res -= (long long)siz[x][0] * siz[y][1] + (long long)siz[x][1] * siz[y][0];
  top--;
}
void dfs(int k) {
  int now = top;
  for (auto it : tree[k].v) {
    Merge(it.first, it.second);
  }
  if (tree[k].l == tree[k].r)
    ans[tree[k].l] = res;
  else {
    dfs(k << 1);
    dfs(k << 1 | 1);
  }
  while (top > now) {
    Reset(sta[top].first, sta[top].second);
  }
}
int main() {
  int n, x, y, add = 3e5;
  scanf("%d", &n);
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    y += add;
    if (!mp[make_pair(x, y)])
      mp[make_pair(x, y)] = i;
    else {
      update(1, mp[make_pair(x, y)], i - 1, make_pair(x, y));
      mp.erase(make_pair(x, y));
    }
  }
  for (auto it : mp) update(1, it.second, n, it.first);
  for (int i = 1; i <= add; i++) prt[i] = i, siz[i][0] = 1;
  for (int i = add + 1; i <= add * 2; i++) prt[i] = i, siz[i][1] = 1;
  dfs(1);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
