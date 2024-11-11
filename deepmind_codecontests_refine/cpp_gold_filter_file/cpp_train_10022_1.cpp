#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
const int N = 1e5 + 5, M = 1e6 + 5;
int first[N], nex[M], to[M], w[M], num = 1;
int n, m, s, t, ans, sum1, sum2;
inline void add(int u, int v, int val) {
  nex[++num] = first[u];
  first[u] = num;
  to[num] = v;
  w[num] = val;
}
inline void Add(int u, int v, int val) {
  add(u, v, val);
  add(v, u, 0);
}
namespace ISAP {
int dep[N], gap[N];
void bfs() {
  memset(dep, -1, sizeof(dep));
  queue<int> q;
  q.push(t);
  dep[t] = 0;
  gap[0] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = first[u]; i; i = nex[i]) {
      int v = to[i];
      if (!w[i] || dep[v] != -1) continue;
      dep[v] = dep[u] + 1;
      gap[dep[v]]++;
      q.push(v);
    }
  }
}
int cur[N];
inline int dfs(int u, int in) {
  int out = 0;
  if (u == t) return in;
  for (int i = cur[u]; i; i = nex[i]) {
    cur[u] = i;
    int v = to[i];
    if (!w[i] || dep[v] != dep[u] - 1) continue;
    int res = dfs(v, min(w[i], in - out));
    w[i] -= res;
    w[i ^ 1] += res;
    out += res;
    if (out == in) return out;
  }
  gap[dep[u]]--;
  if (!gap[dep[u]]) dep[s] = n * m * 2 + 3;
  dep[u]++;
  gap[dep[u]]++;
  return out;
}
void work() {
  bfs();
  while (dep[s] < n * m * 2 + 2) {
    memcpy(cur, first, sizeof(first));
    ans += dfs(s, 1e9);
  }
}
}  // namespace ISAP
bool vis[N], mp[202][202];
int main() {
  n = read(), m = read();
  s = 0, t = 2 * n * m + 1;
  for (int i = 1; i <= n; ++i) {
    string s;
    getline(cin, s);
    for (int j = 0; j < m; ++j)
      if (s[j] == '#') mp[i][j + 1] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!mp[i][j]) continue;
      sum1++;
      int y1 = (i - 1) * m + j, y2 = i * m + j, x2 = y1 + n * m, x1 = x2 - 1;
      if (mp[i - 1][j] && !vis[y1]) sum2++, vis[y1] = 1, Add(s, y1, 1);
      if (mp[i][j - 1] && !vis[x1]) sum2++, vis[x1] = 1, Add(x1, t, 1);
      if (mp[i - 1][j]) {
        if (mp[i][j + 1]) Add(y1, x2, 1);
        if (mp[i][j - 1]) Add(y1, x1, 1);
      }
      if (mp[i + 1][j]) {
        if (mp[i][j + 1]) Add(y2, x2, 1);
        if (mp[i][j - 1]) Add(y2, x1, 1);
      }
    }
  }
  ISAP::work();
  printf("%d", sum1 + ans - sum2);
  return 0;
}
