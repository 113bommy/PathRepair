#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
vector<int> tree[100005];
void dfs(int s) {
  if (vis[s]) {
    return;
  }
  vis[s] = true;
  for (int i = 0; i < tree[s].size(); i++) {
    if (!vis[tree[s][i]]) {
      cout << s << " " << tree[s][i] << endl;
      dfs(tree[s][i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d, h;
  cin >> n >> d >> h;
  if (d > 2 * h || (d == 1 && d == h)) {
    cout << "-1" << endl;
    return 0;
  }
  int idx = 1, root = 1;
  for (int i = 0; i < h && idx <= n; i++) {
    tree[idx].push_back(idx + 1);
    idx++;
  }
  idx++;
  int x = (n - (h + 1)), y = d - h;
  if (!y) {
    y = 1;
    root++;
  }
  if (y) {
    for (int j = 0; j < x / y && idx <= n; j++) {
      for (int i = 0; i < y && idx <= n; i++) {
        if (!i) {
          tree[root].push_back(idx);
          continue;
        }
        tree[idx].push_back(idx + 1);
        idx++;
      }
      idx++;
    }
    for (int i = 0; i < x % y && idx <= n; i++) {
      if (!i) {
        tree[root].push_back(idx);
        continue;
      }
      tree[idx].push_back(idx + 1);
      idx++;
    }
  }
  dfs(1);
  return 0;
}
