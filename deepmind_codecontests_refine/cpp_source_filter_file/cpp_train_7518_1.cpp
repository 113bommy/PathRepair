#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m;
vector<int> v[N], v1[N], v2[N];
int dep[N], fa[N], dp[N][20], mp[N], didx;
int ff[N * 2];
int getf(int v) { return ff[v] == v ? v : ff[v] = getf(ff[v]); }
inline void merge(int x, int y) { ff[getf(x)] = getf(y); }
void dfs(int pos, int f) {
  mp[++didx] = pos;
  dep[pos] = dep[f] + 1;
  fa[pos] = dp[pos][0] = f;
  if (f > 0) v[pos].erase(find(v[pos].begin(), v[pos].end(), f));
  for (auto &i : v[pos]) dfs(i, pos);
}
int tg[N], tg2[N];
void dfs2(int pos, int f) {
  for (auto &i : v[pos]) dfs2(i, pos), tg[pos] += tg[i], tg2[pos] += tg2[i];
  if (tg[pos]) merge(pos, f), merge(pos + n, f + n);
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 19; i >= 0; --i)
    if (dep[dp[x][i]] >= dep[y]) x = dp[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; --i)
    if (dp[x][i] != dp[y][i]) x = dp[x][i], y = dp[y][i];
  return dp[x][0];
}
int lift(int pos, int kk) {
  for (int i = 19; i >= 0; --i)
    if ((kk >> i) & 1) pos = dp[pos][i];
  return pos;
}
int f[N];
bool rev[N];
struct Seg {
  int l, r;
};
inline Seg operator&(const Seg &a, const Seg &b) {
  return {max(a.l, b.l), min(a.r, b.r)};
}
inline Seg operator|(const Seg &a, const Seg &b) {
  return {min(a.l, b.l), max(a.r, b.r)};
}
inline bool chk(Seg x) { return x.l > x.r; }
bool check(int mid) {
  Seg aa = {0, mid};
  for (int i = n; i > 0; --i) {
    int x = mp[i];
    Seg s = aa;
    for (auto &j : v2[x])
      s = s &
          (getf(x) == getf(j) ? Seg{f[j] + 1, mid} : Seg{0, mid - f[j] - 1}),
      rev[j] = getf(j) == getf(x + n);
    Seg s1 = s, s2 = {mid, 0}, s3;
    for (int j = 0, k; j < int(v[x].size()); j = k) {
      s3 = aa;
      int y = v[x][j];
      for (k = j; k < int(v[x].size()); k++) {
        int z = v[x][k];
        if (!(getf(z) == getf(y) || getf(z) == getf(y + n))) break;
        s3 = s3 &
             (getf(y) == getf(z) ? Seg{f[z] + 1, mid} : Seg{0, mid - f[z] - 1});
      }
      if (chk(s3)) return 0;
      if (s3.l > mid - s3.l) s3 = {mid - s3.r, mid - s3.l};
      s1 = s1 & (Seg{s3.l, mid - s3.l} | Seg{mid - s3.r, s3.r});
      if (s3.r < mid - s3.r) s2 = s2 | Seg{s3.r + 1, mid - s3.r - 1};
    }
    if (chk(s1) || (s2.l <= s1.l && s1.r <= s2.r)) return 0;
    if (s2.l <= s1.l && s1.l <= s2.r)
      f[x] = s2.r + 1;
    else
      f[x] = s1.l;
    for (int j = 0, k; j < int(v[x].size()); j = k) {
      s3 = aa;
      int y = v[x][j];
      for (k = j; k < int(v[x].size()); k++) {
        int z = v[x][k];
        if (!(getf(z) == getf(y) || getf(z) == getf(y + n))) break;
        s3 = s3 &
             (getf(y) == getf(z) ? Seg{f[z] + 1, mid} : Seg{0, mid - f[z] - 1});
      }
      bool fl = 0;
      int z = 0;
      if (f[x] < s3.l || f[x] > s3.r) fl = 1, s3 = {mid - s3.r, mid - s3.l};
      for (int l = j; l < k; l++)
        z = v[x][l], rev[z] = (getf(z) == getf(x + n)) ^ fl;
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int t1, t2;
  for (int i = 1; i < n; i++)
    cin >> t1 >> t2, v[t1].push_back(t2), v[t2].push_back(t1);
  dfs(1, 0);
  for (int j = 1; j < 20; j++)
    for (int i = 1; i <= n; i++) dp[i][j] = dp[dp[i][j - 1]][j - 1];
  for (int i = 1; i <= n * 2; i++) ff[i] = i;
  for (int i = 1; i <= m; i++) {
    cin >> t1 >> t2;
    int tt1 = 0, tt2 = 0, z = lca(t1, t2);
    ++tg2[t1];
    ++tg2[t2];
    tg2[z] -= 2;
    if (dep[t2] > dep[z]) ++tg[t2], --tg[tt2 = lift(t2, dep[t2] - dep[z] - 1)];
    if (dep[t1] > dep[z]) ++tg[t1], --tg[tt1 = lift(t1, dep[t1] - dep[z] - 1)];
    if (tt1 && tt2) merge(tt1, tt2 + n), merge(tt1 + n, tt2);
  }
  dfs2(1, 0);
  for (int i = 1; i <= n; i++)
    if (getf(i) == getf(i + n)) {
      cout << -1 << endl;
      return 0;
    }
  int le = 1, ri = n - 1;
  static int w[N];
  for (int i = 2; i <= n; i++) w[i] = min(getf(i), getf(i + n));
  for (int i = 1; i <= n; i++) {
    vector<int> v3;
    for (auto &j : v[i])
      if (w[i] == w[j])
        v2[i].push_back(j);
      else if (tg2[j])
        v3.push_back(j);
    sort(v3.begin(), v3.end(), [](int x, int y) { return w[x] < w[y]; });
    v[i] = v3;
  }
  while (le < ri) {
    int mid = (le + ri) >> 1;
    if (!check(mid))
      le = mid + 1;
    else
      ri = mid;
  }
  cout << le + 1 << endl;
  check(le);
  for (int i = 2; i <= n; i++) {
    int x = mp[i];
    rev[x] ^= rev[fa[x]];
  }
  for (int i = 1; i <= n; i++) cout << (rev[i] ? le - f[i] : f[i]) + 1 << ' ';
  return 0;
}
