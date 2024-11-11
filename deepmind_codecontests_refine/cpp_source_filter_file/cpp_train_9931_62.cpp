#include <bits/stdc++.h>
using namespace std;
const int NUM = 2000 + 10;
int h, w;
int g[NUM][NUM], c[NUM][NUM], can[NUM][NUM];
vector<pair<int, int> > to;
void dfs(int first, int second) {
  to.push_back(make_pair(first, second));
  g[first][second] = 0;
  int i, j;
  for ((i) = (first - 1); (i) <= (first + 1); ++(i))
    for ((j) = (second - 1); (j) <= (second + 1); ++(j))
      if (g[i][j]) dfs(i, j);
}
int dist(pair<int, int> a, pair<int, int> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
int dfs2(int first, int second) {
  int ans = 1;
  g[first][second] = 0;
  int i, j;
  for ((i) = (first - 1); (i) <= (first + 1); ++(i))
    for ((j) = (second - 1); (j) <= (second + 1); ++(j))
      if (g[i][j]) ans += dfs2(i, j);
  return ans;
}
int calc() {
  int sum = 0;
  int i;
  for ((i) = (0); (i) != ((int)to.size()); ++(i))
    if (can[to[i].first][to[i].second]) g[to[i].first][to[i].second] = 1;
  for ((i) = (0); (i) != ((int)to.size()); ++(i))
    if (g[to[i].first][to[i].second])
      sum += dfs2(to[i].first, to[i].second) > 20;
  return sum;
}
int main() {
  int i, j;
  scanf("%d%d", &h, &w);
  for ((i) = (1); (i) <= (h); ++(i))
    for ((j) = (1); (j) <= (w); ++(j)) scanf("%dd", &g[i][j]);
  vector<int> ans;
  for ((i) = (1); (i) <= (h); ++(i)) {
    int last = 0;
    for ((j) = (1); (j) <= (w); ++(j)) {
      if (g[i][j])
        ++last;
      else
        last = 0;
      if (last <= 8 && !g[i][j + 1]) {
        int u = j;
        while (g[i][u]) {
          can[i][u] = 1;
          --u;
        }
      }
    }
  }
  for ((i) = (1); (i) <= (w); ++(i)) {
    int last = 0;
    for ((j) = (1); (j) <= (h); ++(j)) {
      if (g[j][i])
        ++last;
      else
        last = 0;
      if (last <= 8 && !g[j + 1][i]) {
        int u = j;
        while (g[u][i]) {
          can[u][i] = 1;
          --u;
        }
      }
    }
  }
  for ((i) = (1); (i) <= (h); ++(i))
    for ((j) = (1); (j) <= (w); ++(j))
      if (g[i][j]) {
        to.clear();
        dfs(i, j);
        ans.push_back(calc());
      }
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for ((i) = (0); (i) != ((int)ans.size()); ++(i)) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
