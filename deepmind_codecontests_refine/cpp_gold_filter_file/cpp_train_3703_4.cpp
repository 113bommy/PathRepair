#include <bits/stdc++.h>
using namespace std;
const int maxn = 200050;
vector<int> G[maxn];
int color[maxn];
vector<pair<int, int>> Q;
void dfs(int x) {
  for (auto to : G[x]) {
    if (!color[to]) {
      color[to] = color[x] == 1 ? 2 : 1;
      dfs(to);
    }
  }
}
int n, x, y;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
    Q.push_back(make_pair(x, y));
  }
  for (int i = 0; i < n; i++)
    G[2 * i].push_back(2 * i + 1), G[2 * i + 1].push_back(2 * i);
  for (int i = 0; i < 2 * n; i++)
    if (!color[i]) {
      color[i] = 1;
      dfs(i);
    }
  for (auto x : Q) printf("%d %d\n", color[x.first], color[x.second]);
}
