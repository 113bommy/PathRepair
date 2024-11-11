#include <bits/stdc++.h>
using namespace std;
int cnt[2], n;
vector<int> a[200010];
void dfs(int u, int f, int c) {
  cnt[u]++;
  for (auto v : a[u])
    if (v != f) dfs(v, u, c ^ 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0, 0);
  printf("%d", min(cnt[0], cnt[1]) - 1);
  return 0;
}
