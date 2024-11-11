#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, N = 1e7;
int pr[N], mu[N], mnp[N], f[N], now, n, k, cnt;
bool mk[N];
pair<int, int> p[maxn];
vector<int> a, b, g[maxn], v[maxn];
void sieve(int n) {
  memset(mk, 1, sizeof(mk));
  mk[1] = 0;
  mu[1] = 1;
  for (int i = (2); i <= (n); ++i) {
    if (mk[i]) mnp[i] = i, pr[++cnt] = i, mu[i] = -1;
    for (int j = 1; j <= cnt && i * pr[j] <= n; ++j) {
      mk[i * pr[j]] = 0, mnp[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) break;
      mu[i * pr[j]] = -mu[i];
    }
  }
}
void add(int i, int x, int w) {
  if (x == v[i].size())
    f[w] += mu[w];
  else
    add(i, x + 1, w), add(i, x + 1, w * v[i][x]);
}
int ask(int i, int x, int w) {
  if (x == v[i].size())
    return f[w];
  else
    return ask(i, x + 1, w) + ask(i, x + 1, w * v[i][x]);
}
void clr(int i, int x, int w) {
  if (x == v[i].size())
    f[w] = 0;
  else
    clr(i, x + 1, w), clr(i, x + 1, w * v[i][x]);
}
void solve(int l, int r, vector<int> b) {
  if (l == r) {
    for (int x : b) g[l].push_back(x);
    return;
  }
  int mid = (l + r) >> 1;
  vector<int> c, d;
  for (int i = (l); i <= (mid); ++i) add(a[i], 0, 1);
  for (int x : b)
    if (ask(x, 0, 1))
      c.push_back(x);
    else
      d.push_back(x);
  for (int i = (l); i <= (mid); ++i) clr(a[i], 0, 1);
  solve(l, mid, c);
  solve(mid + 1, r, d);
}
int main() {
  scanf("%d%d", &n, &k);
  sieve(N);
  for (int i = (1); i <= (n); ++i) {
    int x;
    scanf("%d", &x);
    while (x != 1) {
      int y = mnp[x];
      v[i].push_back(y);
      while (x % y == 0) x /= y;
    }
  }
  for (int i = (1); i <= (n); ++i)
    if (!ask(i, 0, 1))
      add(i, 0, 1), a.push_back(i);
    else
      b.push_back(i);
  if (a.size() >= k) {
    for (int i = (0); i <= (k - 1); ++i) printf("%d ", a[i]);
    return 0;
  }
  for (int x : a) clr(x, 0, 1);
  int n = a.size();
  solve(0, n - 1, b);
  for (int i = (0); i <= (n - 1); ++i) p[i] = make_pair(g[i].size(), i);
  sort(p, p + n, greater<pair<int, int> >());
  for (int i = (0); i <= (n - 1); ++i) {
    now += p[i].first + 1;
    vector<int> ans;
    if (now >= k) {
      int pk = k - i - 1;
      for (int j = (0); j <= (i); ++j) {
        int ww = min(pk, p[j].first), D = p[j].second;
        pk -= ww;
        ans.push_back(a[D]);
        for (int k = (0); k <= (ww - 1); ++k) ans.push_back(g[D][k]);
      }
      for (int x : ans) printf("%d ", x);
      return 0;
    }
  }
  return 0;
}
