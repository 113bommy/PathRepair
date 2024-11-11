#include <bits/stdc++.h>
using namespace std;
const int MAX = 209;
vector<int> v[MAX];
int n, x, y, deep, ans;
int dfs(int x, int pre) {
  int s = 0, maxd1 = 0, maxd2 = 0;
  for (auto u : v[x])
    if (u != pre) {
      s = max(dfs(u, x), s);
      if (deep > maxd1)
        maxd2 = maxd1, maxd1 = deep;
      else
        maxd2 = max(maxd2, deep);
    }
  s = max(s, maxd1 + maxd2), deep = maxd1 + 1;
  return s;
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++)
    cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
  for (int i = 1; i <= n; i++)
    for (auto j : v[i]) x = dfs(i, j), y = dfs(j, i), ans = max(ans, x * y);
  cout << ans << endl;
  return 0;
}
