#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
int m;
struct matrix {
  long long a[N][N];
  void clr() { memset(a, -1, sizeof(a)); }
  matrix operator*(matrix &b) {
    static matrix c;
    c.clr();
    for (__typeof(0) i = 0; i <= m; i++)
      for (__typeof(0) j = 0; j <= m; j++)
        for (__typeof(0) k = 0; k <= m; k++)
          if (a[i][k] >= 0 && b.a[k][j] >= 0)
            c.a[i][j] = max(c.a[i][j], a[i][k] + b.a[k][j]);
    return c;
  }
  matrix operator^(long long k) {
    static matrix b, c;
    c.clr();
    c.a[0][0] = 0;
    memcpy(b.a, a, sizeof(a));
    for (; k; k >>= 1, b = b * b)
      if (k & 1) c = c * b;
    return c;
  }
} f;
struct Node {
  int ch[26], fail, val;
} tr[N];
void insert(char *s, int val) {
  int n = strlen(s + 1);
  int u = 0;
  for (__typeof(1) i = 1; i <= n; i++) {
    int c = s[i] - 'a';
    if (!tr[u].ch[c]) tr[u].ch[c] = ++m;
    u = tr[u].ch[c];
  }
  tr[u].val += val;
}
void bfs() {
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (__typeof(0) i = 0; i <= 25; i++)
      if (tr[u].ch[i]) {
        int v = tr[u].ch[i];
        if (u) tr[v].fail = tr[tr[u].fail].ch[i];
        q.push(v);
      } else
        tr[u].ch[i] = tr[tr[u].fail].ch[i];
  }
}
struct Edge {
  int to, next;
} e[N];
int head[N], cnt;
void ins(int u, int v) {
  e[++cnt] = (Edge){v, head[u]};
  head[u] = cnt;
}
int deg[N];
void toposort() {
  for (__typeof(1) i = 1; i <= m; i++)
    if (tr[i].fail) ins(tr[i].fail, i), deg[i]++;
  queue<int> q;
  for (__typeof(1) i = 1; i <= m; i++)
    if (!deg[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      tr[v].val += tr[u].val;
      if (!--deg[v]) q.push(v);
    }
  }
}
void build() {
  for (__typeof(0) i = 0; i <= m; i++)
    for (__typeof(0) j = 0; j <= 25; j++) f.a[i][tr[i].ch[j]] = 0;
  for (__typeof(0) i = 0; i <= m; i++)
    for (__typeof(0) j = 0; j <= m; j++)
      if (!f.a[i][j]) f.a[i][j] = tr[j].val;
}
char s[N];
int a[N];
int main() {
  int n;
  long long l;
  scanf("%d%I64d", &n, &l);
  for (__typeof(1) i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (__typeof(1) i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    insert(s, a[i]);
  }
  bfs();
  toposort();
  f.clr();
  build();
  f = f ^ l;
  long long ans = 0;
  for (__typeof(0) i = 0; i <= m; i++) ans = max(ans, f.a[0][i]);
  printf("%I64d\n", ans);
  return 0;
}
