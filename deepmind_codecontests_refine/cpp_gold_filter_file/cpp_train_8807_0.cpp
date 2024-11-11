#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[5005];
vector<int> v[5005];
int vis[5005];
int ans;
bool check(int a, int b) {
  vis[a] = 1;
  if (v[a].size() < ans) {
    v[a].push_back(b);
    return true;
  }
  for (vector<int>::iterator it = v[a].begin(); it != v[a].end(); it++) {
    if (!vis[*it] && check(*it, a)) {
      *it = b;
      return true;
    }
  }
  return false;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  ans = 0;
  for (int i = 0; i < m; i++) {
    int first, second;
    scanf("%d %d", &first, &second);
    memset(vis, 0, sizeof(vis));
    if (check(first, second)) continue;
    memset(vis, 0, sizeof(vis));
    if (check(second, first)) continue;
    ans++;
    v[second].push_back(first);
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    for (vector<int>::iterator it = v[i].begin(); it != v[i].end(); it++) {
      printf("%d %d\n", i, *it);
    }
  }
}
