#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 100;
vector<int> node[N];
vector<pair<int, int>> ans;
int mmax;
void dfs(int u, int fa, int t) {
  int temp = t;
  ans.push_back(make_pair(u, t));
  int son = node[u].size() - (u != 1);
  for (auto v : node[u]) {
    if (v == fa) continue;
    if (t == mmax) {
      t = mmax - son - 1;
      ans.push_back(make_pair(u, t));
    }
    son--;
    t++;
    dfs(v, u, t);
    ans.push_back(make_pair(u, t));
  }
  if (u != 1 && t != temp - 1) ans.push_back(make_pair(u, temp - 1));
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    node[u].push_back(v);
    node[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) mmax = max(mmax, (int)node[i].size());
  dfs(1, -1, 0);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
