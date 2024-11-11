#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 100005;
vector<int> graph[N];
int ans[N];
int now[N][26];
void dfs(int v, int pr) {
  for (size_t i = 0; i < graph[v].size(); ++i) {
    int to = graph[v][i];
    if (to == pr) continue;
    dfs(to, v);
    for (int j = 0; j < 26; ++j) now[v][j] += now[to][j];
  }
  int cur = 0;
  for (int i = 26; i >= 0; --i) {
    if (now[v][i] >= 2) {
      cur = i + 1;
      break;
    }
  }
  while (now[v][cur] == 1) ++cur;
  for (int i = 0; i < cur; ++i) {
    now[v][i] = 0;
  }
  ++now[v][cur];
  ans[v] = cur;
}
int n;
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
  for (int i = 0; i < n; ++i) printf("%c ", (char)('Z' - ans[i]));
  printf("\n");
  return 0;
}
