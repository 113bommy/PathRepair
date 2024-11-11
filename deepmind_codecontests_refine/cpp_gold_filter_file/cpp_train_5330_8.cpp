#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, head[1000010], dfn[1000010], low[1000010], num, ans, a[1000010],
    size[1000010], du[1000010];
struct node {
  int to, next;
} fafa[1000010 * 2];
struct date {
  int u, v;
} e[1000010];
bool instack[1000010];
stack<int> s;
void adde(int u, int v) {
  fafa[++k].next = head[u];
  fafa[k].to = v;
  head[u] = k;
}
void tarjan(int x) {
  dfn[x] = low[x] = ++num;
  s.push(x);
  instack[x] = true;
  for (int i = head[x]; i; i = fafa[i].next) {
    int v = fafa[i].to;
    if (!dfn[v])
      tarjan(v), low[x] = min(low[x], low[v]);
    else if (instack[v])
      low[x] = min(low[x], low[v]);
  }
  if (dfn[x] == low[x]) {
    ans++;
    while (s.top() != x) {
      size[ans]++;
      a[s.top()] = ans;
      instack[s.top()] = false;
      s.pop();
    }
    size[ans]++;
    a[s.top()] = ans;
    instack[s.top()] = false;
    s.pop();
  }
}
void clear() {
  for (int i = 1; i <= n; i++)
    head[i] = dfn[i] = low[i] = head[i] = size[i] = du[i] = 0;
  ans = num = k = 0;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    clear();
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
      scanf("%d%d", &u, &v);
      e[i].u = u, e[i].v = v;
      if (u == v) continue;
      adde(v, u);
    }
    for (int i = 1; i <= n; i++)
      if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= m; i++) {
      if (a[e[i].v] != a[e[i].u]) du[a[e[i].u]]++;
    }
    int flag = 0;
    if (ans > 1) {
      for (int j = 1; j <= ans; j++) {
        if (!du[j]) {
          flag = 1;
          puts("Yes");
          printf("%d %d \n", size[j], n - size[j]);
          for (int i = 1; i <= n; i++)
            if (a[i] == j) printf("%d ", i);
          printf("\n");
          for (int i = 1; i <= n; i++)
            if (a[i] != j) printf("%d ", i);
          printf("\n");
          break;
        }
      }
    }
    if (!flag) puts("No");
  }
}
