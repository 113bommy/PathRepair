#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int sum;
bool vis[1000005];
vector<int> e[1000005];
multiset<int> s;
int dfs(int x) {
  if (vis[x]) return 0;
  vis[x] = 1;
  int cnt = 1;
  for (int i = 0; i < e[x].size(); i++) cnt += dfs(e[x][i]);
  return cnt;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      int x = dfs(i);
      sum += x;
      s.insert(x);
    }
  for (int i = 0;; i++) {
    if (sum >= 2 * (s.size() - 1)) {
      printf("%d\n", i);
      return 0;
    }
    int x = *s.begin();
    s.erase(s.begin());
    int y = *s.begin();
    s.erase(s.begin());
    sum -= x + y - min(x + y, k);
    s.insert(min(x + y, k));
  }
  return 0;
}
