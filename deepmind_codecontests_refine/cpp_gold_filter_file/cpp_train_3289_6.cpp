#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 3e5 + 5;
vector<int> s[maxn];
int num[maxn];
int c[maxn];
struct node {
  int to;
  int nxt;
} edge[maxn << 1];
int head[maxn];
int tot;
int res;
void add(int u, int v) {
  edge[tot].nxt = head[u];
  edge[tot].to = v;
  head[u] = tot++;
}
void Init() {
  res = 1;
  tot = 0;
  memset(c, 0, sizeof(c));
  memset(head, -1, sizeof(head));
}
void dfs(int u, int pre) {
  res = max(res, num[u]);
  set<int> t;
  t.clear();
  for (int i = 0; i < num[u]; i++) {
    int v = s[u][i];
    if (c[v]) {
      t.insert(c[v]);
    }
  }
  int temp = 0;
  for (int i = 0; i < num[u]; i++) {
    int v = s[u][i];
    if (!c[v]) {
      temp++;
      while (t.count(temp)) {
        temp++;
      }
      c[v] = temp;
    }
  }
  for (int i = head[u]; i != -1; i = edge[i].nxt) {
    int to = edge[i].to;
    if (to != pre) {
      dfs(to, u);
    }
  }
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    Init();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &num[i]);
      s[i].clear();
      for (int k = 0; k < num[i]; k++) {
        int x;
        scanf("%d", &x);
        s[i].push_back(x);
      }
    }
    int u, v;
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d", &u, &v);
      add(u, v);
      add(v, u);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
      if (!c[i]) {
        c[i] = 1;
      }
    }
    cout << res << endl;
    cout << c[1];
    for (int i = 2; i <= m; i++) {
      cout << " " << c[i];
    }
    cout << endl;
  }
  return 0;
}
