#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e3 + 5;
struct Edge {
  int to, nxt;
} e[MAX_N << 1];
int head[MAX_N], tote;
void add_edge(int u, int v) {
  e[++tote].to = v, e[tote].nxt = head[u];
  head[u] = tote;
}
void init() { memset(head, 0, sizeof(head)), tote = 0; }
set<int> s;
int n, a[MAX_N], c[MAX_N];
bool flag = false;
int siz[MAX_N];
void dfs(int x, int fa) {
  int cnt = a[x] + 1;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    if (!(--cnt)) {
      c[x] = *it;
      s.erase(*it);
      break;
    }
  }
  siz[x] = 1;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != fa) {
      dfs(e[i].to, x);
      siz[x] += siz[e[i].to];
    }
  if (siz[x] <= a[x]) flag = true;
}
int main() {
  scanf("%d", &n);
  int root;
  for (register int i = 1; i <= n; i++) {
    int to;
    scanf("%d", &to), scanf("%d", &a[i]);
    if (to)
      add_edge(to, i), add_edge(i, to);
    else
      root = i;
    s.insert(i);
  }
  dfs(root, 0);
  if (flag) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (register int i = 1; i <= n; i++)
    printf("%d%c", c[i], i == n ? '\n' : ' ');
  return 0;
}
