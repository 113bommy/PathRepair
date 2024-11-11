#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[200002];
int p[200002];
int c[200002];
long long k[200002];
int dep[200002];
long long d[200002];
long long first[200002];
long long cur;
inline int getp(int v) { return c[v] == v ? v : c[v] = getp(c[v]); }
inline long long get(int v) {
  return k[v] * ((n - k[v]) * (n - k[v] - 1) - first[v]) +
         k[v] * (k[v] - 1) * (k[v] - 2) + 2 * k[v] * (k[v] - 1) * (n - k[v]);
}
void dfs(int v = 0, int pr = -1, int depth = 0) {
  dep[v] = depth;
  c[v] = v;
  k[v] = 1;
  p[v] = pr;
  d[v] = 1;
  first[v] = 0;
  for (const int& v2 : g[v]) {
    if (v2 == pr) continue;
    dfs(v2, v, depth + 1);
    d[v] += d[v2];
    first[v] += d[v2] * (d[v2] - 1);
  }
  first[v] += (n - d[v]) * (n - d[v] - 1);
  cur += get(v);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    --v1, --v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
  dfs();
  scanf("%d", &m);
  printf(
      "%lld"
      "\n",
      cur);
  for (int i = 0; i < m; ++i) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    --v1, --v2;
    v1 = getp(v1);
    v2 = getp(v2);
    while (v1 != v2) {
      if (dep[v1] < dep[v2]) swap(v1, v2);
      int pr = getp(p[v1]);
      c[v1] = pr;
      cur -= get(v1);
      cur -= get(pr);
      k[pr] += k[v1];
      first[pr] -= (d[v1] * (d[v1] - 1) + (n - d[v1]) * (n - d[v1] - 1));
      first[pr] += first[v1];
      cur += get(pr);
      v1 = pr;
    }
    printf(
        "%lld"
        "\n",
        cur);
  }
  return 0;
}
