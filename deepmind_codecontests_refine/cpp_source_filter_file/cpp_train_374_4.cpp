#include <bits/stdc++.h>
using namespace std;
template <typename tp>
inline void read(tp &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar())
    ;
  if (f) x = -x;
}
const int N = 3e5 + 10;
struct E {
  int from, to, nxt;
} e[N << 2];
int head[N], out[N], in[N], pre[N], book[N], vis[N];
int cnt = 0, n, m, len = 0;
char str[N];
int Has[233][233];
int q[N], top = 0;
int ans[N], ans_cnt = 0;
inline void add(int u, int v) {
  if (Has[u][v]) return;
  Has[u][v] = 1;
  e[++cnt] = (E){u, v, head[u]};
  head[u] = cnt;
  out[u]++, in[v]++;
}
inline int find(int u) { return pre[u] == u ? u : pre[u] = find(pre[u]); }
inline void Op() {
  cout << "NO\n";
  return;
}
inline void dfs(int u) {
  ans[++ans_cnt] = u;
  book[u] = 0;
  for (int i = head[u]; i; i = e[i].nxt) dfs(e[i].to);
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str);
    len = strlen(str);
    fill(vis + 'a' - 1, vis + 'z' + 1, 0);
    for (int k = 0; k < len; k++) {
      vis[str[k]]++;
    }
    for (int st = 'a'; st <= 'z'; st++)
      if (vis[st] >= 2) {
        Op();
        return 0;
      }
    for (int st = 'a'; st <= 'z'; st++) book[st] |= vis[st];
    for (int k = 0; k < len - 1; k++) add(str[k], str[k + 1]);
  }
  for (int st = 'a'; st <= 'z'; st++)
    if (out[st] >= 2 || in[st] >= 2) {
      Op();
      return 0;
    }
  top = 0;
  for (int st = 'a'; st <= 'z'; st++)
    if (!in[st] && out[st]) q[++top] = st;
  sort(q + 1, q + top + 1);
  for (int i = 1; i <= top; i++) dfs(q[i]);
  for (int st = 'a'; st <= 'z'; st++)
    if (book[st]) {
      Op();
      return 0;
    }
  for (int i = 1; i <= ans_cnt; i++) putchar(ans[i]);
  return 0;
}
