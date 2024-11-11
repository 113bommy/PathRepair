#include <bits/stdc++.h>
using namespace std;
const int N = 755, M = 10000005;
char s[M];
bool e[N][N];
int n;
struct ACAutomaton {
  int trie[M][2], id[M], idx, pos[M], fa[M];
  void ins(char *s, int t) {
    int cur = 0, l = strlen(s + 1);
    for (int i = 1; i <= l; i++) {
      if (!trie[cur][s[i] - 'a']) trie[cur][s[i] - 'a'] = ++idx, fa[idx] = cur;
      cur = trie[cur][s[i] - 'a'];
    }
    id[cur] = t;
    pos[t] = cur;
  }
  int fail[M];
  void build_fail() {
    queue<int> q;
    for (int i = 0; i < 2; i++)
      if (trie[0][i]) q.push(trie[0][i]);
    while (!q.empty()) {
      int nd = q.front();
      q.pop();
      for (int i = 0; i < 2; i++)
        if (trie[nd][i])
          fail[trie[nd][i]] = trie[fail[nd]][i], q.push(trie[nd][i]);
        else
          trie[nd][i] = trie[fail[nd]][i];
    }
  }
  int f[M];
  int getf(int v) { return f[v] == v ? v : f[v] = getf(f[v]); }
  void build_tr() {
    for (int i = 1; i <= idx; i++) f[i] = id[i] ? i : fail[i];
    for (int i = 1; i <= n; i++) {
      int p = pos[i];
      if (id[getf(fail[p])]) e[i][getf(fail[p])] = 1;
      p = fa[pos[i]];
      while (p) {
        if (id[p]) {
          e[i][id[p]] = 1;
          break;
        }
        if (id[getf(p)]) e[i][getf(p)] = 1;
        p = fa[p];
      }
    }
  }
} t;
int mat[N], mat2[N];
bool vis[N];
int find(int pos) {
  if (vis[pos]) return 0;
  vis[pos] = 1;
  for (int i = 1; i <= n; i++)
    if (e[pos][i] && (!mat[i] || find(mat[i]))) {
      mat[i] = pos;
      return 1;
    }
  return 0;
}
bool vis1[N], vis2[N];
void dfs(int pos) {
  if (vis1[pos]) return;
  vis1[pos] = 1;
  for (int i = 1; i <= n; i++)
    if (e[pos][i] && mat2[pos] != i && !vis2[i]) {
      vis2[i] = 1;
      if (mat[i]) dfs(mat[i]);
    }
}
int ans[N], idx;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> (s + 1), t.ins(s, i);
  t.build_fail();
  t.build_tr();
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) e[i][j] |= e[i][k] & e[k][j];
  for (int i = 1; i <= n; i++) memset(vis, 0, sizeof(vis)), find(i);
  for (int i = 1; i <= n; i++)
    if (mat[i]) mat2[mat[i]] = i;
  for (int i = 1; i <= n; i++)
    if (!mat2[i]) dfs(i);
  for (int i = 1; i <= n; i++)
    if (vis1[i] && !vis2[i]) ans[++idx] = i;
  cout << idx << endl;
  for (int i = 1; i <= idx; i++) cout << ans[i] << ' ';
  return 0;
}
