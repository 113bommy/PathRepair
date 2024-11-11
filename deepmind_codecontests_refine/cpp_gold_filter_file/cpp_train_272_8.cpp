#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
bool vis[MAX][3];
bool call_stack[MAX];
vector<vector<int> > adj;
stack<int> s;
bool flag;
bool dfs(int node, int turn) {
  int sz = adj[node].size();
  if (sz == 0 && turn == 2) return 1;
  for (int i = 0; i < sz; i++) {
    int v = adj[node][i];
    if (call_stack[v]) flag = 1;
    if (!vis[v][3 - turn]) {
      vis[v][3 - turn] = 1;
      call_stack[v] = 1;
      if (dfs(v, 3 - turn)) {
        s.push(v);
        return 1;
      }
    }
    call_stack[v] = 0;
  }
  return 0;
}
int main() {
  adj.resize(MAX);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      int vtx;
      scanf("%d", &vtx);
      adj[i].push_back(vtx);
    }
  }
  int st;
  scanf("%d", &st);
  vis[st][1] = 1;
  call_stack[st] = 1;
  if (dfs(st, 1)) {
    printf("Win\n%d", st);
    while (!s.empty()) {
      printf(" %d", s.top());
      s.pop();
    }
  } else {
    if (flag)
      puts("Draw");
    else
      puts("Lose");
  }
}
