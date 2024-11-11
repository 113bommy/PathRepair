#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f = ch ^ 45, ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? x : -x;
}
int frt[100010], nxt[100010 << 1], v[100010 << 1];
int f[100010], q[100010], d[100010], dis[100010];
vector<int> a[100010];
vector<long long> s[100010];
map<pair<int, int>, long long> ans;
int n, m, Q, far, tot, bl;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline void add(int x, int y) {
  v[++tot] = y;
  nxt[tot] = frt[x];
  frt[x] = tot;
}
void dfs(int x, int fa) {
  d[x] = max(d[x], dis[x]);
  if (dis[x] > dis[far]) far = x;
  for (int i = frt[x]; i; i = nxt[i])
    if (v[i] != fa) {
      dis[v[i]] = dis[x] + 1;
      dfs(v[i], x);
    }
}
int main() {
  n = read();
  m = read();
  Q = read();
  bl = (int)sqrt(1.0 * n * n / Q / log2(n)) + 1;
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
    f[find(y)] = find(x);
  }
  for (int i = 1; i <= n; ++i)
    if (!d[i]) {
      far = 0;
      dis[i] = 0;
      dfs(i, 0);
      int tmp = far;
      far = 0;
      dis[tmp] = 0;
      dfs(tmp, 0);
      dis[far] = 0;
      dfs(far, 0);
    }
  for (int i = 1; i <= n; ++i) a[find(i)].push_back(d[i]);
  for (int i = 1; i <= n; ++i) sort(a[i].begin(), a[i].end());
  for (int i = 1; i <= n; ++i) {
    s[i].resize(a[i].size() + 1);
    for (int j = (int)a[i].size() - 1; j >= 0; j--)
      s[i][j] = s[i][j + 1] + a[i][j];
  }
  for (int i = 1; i <= n; ++i)
    if (a[i].size() >= bl) q[++q[0]] = i;
  for (int i = 1; i <= q[0]; ++i)
    for (int j = i + 1; j <= q[0]; ++j) {
      int l1 = a[q[i]].size(), l2 = a[q[j]].size();
      int len = max(a[q[i]][l1 - 1], a[q[j]][l2 - 1]);
      int p = l2;
      long long now = 0;
      for (int k = 0; k < l1; ++k) {
        while (p && a[q[i]][k] + a[q[j]][p - 1] >= len - 1) --p;
        now += s[q[j]][p] + 1ll * (a[q[i]][k] + 1) * (l2 - p) + 1ll * len * p;
      }
      ans[make_pair(q[i], q[j])] = now;
    }
  while (Q--) {
    int x = read(), y = read();
    x = find(x);
    y = find(y);
    if (x == y) {
      cout << "-1\n";
      continue;
    }
    int l1 = a[x].size(), l2 = a[y].size();
    long long now = 0;
    if (l1 >= bl && l2 >= bl)
      now = ans[make_pair(min(x, y), max(x, y))];
    else {
      int len = max(a[x][l1 - 1], a[y][l2 - 1]);
      if (a[x].size() > a[y].size()) swap(x, y), swap(l1, l2);
      for (int i = 0; i < l1; ++i) {
        int p = lower_bound(a[y].begin(), a[y].end(), len - a[x][i] - 1) -
                a[y].begin();
        now += (s[y][p] + 1ll * (a[x][i] + 1) * (l2 - p) + 1ll * len * p);
      }
    }
    printf("%.7lf\n", 1.0 * now / l1 / l2);
  }
}
