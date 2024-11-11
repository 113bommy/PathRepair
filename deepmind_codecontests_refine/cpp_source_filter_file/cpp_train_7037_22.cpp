#include <bits/stdc++.h>
using namespace std;
const int N = 111;
vector<pair<int, int> > g[N];
void printAns(int id, int v, int u, double x) {
  if (x >= 1) {
    swap(v, u);
    x -= 1;
  }
  x = 1 - x;
  printf("%d %d %d %.12lf\n", id, u, v, x);
}
void dfs(int v, int par, double x) {
  for (pair<int, int> e : g[v]) {
    if (e.first == par) continue;
    x += 2. / (int)g[v].size();
    if (x >= 2) x -= 2;
    printAns(e.second, v, e.first, x);
    double y = x + 1;
    if (y >= 2) y -= 2;
    dfs(e.first, v, y);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    g[v].push_back(make_pair(u, i));
    g[u].push_back(make_pair(v, i));
  }
  printf("%d\n", n - 1);
  double x = 0;
  for (pair<int, int> e : g[1]) {
    printAns(e.second, 1, e.first, x);
    double y = x + 1;
    if (y >= 2) y -= 2;
    dfs(e.first, 1, y);
    x += 2. / (int)g[1].size();
  }
  return 0;
}
