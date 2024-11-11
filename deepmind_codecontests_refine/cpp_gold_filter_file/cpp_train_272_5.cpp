#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000111;
int odw[maxn], n, m, x, vrt, c, b, ok[maxn][2];
vector<int> v[maxn], vo[maxn];
stack<int> s;
void dfs(int u, int win) {
  ok[u][win] = 1;
  s.push(u);
  if (u == vrt && win == 1) {
    printf("Win\n");
    while (!s.empty()) {
      printf("%d ", s.top());
      s.pop();
    }
    printf("\n");
    exit(0);
  }
  for (auto i : vo[u])
    if (!ok[i][win ^ 1]) dfs(i, win ^ 1);
  s.pop();
}
void cykl_parz(int u) {
  odw[u] = 1;
  for (auto i : v[u]) {
    if (odw[i] == 1) {
      printf("Draw\n");
      exit(0);
    } else if (odw[i] == 0) {
      cykl_parz(i);
    }
  }
  odw[u] = 2;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c);
    for (int j = 1; j <= c; j++) {
      scanf("%d", &b);
      v[i].push_back(b);
      vo[b].push_back(i);
    }
  }
  scanf("%d", &vrt);
  for (int i = 1; i <= n; i++)
    if (v[i].size() == 0) dfs(i, 0);
  cykl_parz(vrt);
  printf("Lose\n");
  return 0;
}
