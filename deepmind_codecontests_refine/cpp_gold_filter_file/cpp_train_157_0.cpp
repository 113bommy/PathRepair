#include <bits/stdc++.h>
using namespace std;
int sort_arra[1000010];
int starting_permutation[1000010];
int vertexlist[1000010];
vector<int> adjancylist[1000010];
vector<int> arra;
void dfs(int i) {
  int x;
  arra.push_back(i);
  vertexlist[i] = 1;
  x = adjancylist[i].size();
  for (int j = 0; j < x; ++j)
    if (vertexlist[adjancylist[i][j]] == 0) dfs(adjancylist[i][j]);
}
int main() {
  int n, m, first, second, x;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", starting_permutation + i);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &first, &second);
    adjancylist[first - 1].push_back(second - 1);
    adjancylist[second - 1].push_back(first - 1);
  }
  for (int i = 0; i < n; ++i)
    if (vertexlist[i] == 0) {
      arra.clear();
      dfs(i);
      sort(arra.begin(), arra.end());
      x = arra.size();
      for (int j = 0; j < x; ++j) sort_arra[j] = starting_permutation[arra[j]];
      sort(sort_arra, sort_arra + x, greater<int>());
      for (int j = 0; j < x; ++j) starting_permutation[arra[j]] = sort_arra[j];
    }
  for (int i = 0; i < n; ++i) printf("%d ", starting_permutation[i]);
  printf("\n");
}
