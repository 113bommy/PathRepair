#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int in[maxn], out[maxn];
int d[maxn];
int n, m;
char s[maxn];
vector<int> g[maxn];
void dfs(int u, int &k) {
  in[u] = k++;
  int len = g[u].size();
  for (int i = 0; i < (len); ++i) {
    dfs(g[u][i], k);
  }
  out[u] = k++;
}
struct Query {
  int p, dep;
  void read() { scanf("%d%d", &p, &dep); }
} query[maxn];
void read() {
  cin >> n >> m;
  d[1] = 1;
  for (int i = (2); i <= (n); ++i) {
    int p;
    scanf("%d", &p);
    d[i] = d[p] + 1;
    g[p].push_back(i);
  }
  scanf("%s", s + 1);
  for (int i = 0; i < (m); ++i) query[i].read();
}
vector<int> line[maxn];
int idx[maxn];
int res[maxn];
int cmp(int a, int b) { return query[a].dep < query[b].dep; }
int x[maxn], ix[maxn], y[maxn];
int z[maxn][26] = {};
int size;
int pos;
int cmpx(int a, int b) { return in[x[a]] < in[x[b]]; }
int get(int p) {
  int l = lower_bound(y, y + size, in[p]) - y;
  int r = upper_bound(y, y + size, out[p]) - y;
  int key = 0;
  for (int j = 0; j < (26); ++j) {
    if ((z[r][j] - z[l][j]) & 1) {
      if (key) {
        return 0;
      } else
        key = 1;
    }
  }
  return 1;
}
void mk(int dep) {
  size = line[dep].size();
  for (int i = 0; i < (size); ++i) {
    ix[i] = i;
    x[i] = line[dep][i];
  }
  sort(ix, ix + size, cmpx);
  for (int i = 0; i < (size); ++i) {
    y[i] = in[x[ix[i]]];
  }
  for (int i = 0; i < (size); ++i) {
    for (int j = 0; j < (26); ++j) {
      z[i + 1][j] = z[i][j];
    }
    ++z[i + 1][s[x[ix[i]]] - 'a'];
  }
  while (pos < m && query[idx[pos]].dep == dep) {
    res[idx[pos]] = get(query[idx[pos]].p);
    pos++;
  }
}
void solve() {
  read();
  for (int i = 1; i <= (n); ++i) {
    line[d[i]].push_back(i);
  }
  int k = 1;
  dfs(1, k);
  for (int i = 0; i < (m); ++i) {
    query[i].read();
    idx[i] = i;
  }
  sort(idx, idx + m, cmp);
  int dep = 1;
  pos = 0;
  while (pos < m) {
    mk(dep++);
  }
  for (int i = 0; i < (m); ++i) res[i] ? printf("Yes\n") : printf("No\n");
}
int main() {
  solve();
  return 0;
}
