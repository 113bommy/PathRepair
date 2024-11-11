#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1000010], b[1000010], c[1000010];
int fa[1000010], f[1000010], siz[1000010];
vector<int> vec[1000010];
stack<pair<int, int> > s;
int find(int x) { return x == fa[x] ? x : find(fa[x]); }
void init() {
  for (int i = 1; i <= 2 * n + 1; i++) fa[i] = i, siz[i] = 1;
}
bool merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return 0;
  if (siz[fx] > siz[fy]) swap(fx, fy);
  fa[fx] = fy;
  siz[fy] += siz[fx];
  s.push({fx, fy});
  return 1;
}
void del() {
  pair<int, int> now = s.top();
  s.pop();
  fa[now.first] = now.first;
  siz[now.second] -= siz[now.first];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  init();
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  for (int i = 1; i <= m; i++) {
    if (c[a[i]] == c[b[i]]) {
      int fx = find(a[i]);
      int fy = find(b[i]);
      if (fx == fy)
        f[c[a[i]]] = 1;
      else {
        merge(a[i], b[i] + n), merge(b[i], a[i] + n);
      }
    }
  }
  map<pair<int, int>, int> mp;
  long long cnt = 0;
  for (int i = 1; i <= m; i++) {
    if (c[a[i]] != c[b[i]] && !f[c[a[i]]] && !f[c[b[i]]]) {
      int r1 = c[a[i]], r2 = c[b[i]];
      if (r1 > r2) swap(r1, r2);
      if (!mp[{r1, r2}]) mp[{r1, r2}] = ++cnt;
      int pos = mp[{r1, r2}];
      vec[pos].push_back(i);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= cnt; i++) {
    int now = s.size();
    for (int j = 0; j < vec[i].size(); j++) {
      int v = vec[i][j];
      int fx = find(a[v]), fy = find(b[v]);
      if (fx == fy) {
        ans--;
        break;
      }
      merge(a[v], b[v] + n);
      merge(b[v], a[v] + n);
    }
    while (s.size() > now) {
      del();
    }
  }
  cnt = 0;
  for (int i = 1; i <= k; i++)
    if (!f[i]) cnt++;
  ans += cnt * (cnt - 1) / 2;
  printf("%lld\n", ans);
}
