#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, inf = 1e9, M = 22, mod = 1e9 + 7;
int r[M][maxn], sa[maxn], n, la[maxn], num[maxn], a[maxn], par[maxn];
int ans[maxn];
pair<pair<int, int>, int> p[maxn];
inline int ad(int x, int y) { return (x + y) % mod; }
inline int mu(int x, int y) { return 1LL * x * y % mod; }
int lcp(int x, int y) {
  if (x == y) a[x];
  int ans = 0;
  int xb = x, yb = y;
  for (int i = M - 1; i >= 0; i--) {
    if (r[i][x] == r[i][y]) {
      x += (1 << i);
      y += (1 << i);
      ans |= (1 << i);
    }
  }
  return min(ans, min(a[xb], a[yb]));
}
int f[maxn][3];
int Ans = 0;
int get_par(int v) { return (par[v] == v ? v : par[v] = get_par(par[v])); }
void mrg(int u, int v) {
  u = get_par(u), v = get_par(v);
  int cur = 1, c1 = 1, c2 = 1;
  for (int i = 0; i < 3; i++) {
    c1 = mu(c1, f[u][i]);
    c2 = mu(c2, f[v][i]);
  }
  for (int i = 0; i < 3; i++) {
    int t = f[u][i] + f[v][i];
    f[u][i] = f[v][i] = t;
    cur = mu(cur, t);
  }
  par[u] = v;
  Ans = ad(Ans, cur);
  Ans = ad(Ans, mod - c1);
  Ans = ad(Ans, mod - c2);
}
int main() {
  string t[3], s;
  int len = inf;
  for (int i = 0; i < 3; i++) {
    cin >> t[i];
    len = min(len, int(t[i].size()));
  }
  for (int i = 0; i < 3; i++) {
    s += t[i];
    if (i != 2) s += '|';
  }
  n = s.size();
  int cur = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '|')
      num[i] = cur;
    else {
      num[i] = 0;
      cur++;
    }
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != '|')
      a[i] = a[i + 1] + 1;
    else
      a[i] = 0;
  }
  for (int i = 0; i < n; i++) r[0][i] = s[i];
  for (int i = 1; i < M; i++) {
    for (int j = 0; j < n; j++) {
      if (j + (1 << (i - 1)) >= n)
        p[j] = {{r[i - 1][j], -1}, j};
      else
        p[j] = {{r[i - 1][j], r[i - 1][j + (1 << (i - 1))]}, j};
    }
    sort(p, p + n);
    r[i][p[0].second] = 1;
    for (int j = 1; j < n; j++) {
      if (p[j - 1].first == p[j].first)
        r[i][p[j].second] = r[i][p[j - 1].second];
      else
        r[i][p[j].second] = j + 1;
    }
  }
  for (int i = 0; i < n; i++) sa[i] = p[i].second;
  for (int i = 0; i < n - 1; i++) la[i] = lcp(sa[i], sa[i + 1]);
  for (int i = 0; i < n; i++)
    if (num[sa[i]]) f[i][num[sa[i]] - 1] = 1;
  vector<pair<int, int> > v;
  for (int i = 0; i < n - 1; i++)
    if (la[i]) v.push_back({la[i], i});
  sort(v.begin(), v.end(), greater<pair<int, int> >());
  for (int i = 0; i < n; i++) par[i] = i;
  cur = 0;
  for (int i = len; i >= 1; i--) {
    while (cur < n && v[cur].first >= i) {
      mrg(v[cur].second, v[cur].second + 1);
      cur++;
    }
    ans[i] = Ans;
  }
  for (int i = 1; i <= len; i++) cout << ans[i] << " ";
}
