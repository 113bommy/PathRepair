#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int> > g;
vector<int> arr;
vector<char> used;
void dfs(int v) {
  arr.push_back(v + 1);
  used[v] = true;
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (!used[to]) {
      dfs(to);
      arr.push_back(v + 1);
    }
  }
}
int main(int argc, char *argv[]) {
  int m;
  scanf("%d%d%d", &n, &m, &k);
  g.resize(n);
  while (m--) {
    int from, to;
    scanf("%d%d", &from, &to);
    --from;
    --to;
    g[from].push_back(to);
    g[to].push_back(from);
  }
  used.resize(n, false);
  dfs(0);
  int kk = (2 * n - 1) / k + 1;
  for (int i = 0, j = 0; i < k; ++i, j += kk, j = min(j, 2 * n - 2)) {
    if (j + kk >= 2 * n - 1) {
      printf("%d ", 2 * n - 1 - j);
      for (int q = j; q < 2 * n - 1; ++q) {
        printf("%d ", arr[q]);
      }
      printf("\n");
    } else {
      printf("%d ", kk);
      for (int q = j; q < j + kk; ++q) {
        printf("%d ", arr[q]);
      }
      printf("\n");
    }
  }
  return 0;
}
