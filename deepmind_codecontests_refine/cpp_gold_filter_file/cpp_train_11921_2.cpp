#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int V = 10000005, N = 760;
int n;
bool G[N][N];
char s[V];
struct Trie {
  int ch[V][2], ed[V], cnt, pos[N], fa[V];
  inline void Insert(char *s, int n, int Id) {
    int now = 1, i, c;
    for (i = 0; i < n; ++i, now = ch[now][c])
      if (!ch[now][c = s[i] - 'a']) {
        ch[now][c] = ++cnt;
        fa[cnt] = now;
      }
    ed[now] = Id;
    pos[Id] = now;
  }
  queue<int> q;
  int fail[V];
  inline void buildfail() {
    int x;
    fail[1] = 1;
    if (ch[1][0]) fail[ch[1][0]] = 1, q.push(ch[1][0]);
    if (ch[1][1]) fail[ch[1][1]] = 1, q.push(ch[1][1]);
    while (!q.empty()) {
      x = q.front(), q.pop();
      if (ch[x][0])
        fail[ch[x][0]] = ch[fail[x]][0], q.push(ch[x][0]);
      else
        ch[x][0] = ch[fail[x]][0];
      if (ch[x][1])
        fail[ch[x][1]] = ch[fail[x]][1], q.push(ch[x][1]);
      else
        ch[x][1] = ch[fail[x]][1];
    }
  }
  int fa_[V];
  inline int findf(int x) { return x == fa_[x] ? x : (fa_[x] = findf(fa_[x])); }
  inline void buildtrans() {
    int i, x;
    for (i = 1; i <= cnt; ++i) fa_[i] = ed[i] ? i : fail[i];
    for (i = 1; i <= n; ++i) {
      x = pos[i];
      if (ed[findf(fail[x])]) G[i][ed[findf(fail[x])]] = 1;
      x = fa[pos[i]];
      while (x) {
        if (ed[x]) {
          G[i][ed[x]] = 1;
          break;
        }
        if (ed[findf(x)]) G[i][ed[findf(x)]] = 1;
        x = fa[x];
      }
    }
  }
} T;
int match_rev[N];
int match_for[N];
bool vis[N];
bool vis1[N], vis2[N];
bool Hungary(int x) {
  if (vis[x]) return false;
  vis[x] = true;
  for (int i = 1; i <= n; i++)
    if (G[x][i] && (!match_rev[i] || Hungary(match_rev[i])))
      return match_rev[i] = x, true;
  return false;
}
void dfs(int x) {
  if (vis1[x]) return;
  vis1[x] = true;
  for (int i = 1; i <= n; i++)
    if (G[x][i] && match_for[x] != i && !vis2[i]) {
      vis2[i] = true;
      if (match_rev[i]) dfs(match_rev[i]);
    }
}
int ans[N], cnt;
int main() {
  register int i, j, k;
  scanf("%d", &n);
  for (T.cnt = i = 1; i <= n; ++i) scanf("%s", s), T.Insert(s, strlen(s), i);
  T.buildfail();
  T.buildtrans();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) G[j][k] |= G[j][i] & G[i][k];
  for (int i = 1; i <= n; i++) memset(vis, false, sizeof(vis)), Hungary(i);
  for (int i = 1; i <= n; i++)
    if (match_rev[i]) match_for[match_rev[i]] = i;
  for (int i = 1; i <= n; i++)
    if (!match_for[i]) dfs(i);
  for (int i = 1; i <= n; i++)
    if (vis1[i] && !vis2[i]) ans[++cnt] = i;
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
  return 0;
}
