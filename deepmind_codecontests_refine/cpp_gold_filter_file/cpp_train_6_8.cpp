#include <bits/stdc++.h>
using namespace std;
int n, s, a[200010];
map<int, int> mp1;
map<int, vector<int> > mp2;
vector<vector<int> > ans;
void dfs(int u) {
  while (!mp2[u].empty()) {
    int i = mp2[u].back();
    mp2[u].pop_back();
    dfs(a[i]);
    ans.back().push_back(i);
  }
  mp2.erase(u);
}
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), ++mp1[a[i]];
  int j = 1;
  for (auto it = mp1.begin(); it != mp1.end(); j += it->second, ++it)
    for (int i = j; i < j + it->second; i++)
      if (a[i] != it->first) mp2[it->first].push_back(i);
  while (!mp2.empty()) {
    ans.push_back(vector<int>());
    dfs(mp2.begin()->first);
    reverse(ans.back().begin(), ans.back().end());
    s -= ans.back().size();
  }
  if (s < 0) return puts("-1"), 0;
  int b = min(s, (int)ans.size()), d = 0;
  printf("%d\n", ans.size() - (b >= 3 ? b - 2 : 0));
  if (b >= 3) {
    for (int i = 0; i < b; i++) d += ans[i].size();
    printf("%d\n", d);
    for (int i = 0; i < b; i++)
      for (auto c : ans[i]) printf("%d ", c);
    printf("\n%d\n", b);
    for (int i = b - 1; i + 1; i--) printf("%d ", ans[i][0]);
    printf("\n");
  }
  for (int i = (b >= 3 ? b : 0); i < ans.size(); i++) {
    printf("%d\n", ans[i].size());
    for (auto c : ans[i]) printf("%d ", c);
    printf("\n");
  }
  return 0;
}
