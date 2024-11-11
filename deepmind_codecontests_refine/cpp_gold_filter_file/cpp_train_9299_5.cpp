#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
using namespace std;
const int N = 1e6 + 10;
int n, m, c[N][26], fail[N], pos[N], idx, st[N], ed[N], cnt, vis[N], d[N];
char str[N];
vector<int> g[N];
void insert(int id) {
  int p = 0;
  for (int i = 1; str[i]; i++) {
    int k = str[i] - 'a';
    if (!c[p][k]) c[p][k] = ++idx;
    p = c[p][k];
  }
  pos[id] = p;
}
void build() {
  queue<int> q;
  for (int i = 0; i < 26; i++)
    if (c[0][i]) q.push(c[0][i]);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++)
      if (c[u][i])
        q.push(c[u][i]), fail[c[u][i]] = c[fail[u]][i];
      else
        c[u][i] = c[fail[u]][i];
  }
}
void dfs(int x) {
  st[x] = ++cnt;
  for (int to : g[x]) dfs(to);
  ed[x] = cnt;
}
void ins(int x, int v) {
  for (; x <= cnt + 1; x += x & (-x)) d[x] += v;
}
int ask(int x) {
  int s = 0;
  for (; x; x -= x & (-x)) s += d[x];
  return s;
}
signed main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) scanf("%s", str + 1), insert(i);
  build();
  for (int i = 1; i <= idx; i++) g[fail[i]].push_back(i);
  dfs(0);
  for (int i = 1; i <= n; i++)
    ins(st[pos[i]], 1), ins(ed[pos[i]] + 1, -1), vis[i] = 1;
  for (int i = 1; i <= m; i++) {
    scanf("%s", str + 1);
    if (str[1] == '+' || str[1] == '-') {
      int sum = 0;
      for (int j = 2; str[j]; j++) sum = sum * 10 + str[j] - '0';
      if (str[1] == '+') {
        if (!vis[sum])
          ins(st[pos[sum]], 1), ins(ed[pos[sum]] + 1, -1), vis[sum] = 1;
      } else {
        if (vis[sum])
          ins(st[pos[sum]], -1), ins(ed[pos[sum]] + 1, 1), vis[sum] = 0;
      }
    } else {
      int p = 0, res = 0;
      for (int j = 2; str[j]; j++) {
        p = c[p][str[j] - 'a'];
        res += ask(st[p]);
      }
      printf("%d\n", res);
    }
  }
  return 0;
}
