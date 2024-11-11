#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, c;
};
int n, m;
int cnt;
int head[400005];
int nxt[400005];
int to[400005];
vector<node> ans;
int son[200005];
bool vis_p[200005];
bool vis_e[400005];
void addedge(int u, int v) {
  nxt[cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
  cnt++;
}
void dfs(int u) {
  vis_p[u] = 1;
  for (int i = head[u]; i != -1; i = nxt[i]) {
    int v = to[i];
    if (!vis_e[i]) {
      vis_e[i] = vis_e[i ^ 1] = 1;
      if (!vis_p[v]) dfs(v);
      if (son[v]) {
        ans.push_back((node){u, v, son[v]});
        son[v] = 0;
      } else if (son[u]) {
        ans.push_back((node){son[u], u, v});
        son[u] = 0;
      } else
        son[u] = v;
    }
  }
}
int main() {
  memset(head, -1, sizeof(head));
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    addedge(u, v);
    addedge(v, u);
  }
  vis_p[0] = 1;
  for (int i = 1; i <= n; i++)
    if (!vis_p[i]) dfs(i);
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << '\n';
  }
  return 0;
}
