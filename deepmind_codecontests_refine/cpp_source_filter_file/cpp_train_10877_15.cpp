#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
pair<int, int> a[N];
vector<int> v[N];
int ans[N];
bool check(int p, int first) {
  return first >= a[p].first && first <= a[p].second;
}
void dfs(int u, int flag) {
  if (ans[u] == flag) return;
  if (ans[u] == 3 - flag) {
    printf("IMPOSSIBLE\n");
    exit(0);
  }
  ans[u] = flag;
  for (int i = 0; i < v[u].size(); i++) {
    int first = v[u][i];
    dfs(first, 3 - flag);
  }
}
int main() {
  int t, T, n, m;
  scanf("%d%d%d%d", &t, &T, &n, &m);
  int first = -0x7fffffff, second = 0x7fffffff;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
    first = max(first, a[i].first);
    second = min(second, a[i].second);
  }
  while (m--) {
    int ax, ay;
    scanf("%d%d", &ax, &ay);
    v[ax].push_back(ay);
    v[ay].push_back(ax);
  }
  if (first + second < t)
    first = t - second;
  else if (first + second > T)
    second = T - first;
  if (first < 0 || second < 0) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!check(i, first) && !check(i, second)) {
      printf("IMPOSSIBLE\n");
      return 0;
    }
    if (!check(i, first)) dfs(i, 2);
    if (!check(i, second)) dfs(i, 1);
  }
  for (int i = 1; i <= n; i++)
    if (!ans[i]) dfs(i, 1);
  printf("POSSIBLE\n");
  printf("%d %d\n", second, first);
  for (int i = 1; i <= n; i++) printf("%d", ans[i]);
  printf("\n");
  return 0;
}
