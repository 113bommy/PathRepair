#include <bits/stdc++.h>
using namespace std;
const int maxn = 250100;
set<pair<int, int> > ver[maxn];
int n, d[maxn], vis[maxn], K;
long long f[maxn][2];
int pre[maxn], suf[maxn];
vector<int> Rm[maxn];
multiset<long long> Sa[maxn], Sb[maxn];
long long suma[maxn];
inline void update(int x) {
  while (Sa[x].size() && Sb[x].size() && *Sa[x].rbegin() > *Sb[x].begin()) {
    int a = *Sa[x].rbegin(), b = *Sb[x].begin();
    Sa[x].erase(Sa[x].find(a));
    Sb[x].erase(Sb[x].begin());
    suma[x] += b - a;
    Sa[x].insert(b);
    Sb[x].insert(a);
  }
  while (Sa[x].size() && ((int)Sa[x].size() >= K || *Sa[x].rbegin() > 0)) {
    int a = *Sa[x].rbegin();
    Sb[x].insert(a);
    suma[x] -= a;
    Sa[x].erase(Sa[x].find(a));
  }
  while ((int)Sa[x].size() < K - 1 && Sb[x].size() && *Sb[x].begin() <= 0) {
    int a = *Sb[x].begin();
    Sb[x].erase(Sb[x].begin());
    Sa[x].insert(a);
    suma[x] += a;
  }
}
inline void ins(int x, long long v) {
  Sa[x].insert(v);
  suma[x] += v;
  update(x);
}
inline void era(int x, long long v) {
  if (Sa[x].find(v) != Sa[x].end())
    Sa[x].erase(Sa[x].find(v)), suma[x] -= v;
  else
    Sb[x].erase(Sb[x].find(v));
  update(x);
}
long long sum[maxn];
inline void treedp(int x, int fat) {
  f[x][0] = f[x][1] = sum[x];
  vis[x] = 1;
  for (auto p : ver[x]) {
    int y = p.first, w = p.second;
    if (y == fat) continue;
    treedp(y, x);
    f[y][0] += w;
    f[x][0] += f[y][0];
    f[x][1] += f[y][0];
    ins(x, f[y][1] - f[y][0]);
  }
  update(x);
  f[x][0] += suma[x];
  if (K && Sb[x].size() && *Sb[x].begin() < 0) f[x][0] += *Sb[x].begin();
  f[x][1] += suma[x];
  for (auto p : ver[x])
    if (p.first != fat) era(x, f[p.first][1] - f[p.first][0]);
}
int U[maxn], V[maxn], W[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) scanf("%d%d%d", U + i, V + i, W + i);
  for (int i = 0; i < n - 1; i++) d[++U[i]]++, d[++V[i]]++;
  for (int i = 0; i < n - 1; i++) {
    ver[U[i]].insert(make_pair(V[i], W[i]));
    ver[V[i]].insert(make_pair(U[i], W[i]));
  }
  for (int i = 1; i <= n; i++) pre[i] = i - 1, suf[i] = i + 1;
  pre[n + 1] = n;
  suf[0] = 1;
  for (int i = 1; i <= n; i++) Rm[d[i]].push_back(i);
  vector<long long> res;
  for (int i = 0; i < n; i++) {
    K = i;
    for (int j = 0; j < (int)Rm[i].size(); j++) {
      int x = Rm[i][j], p = pre[x], s = suf[x];
      suf[p] = s;
      pre[s] = p;
      for (auto p : ver[x]) {
        int y = p.first, w = p.second;
        ver[y].erase(make_pair(x, w));
        ins(y, -w);
        sum[y] += w;
      }
      ver[x].clear();
    }
    long long ans = 0;
    for (int j = suf[0]; j <= n; j = suf[j])
      if (!vis[j]) {
        treedp(j, 0);
        ans += f[j][0];
      }
    printf("%lld ", ans);
    for (int j = suf[0]; j <= n; j = suf[j]) vis[j] = 0;
  }
  return 0;
}
