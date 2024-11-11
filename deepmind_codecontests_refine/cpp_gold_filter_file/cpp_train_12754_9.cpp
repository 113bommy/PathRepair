#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int vis[1000005];
struct node {
  vector<int> vs;
} scc[1000005];
int cnt_block;
void dfs(int x, int key) {
  if (vis[x]) {
    return;
  }
  vis[x] = 1;
  scc[key].vs.push_back(x);
  dfs(a[x], key);
}
bool cmp(node x, node y) { return x.vs.size() < y.vs.size(); }
vector<int> temp;
int ans[1000005];
int pcd[1000005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ++cnt_block;
      dfs(i, cnt_block);
    }
  }
  sort(scc + 1, scc + 1 + cnt_block, cmp);
  for (int i = 1; i <= cnt_block; i++) {
    temp.clear();
    if (scc[i].vs.size() & 1) {
      int mid = (scc[i].vs.size() + 1) / 2;
      for (int j = 1; j <= mid; j++) {
        pcd[(j * 2) - 1] = scc[i].vs[j - 1];
      }
      for (int j = mid + 1; j <= scc[i].vs.size(); j++) {
        pcd[(j - mid) * 2] = scc[i].vs[j - 1];
      }
      for (int j = 1; j <= scc[i].vs.size(); j++) {
        ans[pcd[j]] = pcd[j + 1];
      }
      ans[pcd[scc[i].vs.size()]] = pcd[1];
    } else {
      if (i == cnt_block) {
        printf("-1");
        return 0;
      }
      if (scc[i].vs.size() ^ scc[i + 1].vs.size()) {
        printf("-1");
        return 0;
      }
      for (int j = 0; j < scc[i].vs.size(); j++) {
        temp.push_back(scc[i].vs[j]);
        temp.push_back(scc[i + 1].vs[j]);
      }
      for (int j = 0; j < temp.size() - 1; j++) {
        ans[temp[j]] = temp[j + 1];
      }
      ans[temp[temp.size() - 1]] = temp[0];
      i++;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
}
