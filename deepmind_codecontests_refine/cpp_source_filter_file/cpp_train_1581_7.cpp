#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, maxn = 5e5 + 5;
int n, m;
char s[maxn];
vector<pair<int, int> > g[maxn], qu[maxn];
vector<int> f[maxn];
int tr[maxn][27], tot = 0, in[maxn], out[maxn], dfs_clock;
int ans[maxn], fail[maxn];
int sum[maxn];
void add(int x, int v) {
  while (x <= n) {
    sum[x] += v;
    x += (x & (-x));
  }
}
int query(int x) {
  int r = 0;
  while (x) {
    r += sum[x];
    x -= (x & (-x));
  }
  return r;
}
int add() {
  int now = 0, len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (!tr[now][s[i] - 'a']) tr[now][s[i] - 'a'] = ++tot;
    now = tr[now][s[i] - 'a'];
  }
  return now;
}
void build() {
  queue<int> Q;
  for (int i = 0; i <= 25; i++)
    if (tr[0][i]) Q.push(tr[0][i]);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i <= 25; i++) {
      if (tr[u][i]) {
        fail[tr[u][i]] = tr[fail[u]][i];
        Q.push(tr[u][i]);
      } else
        tr[u][i] = tr[fail[u]][i];
    }
  }
  for (int i = 1; i <= tot; i++) f[fail[i]].push_back(i);
}
void dfs(int u) {
  in[u] = ++dfs_clock;
  for (int i = 0; i < f[u].size(); i++) dfs(f[u][i]);
  out[u] = dfs_clock;
}
void dfs1(int u, int now) {
  add(in[u], 1);
  for (int i = 0; i < qu[now].size(); i++) {
    pair<int, int> v = qu[now][i];
    ans[v.second] = query(out[v.first]) - query(in[v.first] - 1);
  }
  for (int i = 0; i < g[now].size(); i++) {
    pair<int, int> v = g[now][i];
    dfs1(tr[u][v.first], v.second);
  }
  add(in[u], -1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int op;
    scanf("%d", &op);
    int p = 0;
    if (op == 2) scanf("%d", &p);
    scanf("%s", s);
    g[p].push_back(make_pair(s[0] - 'a', i));
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int p;
    scanf("%d%s", &p, s);
    qu[p].push_back(make_pair(add(), i));
  }
  build();
  dfs(0);
  dfs1(0, 0);
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
