#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 1e5 + 7;
const long long maxm = 1e7 + 7;
int n, m, k;
struct EDGE {
  int to, next;
} p[maxn * 2];
int head[maxn], cnt = 0;
void add(int u, int v) {
  p[cnt].to = v;
  p[cnt].next = head[u];
  head[u] = cnt++;
}
int deep[maxn * 2], ans[maxn * 2], d = 0;
bool endf = false;
void dfs(int u) {
  if (endf) return;
  deep[u] = ++d;
  ans[d] = u;
  for (register int i = head[u]; i != -1; i = p[i].next) {
    if (endf) return;
    int v = p[i].to;
    if (deep[v]) {
      if (deep[u] - deep[v] >= k + 1) {
        printf("%d", deep[u] - deep[v]);
        printf("\n");
        ;
        for (register int i = deep[v]; i <= deep[u]; i = i + 1) {
          printf("%d", ans[i]);
          printf("%s", " ");
        }
        endf = true;
        break;
      }
    } else
      dfs(v);
  }
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  int u, v;
  for (register int i = 1; i <= m; i = i + 1) {
    scanf("%d", &u);
    scanf("%d", &v);
    add(u, v);
    add(v, u);
  }
  dfs(1);
}
