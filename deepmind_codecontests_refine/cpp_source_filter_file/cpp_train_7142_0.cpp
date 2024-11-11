#include <bits/stdc++.h>
using namespace std;
int n;
int a[100039], b[100039], curpos[100039];
vector<vector<int>> ans;
int vis[100039];
vector<int> tmp;
void dfs(int x) {
  vis[x] = 1;
  tmp.push_back(x);
  if (vis[curpos[x]]) return;
  dfs(curpos[x]);
}
int main() {
  scanf("%d", &n);
  map<int, int> mp;
  for (int i = (1); i < n + 1; i++) {
    scanf("%d", &a[i]);
    mp[a[i]] = i;
  }
  for (int i = (1); i < n + 1; i++) b[i] = a[i];
  sort(b + 1, b + 1 + n);
  for (int i = (1); i < n + 1; i++) curpos[i] = mp[b[i]];
  for (int i = (1); i < n + 1; i++) {
    if (!vis[i]) {
      dfs(i);
      ans.push_back(tmp);
    }
    tmp.clear();
  }
  printf("%d\n", ans.size());
  for (int i = (0); i < ans.size(); i++) {
    printf("%d ", ans.size());
    for (auto p : ans[i]) printf("%d ", p);
    printf("\n");
  }
  return 0;
}
