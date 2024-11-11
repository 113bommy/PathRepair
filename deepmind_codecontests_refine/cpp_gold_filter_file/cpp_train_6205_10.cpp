#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > mul(vector<vector<long long> > a,
                               vector<vector<long long> > b) {
  vector<vector<long long> > c;
  c.resize(a.size());
  for (int i = 0; i < c.size(); i++) c[i].resize(b[0].size(), 0);
  for (int i = 0; i < c.size(); i++)
    for (int j = 0; j < c[i].size(); j++)
      for (int k = 0; k < b.size(); k++)
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
  return c;
}
vector<vector<long long> > def;
vector<vector<long long> > bpow(vector<vector<long long> > a, long long st) {
  if (st == 0) return def;
  if (st == 1) return a;
  vector<vector<long long> > b = bpow(a, st >> 1);
  b = mul(b, b);
  if (st & 1) b = mul(a, b);
  return b;
}
long long AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;
long long myrand() {
  long long ZR = (XR * AR + YR * BR + CR) % MOD;
  XR = YR;
  YR = ZR;
  return ZR;
}
long long sqr(long long x) { return x * x; }
const long long llinf = 2e18;
const long double EPS = 1e-9;
const int maxn = 1e5 + 100, inf = 1e9 + 100, mod = 1e9 + 9;
struct myhash {
  long long operator()(const pair<int, int> &x) const {
    return x.first * (long long)42424243 + x.second;
  }
};
const int sq = 1000;
int n;
int zap;
pair<int, int> zaps[maxn];
vector<int> e[maxn];
bool vis[maxn];
bool ez;
int color[maxn];
int root[maxn];
bool predfs(int v, int rootnow) {
  vis[v] = 1;
  root[v] = rootnow;
  for (int i = 0; i < e[v].size(); i++) {
    int to = e[v][i];
    if (!vis[to]) {
      color[to] = color[v] ^ 1;
      if (predfs(to, rootnow)) return 1;
    } else if (color[to] != (color[v] ^ 1))
      return 1;
  }
  return 0;
}
pair<int, int> get(int v, int u) {
  if (v > u) swap(v, u);
  return make_pair(v, u);
}
unordered_set<pair<int, int>, myhash> bad;
unordered_map<pair<int, int>, int, myhash> mp;
unordered_set<pair<int, int>, myhash> got;
int croot[maxn];
bool frst[maxn];
unordered_map<pair<int, int>, int, myhash> poss;
void precalc(int start) {
  for (int i = 0; i < n; i++) e[i].clear(), vis[i] = 0, color[i] = -1;
  ez = 0;
  bad.clear();
  for (int i = start; i < min(zap, start + sq); i++) {
    if (bad.count(get(zaps[i].first, zaps[i].second)) == 0) {
      bad.insert(get(zaps[i].first, zaps[i].second));
      if (mp[get(zaps[i].first, zaps[i].second)] == 1) frst[i] = 1;
    }
  }
  got.clear();
  for (int i = 0; i < start; i++) {
    int v = zaps[i].first, u = zaps[i].second;
    if (bad.count(get(v, u)) == 0 && mp[get(v, u)] == 1 &&
        got.count(get(v, u)) == 0) {
      e[v].push_back(u);
      e[u].push_back(v);
      got.insert(get(v, u));
    }
  }
  for (int i = 0; i < n; i++)
    if (!vis[i]) {
      color[i] = 0;
      croot[i] = -1;
      if (predfs(i, i)) {
        ez = 1;
        break;
      }
    }
}
vector<pair<int, int> > ed[maxn];
vector<int> vert;
bool taken[maxn];
bool dfs(int v) {
  for (int i = 0; i < ed[v].size(); i++) {
    int s = ed[v][i].first, f = ed[v][i].second, to = root[f];
    if (croot[to] == -1) {
      croot[to] = croot[v] ^ color[s] ^ color[f] ^ 1;
      if (dfs(to)) return 1;
    } else if (croot[to] != (croot[v] ^ color[s] ^ color[f] ^ 1))
      return 1;
  }
  return 0;
}
bool calc() {
  for (int i = 0; i < vert.size(); i++) {
    int v = root[vert[i]];
    if (croot[v] == -1) {
      croot[v] = 0;
      if (dfs(v)) return 1;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  scanf("%d %d", &n, &zap);
  for (int i = 0; i < zap; i++)
    scanf("%d %d", &zaps[i].first, &zaps[i].second), zaps[i].first--,
        zaps[i].second--;
  for (int start = 0; start < zap; start += sq) {
    precalc(start);
    for (int i = start; i < min(zap, start + sq); i++) {
      if (ez)
        printf("NO\n");
      else {
        mp[get(zaps[i].first, zaps[i].second)] ^= 1;
        if (poss.count(get(zaps[i].first, zaps[i].second)) == 1)
          frst[poss[get(zaps[i].first, zaps[i].second)]] = 0;
        if (mp[get(zaps[i].first, zaps[i].second)] == 1)
          frst[i] = 1;
        else
          frst[i] = 0;
        poss[get(zaps[i].first, zaps[i].second)] = i;
        for (int j = start; j < min(zap, start + sq); j++) {
          int v = zaps[j].first, u = zaps[j].second;
          if (!taken[v]) taken[v] = 1, vert.push_back(v);
          if (!taken[u]) taken[u] = 1, vert.push_back(u);
          if (frst[j]) {
            ed[root[v]].push_back(make_pair(v, u));
            ed[root[u]].push_back(make_pair(u, v));
          }
        }
        if (calc())
          printf("NO\n");
        else
          printf("YES\n");
        for (int j = 0; j < vert.size(); j++)
          taken[vert[j]] = 0, ed[root[vert[j]]].clear(),
          croot[root[vert[j]]] = -1;
        vert.clear();
      }
    }
  }
}
