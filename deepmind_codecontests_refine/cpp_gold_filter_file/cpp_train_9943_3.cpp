#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int n, col[100005], sz[100005], badboy[100005];
long long ans[100005], can;
int cnt[100005];
void dfs(int nod, int p) {
  sz[nod] = 1;
  for (int i = 0; i < v[nod].size(); ++i) {
    if (v[nod][i] != p) {
      dfs(v[nod][i], nod);
      sz[nod] += sz[v[nod][i]];
    }
  }
}
int maxx;
void reveal(int x) {
  ++cnt[x];
  if (maxx < cnt[x]) {
    maxx = cnt[x];
    can = x;
  } else if (maxx == cnt[x])
    can += x;
}
void add(int nod, int p) {
  reveal(col[nod]);
  for (int i = 0; i < v[nod].size(); ++i) {
    if (v[nod][i] != p && !badboy[v[nod][i]]) add(v[nod][i], nod);
  }
}
void rem(int nod, int p) {
  cnt[col[nod]]--;
  for (int i = 0; i < v[nod].size(); ++i) {
    if (v[nod][i] != p && !badboy[v[nod][i]]) rem(v[nod][i], nod);
  }
}
void dfs_proc(int nod, int p, int ok) {
  int bg = -1, Max = 0;
  for (int i = 0; i < v[nod].size(); ++i) {
    if (v[nod][i] != p && Max < sz[v[nod][i]]) {
      Max = sz[v[nod][i]];
      bg = v[nod][i];
    }
  }
  for (int i = 0; i < v[nod].size(); ++i) {
    if (v[nod][i] != p && v[nod][i] != bg) {
      dfs_proc(v[nod][i], nod, 1);
    }
  }
  if (bg != -1) {
    dfs_proc(bg, nod, 0);
    badboy[bg] = 1;
  }
  add(nod, p);
  if (bg != -1) badboy[bg] = 0;
  ans[nod] = can;
  if (ok == 1) {
    rem(nod, p);
    maxx = can = 0;
  }
}
int main() {
  int i, x, y;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &col[i]);
  for (i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  dfs_proc(1, 0, 0);
  for (i = 1; i <= n; ++i) printf("%lld ", ans[i]);
  return 0;
}
