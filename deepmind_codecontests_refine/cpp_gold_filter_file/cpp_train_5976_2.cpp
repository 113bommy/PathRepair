#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 100005;
int n;
vector<int> graph[N];
int now[N][26];
int ans[N];
void dfs(int v, int prev) {
  for (size_t i = 0; i < graph[v].size(); ++i) {
    int to = graph[v][i];
    if (to == prev) continue;
    dfs(to, v);
    for (int j = 0; j < 26; ++j) {
      now[v][j] += now[to][j];
    }
  }
  int current = 0;
  for (int i = 25; i >= 0; --i) {
    if (now[v][i] >= 2) {
      current = i + 1;
      break;
    }
  }
  while (now[v][current] == 1) ++current;
  for (int i = 0; i < current; ++i) now[v][i] = 0;
  ++now[v][current];
  ans[v] = current;
}
int main() {
  cin >> n;
  int x, y;
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d %d", &x, &y);
    --x;
    --y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  dfs(0, -1);
  for (int i = 0; i < n; ++i) {
    printf("%c ", (char)('Z' - ans[i]));
  }
  printf("\n");
  return 0;
}
