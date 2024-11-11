#include <bits/stdc++.h>
using namespace std;
int n, m, s, tot, ans[300005], cnt;
bool vis[300005];
struct nade {
  int v, num, w;
};
vector<nade> G[300005];
vector<int> E[300005];
queue<int> que;
void work1() {
  cnt = 1;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    vis[u] = true;
    for (int i = 0, v; i < E[u].size(); i++) {
      v = E[u][i];
      if (!vis[v]) {
        cnt++;
        vis[v] = true;
        que.push(v);
      }
    }
    for (int i = 0, v, num, w; i < G[u].size(); i++) {
      v = G[u][i].v, num = G[u][i].num, w = G[u][i].w;
      if (!vis[v] && ans[num] != -w) {
        ans[num] = w;
        cnt++;
        vis[v] = true;
        que.push(v);
      }
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= tot; i++) putchar(ans[i] == 1 ? '+' : '-');
  puts("");
}
void work2() {
  cnt = 1;
  que.push(s);
  memset(ans, 0, sizeof ans);
  memset(vis, 0, sizeof vis);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    vis[u] = true;
    for (int i = 0, v; i < E[u].size(); i++) {
      v = E[u][i];
      if (!vis[v]) {
        cnt++;
        vis[v] = true;
        que.push(v);
      }
    }
    for (int i = 0, v, num, w; i < G[u].size(); i++) {
      v = G[u][i].v, num = G[u][i].num, w = G[u][i].w;
      if (ans[num] != w) ans[num] = -w;
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= tot; i++) putchar(ans[i] == 1 ? '+' : '-');
  puts("");
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  while (m--) {
    int op, u, v;
    scanf("%d%d%d", &op, &u, &v);
    if (op == 1)
      E[u].push_back(v);
    else {
      G[u].push_back(nade{v, ++tot, 1});
      G[v].push_back(nade{u, tot, -1});
    }
  }
  work1();
  work2();
}
