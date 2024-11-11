#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, next;
} e[1000010];
int head[1000010], num;
int n, m;
int cnt, tot;
int dfn[1000010], low[1000010];
stack<int> s;
set<int> node[100010], edge[100010], ans;
void addedge(int a, int b) {
  e[++num].to = b;
  e[num].next = head[a];
  head[a] = num;
}
void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++cnt;
  for (int i = head[u]; i; i = e[i].next) {
    if (!dfn[e[i].to]) {
      s.push(i >> 1);
      s.push(u);
      s.push(e[i].to);
      tarjan(e[i].to, u);
      low[u] = min(low[u], low[e[i].to]);
      if (dfn[u] <= low[e[i].to]) {
        tot++;
        while (1) {
          int t1 = s.top();
          s.pop();
          int t2 = s.top();
          s.pop();
          node[tot].insert(t1);
          node[tot].insert(t2);
          edge[tot].insert(s.top());
          s.pop();
          if (t1 == e[i].to && t2 == u) break;
        }
      }
    } else {
      if (dfn[e[i].to] < dfn[u] && e[i].to != fa) {
        s.push(i >> 1);
        s.push(u);
        s.push(e[i].to);
        low[u] = min(low[u], dfn[e[i].to]);
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    addedge(a, b);
    addedge(b, a);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, 0);
  for (int i = 1; i <= tot; i++) {
    if (edge[i].size() == node[i].size()) {
      ans.insert(edge[i].begin(), edge[i].end());
    }
  }
  printf("%d\n", ans.size());
  for (int i : ans) printf("%d ", i);
}
