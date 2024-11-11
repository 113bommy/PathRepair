#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, m, q, nn = 0, cn = 1, num[MAXN] = {0}, d1[MAXN] = {0}, d2[MAXN] = {0},
             d[MAXN] = {0}, cnt[MAXN] = {0}, pos[MAXN];
long long s1[MAXN] = {0}, s2[MAXN] = {0};
vector<int> ch[MAXN];
map<pair<int, int>, double> ans;
void dfs1(int x, int fa) {
  int sz = ch[x].size();
  num[x] = nn;
  ++cnt[nn];
  for (int i = 0, t; i < sz; ++i)
    if ((t = ch[x][i]) != fa) {
      dfs1(t, x);
      if (d1[t] >= d2[x]) d2[x] = d1[t] + 1;
      if (d2[x] > d1[x]) swap(d1[x], d2[x]);
    }
}
void dfs2(int x, int fa, int mx) {
  int sz = ch[x].size();
  ++s1[cn + max(mx, d1[x])];
  d[nn] = max(d[nn], max(mx, d1[x]));
  for (int i = 0, t; i < sz; ++i)
    if ((t = ch[x][i]) != fa)
      dfs2(t, x, 1 + max(mx, d1[x] == d1[t] + 1 ? d2[x] : d1[x]));
}
long long S1(int x, int l, int r) {
  l = max(l, 0);
  r = min(r, cnt[x] - 1);
  if (l > r) return 0;
  return s1[pos[x] + r] - (l ? s1[pos[x] + l - 1] : 0);
}
long long S2(int x, int l, int r) {
  l = max(l, 0);
  r = min(r, cnt[x] - 1);
  if (l > r) return 0;
  return s2[pos[x] + r] - (l ? s2[pos[x] + l - 1] : 0);
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%d%d", &n, &m, &q);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    ch[x].push_back(y);
    ch[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
    if (!num[i]) {
      pos[++nn] = cn;
      dfs1(i, 0);
      dfs2(i, 0, 0);
      for (int j = 1; j < cnt[nn]; ++j) {
        s2[cn + j] = s2[cn + j - 1] + s1[cn + j] * j;
        s1[cn + j] += s1[cn + j - 1];
      }
      cn += cnt[nn];
    }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = num[x];
    y = num[y];
    if (x == y)
      printf("%d\n", -1);
    else {
      if (d[x] > d[y]) swap(x, y);
      pair<int, int> now = make_pair(x, y);
      if (ans.find(now) == ans.end()) {
        long long sum = 0;
        for (int i = 0; i <= d[x]; ++i)
          sum += S1(x, i, i) * S1(y, 0, d[y] - i - 2);
        sum *= d[y];
        for (int i = 0; i <= d[x]; ++i) {
          long long tx1, tx2, ty1, ty2;
          tx1 = S1(x, i, i);
          tx2 = S2(x, i, i);
          ty1 = S1(y, d[y] - i - 1, d[y]);
          ty2 = S2(y, d[y] - i - 1, d[y]);
          sum += tx1 * ty1 + tx1 * ty2 + tx2 * ty1;
        }
        ans[now] = 1.0 * sum / cnt[x] / cnt[y];
      }
      printf("%.9lf\n", ans[now]);
    }
  }
  return 0;
}
