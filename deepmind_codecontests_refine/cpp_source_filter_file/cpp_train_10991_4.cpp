#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
static void amin(T &x, U y) {
  if (x > y) x = y;
}
const int N = 2e5 + 9;
vector<int> graph[N];
vector<int> visit(N), route;
void dfs(int u) {
  visit[u] = 1;
  route.push_back(u);
  for (auto v : graph[u]) {
    if (!visit[v]) dfs(v);
    route.push_back(u);
  }
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < (m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(1);
  int dl = 0;
  for (int i = 0; i < (k); i++) {
    int cnt = 1;
    vector<int> ans;
    while (dl < route.size() && cnt < ((2 * n + k - 1) / k))
      ans.push_back(route[dl++]), ++cnt;
    if (!ans.size()) ans.push_back(1);
    printf("%d ", ans.size());
    for (auto x : ans) printf("%d ", x);
    printf("\n");
  }
  return 0;
}
