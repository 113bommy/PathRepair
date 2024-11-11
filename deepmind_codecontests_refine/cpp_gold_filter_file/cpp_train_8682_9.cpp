#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 4e5;
int n, r1, r2;
vector<int> g[MAX_N];
vector<int> mark(MAX_N, false);
vector<int> p(MAX_N, 0);
void dfs(int v) {
  stack<int> s;
  s.push(v);
  mark[v] == true;
  while (s.empty() == false) {
    int u = s.top();
    s.pop();
    for (int j = 0; j < g[u].size(); j++) {
      if (mark[g[u][j]] == false) {
        mark[g[u][j]] = true;
        p[g[u][j]] = u;
        s.push(g[u][j]);
      }
    }
  }
}
int main() {
  cin >> n >> r1 >> r2;
  r1--;
  r2--;
  int inp;
  for (int i = 0; i < n; i++) {
    if (i != r1) {
      scanf("%d", &inp);
      inp--;
      g[inp].push_back(i);
      g[i].push_back(inp);
    }
  }
  dfs(r2);
  for (int i = 0; i < n; i++) {
    if (i != r2) {
      printf("%d ", p[i] + 1);
    }
  }
  return 0;
}
