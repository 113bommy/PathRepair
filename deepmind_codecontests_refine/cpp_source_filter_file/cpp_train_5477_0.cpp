#include <bits/stdc++.h>
using namespace std;
vector<int> v[200010], c[200010], rt;
int n, siz[200010], fa[200010], dep[200010];
vector<pair<int, pair<int, int> > > ans;
void dfs1(int np, int fath) {
  bool isrt = 1;
  siz[np] = 1;
  for (int x : v[np]) {
    if (x == fath) continue;
    dfs1(x, np);
    siz[np] += siz[x];
    if (siz[x] > (n >> 1)) isrt = 0;
  }
  if (n - siz[np] > (n >> 1)) isrt = 0;
  if (isrt) rt.push_back(np);
}
int stk[200010], top;
void dfs2(int np, int fath) {
  fa[np] = fath;
  stk[top++] = np;
  if (dep[np] >= 3) c[stk[1]].push_back(np);
  for (int x : v[np]) {
    if (x == fath) continue;
    dep[x] = dep[np] + 1;
    dfs2(x, np);
  }
  top--;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, ti, tj; i < n; i++) {
    scanf("%d%d", &ti, &tj);
    v[ti].push_back(tj);
    v[tj].push_back(ti);
  }
  dfs1(1, 0);
  if (rt.size() == 1)
    dfs2(rt[0], 0);
  else
    dfs2(rt[0], rt[1]), dfs2(rt[1], rt[0]);
  for (int i = 1; i <= n; i++)
    if (c[i].size()) {
      int cur = i;
      for (int p : c[i]) {
        ans.push_back(make_pair(fa[i], make_pair(i, p))),
            ans.push_back(make_pair(p, make_pair(fa[p], i)));
        cur = p;
      }
      ans.push_back(make_pair(fa[i], make_pair(cur, i)));
    }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d %d\n", ans[i].first, ans[i].second.first,
           ans[i].second.second);
  return 0;
}
