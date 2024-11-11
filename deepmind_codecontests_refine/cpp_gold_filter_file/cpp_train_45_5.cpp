#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265359;
template <typename T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T sqr(T x) {
  return x * x;
}
const int maxn = 200005;
const long long mod = 1000000007;
vector<pair<int, long long> > g[maxn];
long long sumDist[maxn], sumDistAll[maxn], sumDistUp[maxn];
long long sumDist2[maxn], sumDistAll2[maxn], sumDistUp2[maxn];
long long cnt[maxn];
int tin[maxn], tout[maxn];
int timer = 1;
int parent[maxn][18];
int depth[maxn];
long long depth2[maxn];
long long n;
void dfs(int v, int p, int d, long long d2 = 0) {
  tin[v] = timer++;
  parent[v][0] = p;
  depth[v] = d + 1;
  cnt[v] = 1;
  depth2[v] = d2;
  for (int i = 1; i < 18; i++) parent[v][i] = parent[parent[v][i - 1]][i - 1];
  for (pair<int, int> to : g[v]) {
    if (to.first == p) continue;
    dfs(to.first, v, d + 1, d2 + to.second);
    long long l2 = ((long long)to.second * to.second) % mod;
    sumDist[v] =
        (sumDist[v] + (sumDist[to.first] + cnt[to.first] * 1LL * to.second)) %
        mod;
    sumDist2[v] = (sumDist2[v] +
                   (sumDist2[to.first] +
                    ((((long long)to.second) * 2LL * sumDist[to.first]) % mod) +
                    cnt[to.first] * l2)) %
                  mod;
    cnt[v] += cnt[to.first];
  }
  tout[v] = timer;
}
void dfs2(int v, int p, long long upDist, long long upDist2) {
  sumDistAll[v] = (sumDist[v] + upDist) % mod;
  sumDistAll2[v] = (sumDist2[v] + upDist2) % mod;
  sumDistUp[v] = upDist;
  sumDistUp2[v] = upDist2;
  for (pair<int, int> to : g[v]) {
    if (to.first == p) continue;
    long long l2 = ((long long)to.second * to.second) % mod;
    long long newUpDist =
        (upDist + sumDist[v] -
         ((sumDist[to.first] + cnt[to.first] * to.second) % mod) + mod) %
        mod;
    long long t = newUpDist;
    newUpDist =
        (newUpDist + ((long long)to.second) * (n - cnt[to.first])) % mod;
    long long newUpDist2 =
        (upDist2 + sumDist2[v] -
         ((sumDist2[to.first] +
           (((long long)to.second * 2LL * sumDist[to.first]) % mod) +
           cnt[to.first] * l2) %
          mod) +
         mod) %
        mod;
    newUpDist2 = (newUpDist2 + (((long long)to.second * 2LL * t) % mod) +
                  l2 * (n - cnt[to.first])) %
                 mod;
    dfs2(to.first, v, newUpDist, newUpDist2);
  }
}
int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int diff = depth[a] - depth[b];
  for (int i = 0; i < 18; i++)
    if (diff & (1 << i)) a = parent[a][i];
  if (a == b) return a;
  int ans;
  for (int i = 17; i >= 0; i--) {
    if (parent[a][i] == parent[b][i])
      ans = parent[a][i];
    else {
      a = parent[a][i];
      b = parent[b][i];
    }
  }
  return ans;
}
long long query(int u, int v) {
  if (!(tin[v] <= tin[u] && tin[u] < tout[v])) {
    int z = lca(u, v);
    long long d = (depth2[u] - depth2[z] + depth2[v] - depth2[z]) % mod;
    long long d2 = (d * d) % mod;
    long long ans = sumDistAll2[u];
    ans = (ans + 3LL * mod -
           2LL * ((sumDist2[v] + ((2LL * d * sumDist[v]) % mod) + d2 * cnt[v]) %
                  mod)) %
          mod;
    ans = (mod - ans) % mod;
    return ans;
  } else {
    long long ans = sumDistAll2[u];
    long long d = (depth2[u] - depth2[v]) % mod;
    d = (d + mod) % mod;
    long long d2 = (d * d) % mod;
    ans = (ans + 3LL * mod -
           2LL * ((sumDistUp2[v] + 2LL * d * sumDistUp[v] + d2 * (n - cnt[v])) %
                  mod)) %
          mod;
    return ans;
  }
}
int main() {
  int _n;
  scanf("%d", &_n);
  n = _n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    g[u].push_back(make_pair(v, c));
    g[v].push_back(make_pair(u, c));
  }
  dfs(1, 1, 0);
  dfs2(1, 1, 0, 0);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%d\n", (int)query(u, v));
  }
  return 0;
}
