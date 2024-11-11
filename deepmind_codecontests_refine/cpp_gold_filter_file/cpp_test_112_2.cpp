#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, L = 19;
vector<pair<int, char>> to[N];
string str[N];
int pos[N];
int n, m, q;
char s[N];
int from[N];
int sa[N], rk[N], tp[N], bkt[N], hei[N], len, st[L][N], l2[N];
int p0[N];
bool cmp(int x, int y, int t) {
  return tp[x] == tp[y] && tp[x + t] == tp[y + t];
}
void tros(int len, int m) {
  for (int i = 1; i <= m; i++) bkt[i] = 0;
  for (int i = 1; i <= len; i++) bkt[rk[tp[i]]]++;
  for (int i = 1; i <= m; i++) bkt[i] += bkt[i - 1];
  for (int i = len; i >= 1; i--) sa[bkt[rk[tp[i]]]--] = tp[i];
}
void get_sa() {
  len = strlen(s + 1);
  int m = 128;
  for (int i = 1; i <= len; i++) tp[i] = i, rk[i] = s[i];
  tros(len, m);
  for (int l = 1, p = 0; p < len; m = p, l <<= 1) {
    p = 0;
    for (int i = len - l + 1; i <= len; i++) tp[++p] = i;
    for (int i = 1; i <= len; i++)
      if (sa[i] > l) tp[++p] = sa[i] - l;
    tros(len, m);
    memcpy(tp, rk, sizeof(tp));
    rk[sa[1]] = p = 1;
    for (int i = 2; i <= len; i++)
      rk[sa[i]] = cmp(sa[i], sa[i - 1], l) ? p : ++p;
  }
  for (int i = 1, t = 0; i <= len; i++) {
    if (t) --t;
    while (s[i + t] == s[sa[rk[i] - 1] + t]) ++t;
    hei[rk[i]] = t;
  }
  for (int i = 1; i <= len; i++) st[0][i] = hei[i];
  for (int i = 1; i < L; i++) {
    for (int j = 1; j <= len - (1 << (i - 1)); j++)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }
  for (int i = 2; i <= len; i++) l2[i] = l2[i >> 1] + 1;
}
int qmin(int x, int y) {
  int t = l2[y - x + 1];
  return min(st[t][x], st[t][y - (1 << t) + 1]);
}
int lcp(int x, int y) {
  if (x == y) return len - x + 1;
  x = rk[x], y = rk[y];
  if (x > y) swap(x, y);
  return qmin(x + 1, y);
}
int sz[N], mxch[N], top[N], dep[N], fa[N];
void ss0(int x) {
  sz[x] = 1;
  for (auto &i : to[x]) {
    int v = i.first;
    if (v == fa[x]) continue;
    fa[v] = x;
    dep[v] = dep[x] + 1;
    ss0(v);
    sz[x] += sz[v];
    if (sz[v] > sz[mxch[x]]) mxch[x] = v;
  }
  if (mxch[x])
    for (auto &i : to[x])
      if (i.first == mxch[x]) swap(i, to[x][0]);
}
int dfn[N], dfnn, dpos[N], upos[N];
void ss1(int x, int t) {
  top[x] = t;
  dfn[x] = ++dfnn;
  bool first = 1;
  for (auto &i : to[x]) {
    int v = i.first;
    if (v == fa[x]) continue;
    ++len;
    s[len] = i.second;
    from[len] = m + 1;
    dpos[v] = len;
    ss1(v, first ? t : v);
    first = 0;
  }
}
void ss2(int x) {
  for (int I = to[x].size() - 1; I >= 0; I--) {
    auto &i = to[x][I];
    int v = i.first;
    if (v == fa[x]) continue;
    ss2(v);
    ++len;
    s[len] = i.second;
    from[len] = m + 2;
    upos[v] = len;
  }
}
vector<pair<int, int>> get_intervals(int u, int v) {
  vector<pair<int, int>> v1, v2;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) {
      v2.push_back({dpos[top[v]], dpos[v]});
      v = fa[top[v]];
    } else {
      v1.push_back({upos[u], upos[top[u]]});
      u = fa[top[u]];
    }
  }
  if (dep[u] != dep[v]) {
    if (dep[u] > dep[v])
      v1.push_back({upos[u], upos[mxch[v]]});
    else
      v2.push_back({dpos[mxch[u]], dpos[v]});
  }
  reverse(v2.begin(), v2.end());
  for (auto &i : v2) v1.push_back(i);
  return v1;
}
int lcp(int x, vector<pair<int, int>> &y) {
  int ans = 0;
  for (auto &i : y) {
    int l = i.first, r = i.second;
    int t = lcp(x, l);
    t = min(t, r - l + 1);
    ans += t;
    if (t < r - l + 1) break;
    x += t;
  }
  return ans;
}
bool cmp1(int x, const vector<pair<int, int>> &y) {
  for (auto &i : y) {
    int l = i.first, r = i.second;
    int t = lcp(x, l);
    t = min(t, r - l + 1);
    if (t < r - l + 1) return s[x + t] < s[l + t];
    x += t;
  }
  return 0;
}
bool cmp2(const vector<pair<int, int>> &y, int x) {
  for (auto &i : y) {
    int l = i.first, r = i.second;
    int t = lcp(x, l);
    t = min(t, r - l + 1);
    if (t < r - l + 1) return s[l + t] < s[x + t];
    x += t;
  }
  return 0;
}
int qu[N], qv[N], ql[N], qr[N], qL[N], qR[N], ans[N];
vector<tuple<int, int, int>> que[N];
int t[N];
void mdf(int p, int v) {
  for (; p <= m + 2; p += p & -p) t[p] += v;
}
int qry(int p) {
  int r = 0;
  for (; p; p -= p & -p) r += t[p];
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i < n; i++) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    to[x].push_back({y, c});
    to[y].push_back({x, c});
  }
  for (int i = 1; i <= m; i++) cin >> str[i];
  pos[1] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < str[i].size(); j++)
      s[pos[i] + j] = str[i][j], from[pos[i] + j] = i;
    s[pos[i] + str[i].size()] = '$';
    from[pos[i] + str[i].size()] = i;
    pos[i + 1] = pos[i] + str[i].size() + 1;
  }
  len = pos[m + 1] - 1;
  ss0(1);
  ss1(1, 1);
  ss2(1);
  get_sa();
  for (int i = 1; i <= q; i++) {
    cin >> qu[i] >> qv[i] >> ql[i] >> qr[i];
    auto v = get_intervals(qu[i], qv[i]);
    qL[i] = lower_bound(sa + 1, sa + len + 1, v, cmp1) - sa;
    qR[i] = upper_bound(sa + 1, sa + len + 1, v, cmp2) - sa - 1;
  }
  for (int i = 1; i <= q; i++) {
    que[qL[i] - 1].emplace_back(ql[i] - 1, 1, i);
    que[qL[i] - 1].emplace_back(qr[i], -1, i);
    que[qR[i]].emplace_back(ql[i] - 1, -1, i);
    que[qR[i]].emplace_back(qr[i], 1, i);
  }
  for (int i = 1; i <= len; i++) {
    mdf(from[sa[i]], 1);
    for (auto j : que[i]) {
      int x = get<0>(j), y = get<1>(j), z = get<2>(j);
      ans[z] += y * qry(x);
    }
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
