#include <bits/stdc++.h>
using namespace std;
vector<int> edges[300005], vis(300005), ans(300005);
vector<set<int> > color(300005);
void bfs(int i) {
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int clr = 1;
    int u = q.front();
    q.pop();
    set<int> st;
    vis[u] = 1;
    for (auto i : color[u]) {
      if (ans[i]) st.insert(ans[i]);
    }
    for (auto i : color[u]) {
      if (ans[i] == 0) {
        while (st.find(clr) != st.end()) clr++;
        st.insert(clr);
        ans[i] = clr;
      }
    }
    for (auto i : edges[u]) {
      if (vis[i] == 0) {
        q.push(i);
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    while (x--) {
      int c;
      scanf("%d", &c);
      color[i].insert(c);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  bfs(0);
  set<int> s;
  for (int i = 1; i <= m; i++) {
    s.insert(max(ans[i], 1));
  }
  printf("%d \n", s.size());
  for (int i = 1; i <= m; i++) printf("%d ", max(ans[i], 1));
  return 0;
}
