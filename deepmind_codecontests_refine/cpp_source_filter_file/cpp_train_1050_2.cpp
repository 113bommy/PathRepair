#include <bits/stdc++.h>
using namespace std;
int n, a[((int)2001 * 1000)], b[((int)2001 * 1000)], comp[((int)2001 * 1000)];
vector<int> v, e[((int)2001 * 1000)], vec[((int)2001 * 1000)];
bool mark[((int)2001 * 1000)], dead[((int)2001 * 1000)],
    type[((int)2001 * 1000)];
void dfs(int x, int root) {
  mark[x] = 1;
  comp[x] = root;
  vec[root].push_back(x);
  for (int i = 0; i < e[x].size(); i++)
    if (!mark[e[x][i]]) dfs(e[x][i], root);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &a[i], &b[i]), v.push_back(a[i]), v.push_back(b[i]);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin(),
    b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin(),
    e[a[i]].push_back(b[i]), e[b[i]].push_back(a[i]);
  for (int i = 0; i < v.size(); i++)
    if (!mark[i]) {
      dfs(i, i);
      int cnt = 0;
      for (int j = 0; j < vec[i].size(); j++) cnt += e[vec[i][j]].size();
      if (cnt > 2 * (int)vec[i].size()) return cout << "-1\n", 0;
      type[i] = (cnt == 2 * (int)vec[i].size());
    }
  int l = 0, r = 1e9 + 10;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    memset(dead, 0, sizeof dead);
    bool flg = 1;
    for (int i = (int)v.size() - 1; i >= 0; i--) {
      if (v[i] <= mid) break;
      if (type[comp[v[i]]] || dead[comp[v[i]]]) {
        flg = 0;
        break;
      }
      dead[comp[v[i]]] = 1;
    }
    if (flg)
      r = mid;
    else
      l = mid;
  }
  cout << r << "\n";
  return 0;
}
