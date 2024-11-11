#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 301000;
long long myrand() {
  return ((long long)rand() << 48) + ((long long)rand << 32) +
         ((long long)rand() << 16) + rand();
}
set<int> e[N];
int n, m, u, v, id[N], f[N], dep[N], t;
pair<int, int> E[N];
map<long long, int> hs;
long long lev[N], d[N];
void dfs(int u, int f, int d) {
  dep[u] = d;
  for (auto v : e[u])
    if (v != f) {
      dfs(v, u, d + 1);
    }
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
  srand(time(0));
  scanf("%d%d", &n, &m);
  lev[0] = 1;
  for (int i = 1; i < n + 1; i++) lev[i] = lev[i - 1] * 10;
  for (int i = 1; i < n + 1; i++) d[i] = lev[i];
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    E[i] = make_pair(u, v);
    d[u] += lev[v];
    d[v] += lev[u];
  }
  for (int i = 1; i < n + 1; i++) {
    if (!hs.count(d[i])) hs[d[i]] = t++;
    id[i] = hs[d[i]];
  }
  for (int i = 0; i < t; i++) f[i] = i;
  for (int i = 0; i < m; i++) {
    u = id[E[i].first], v = id[E[i].second];
    if (u == v) continue;
    if (e[u].count(v) || e[v].count(u)) continue;
    if (find(u) == find(v)) {
      puts("NO");
      return 0;
    }
    f[find(u)] = find(v);
    e[u].insert(v);
    e[v].insert(u);
  }
  for (int i = 0; i < t; i++)
    if (((int)(e[i]).size()) > 2) {
      puts("NO");
      return 0;
    }
  for (int i = 0; i < t; i++)
    if (((int)(e[i]).size()) < 2) {
      dfs(i, -1, 1);
      puts("YES");
      for (int j = 1; j < n + 1; j++) printf("%d ", dep[id[j]]);
      puts("");
      return 0;
    }
}
