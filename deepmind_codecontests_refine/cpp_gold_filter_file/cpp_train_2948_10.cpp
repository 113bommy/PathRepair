#include <bits/stdc++.h>
using namespace std;
long long modpow(long long b, long long e, long long mod) {
  long long ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
const int N = 100005;
struct edge {
  int x, y, z;
  int w;
};
vector<edge> e;
vector<int> g[N];
bool ok = false;
int n, l, r, U = -1, V = -1;
int del[N], sum[22][N], dep[22][N], sz[22][N], len[22][N], caminho[N], atual[N],
    cent[22][N];
pair<int, int> dp[3 * N];
int lq = 0, rq = 0, szA = 0, szC = 0;
void calc_sz(int x, int level, int p = -1) {
  sz[level][x] = 1;
  for (auto W : g[x]) {
    int w = e[W].x ^ e[W].y ^ x;
    if (del[w] || w == p) continue;
    calc_sz(w, level, x);
    sz[level][x] += sz[level][w];
  }
}
int find_centroid(int x, int level, int tam, int p = -1) {
  for (auto W : g[x]) {
    int w = e[W].x ^ e[W].y ^ x;
    if (w == p || del[w]) continue;
    if (sz[level][w] * 2 > tam) return find_centroid(w, level, tam, x);
  }
  return x;
}
void calc_d(int x, int level, int root, int p = -1, int dist = 0, int dd = 0) {
  dep[level][x] = dd, len[level][x] = dd, cent[level][x] = root;
  for (auto W : g[x]) {
    int w = e[W].x ^ e[W].y ^ x;
    if (w == p || del[w]) continue;
    calc_d(w, level, root, x, dist + e[W].z, dd + 1);
    len[level][x] = max(len[level][x], len[level][w]);
  }
}
void dfs(int x, int level, int p, int dist = 0) {
  sum[level][x] = dist;
  if (szA == dep[level][x]) atual[szA++] = x;
  if (sum[level][atual[dep[level][x]]] <= sum[level][x])
    atual[dep[level][x]] = x;
  for (auto w : g[x]) {
    int v = e[w].x ^ e[w].y ^ x;
    if (del[v] || v == p) continue;
    dfs(v, level, x, dist + e[w].z);
  }
}
void solve(int x, int level) {
  szC = 1;
  caminho[0] = x;
  atual[0] = x;
  for (auto w : g[x]) {
    int v = e[w].x ^ e[w].y ^ x;
    if (del[v]) continue;
    szA = 1;
    dfs(v, level, x, e[w].z);
    int curr = min(r, szC) - 1;
    lq = 0, rq = -1;
    for (int j = 1; j < szA; j++) {
      while ((rq - lq + 1) && (dp[lq].first + j) > r) lq++;
      while (curr >= 0 && (curr + j) >= l) {
        pair<int, int> u = {curr, caminho[curr]};
        curr--;
        while ((rq - lq + 1) &&
               sum[level][dp[rq].second] <= sum[level][u.second])
          rq--;
        dp[++rq] = u;
      }
      if ((rq - lq + 1) &&
          (sum[level][dp[lq].second] + sum[level][atual[j]]) >= 0) {
        U = dp[lq].second, V = atual[j], ok = true;
      }
    }
    for (int j = 0; j < szA; j++) {
      if (szC == j) caminho[szC++] = (atual[j]);
      if (sum[level][caminho[j]] < sum[level][atual[j]]) caminho[j] = atual[j];
    }
  }
}
void decompose(int x, bool sorts = 0, int level = 0, bool rdo = 0) {
  if (rdo) {
    calc_sz(x, level);
    x = find_centroid(x, level, sz[level][x]);
    calc_d(x, level, x);
  } else
    x = cent[level][x];
  szC = 0;
  if (!sorts) solve(x, level);
  if (sorts) {
    sort(begin(g[x]), end(g[x]), [&](int a, int b) {
      int u = x ^ e[a].x ^ e[a].y, v = x ^ e[b].x ^ e[b].y;
      if (len[u] == len[v]) return u < v;
      return len[u] < len[v];
    });
  }
  del[x] = 1;
  for (auto w : g[x]) {
    int v = e[w].x ^ e[w].y ^ x;
    if (del[v]) continue;
    decompose(v, sorts, level + 1, rdo);
  }
}
int32_t main() {
  scanf("%d%d%d", &n, &l, &r);
  vector<int> tocmp;
  for (int i = 0; i < (n - 1); ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    g[x].push_back((int)(e).size());
    g[y].push_back((int)(e).size());
    e.push_back({x, y, z, z});
    tocmp.push_back(z);
  }
  sort(begin(tocmp), end(tocmp));
  tocmp.resize(unique(begin(tocmp), end(tocmp)) - begin(tocmp));
  int l = 0, r = (int)(tocmp).size() - 1;
  decompose(1, 1, 0, 1);
  decompose(1, 0, 0, 0);
  while (l <= r) {
    int mid = l + (r - l) / 2;
    for (int i = 1; i <= n; i++) {
      del[i] = 0;
    }
    for (auto& w : e) {
      w.z = -1;
      if (w.w >= tocmp[mid]) w.z = 1;
    }
    ok = false;
    decompose(1);
    if (ok) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  printf("%d %d\n", U, V);
}
