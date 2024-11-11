#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e5 + 7;
int n;
vector<int> g[NMAX];
double sol;
void Dfs(int cur, int p, int h) {
  sol += 1.0 / h;
  for (int i : g[cur]) {
    if (i == p) continue;
    Dfs(i, cur, h + 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  Dfs(1, 0, 1);
  printf("%.12f\n", sol);
  return 0;
}
