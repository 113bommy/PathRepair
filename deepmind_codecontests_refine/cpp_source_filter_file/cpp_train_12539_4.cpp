#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100005;
const int MAX_M = 100005;
vector<int> e[MAX_N];
int chet[MAX_N];
int now_chet[MAX_N];
int flag[MAX_N];
int cnt = 0;
int root = 0;
vector<int> ans;
void dfs_comp(int v) {
  if (chet[v]) cnt++;
  flag[v] = 1;
  for (int i = 0; i < (int)e[v].size(); i++)
    if (flag[e[v][i]] == 0) dfs_comp(e[v][i]);
}
void dfs(int v, int pred) {
  flag[v] = 1;
  now_chet[v] = 1 - now_chet[v];
  ans.push_back(v);
  int sum = 0;
  for (int i = 0; i < (int)e[v].size(); i++)
    if (flag[e[v][i]] == 0) {
      dfs(e[v][i], v);
      ans.push_back(v);
      now_chet[v] = 1 - now_chet[v];
    }
  for (int i = 0; i < (int)e[v].size(); i++)
    if (e[v][i] == pred) {
      if (now_chet[e[v][i]] != chet[e[v][i]]) {
        ans.push_back(e[v][i]);
        ans.push_back(v);
        now_chet[e[v][i]] = 1 - now_chet[e[v][i]];
        now_chet[v] = 1 - now_chet[v];
      }
    }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 0; i < n; i++) scanf("%d", &chet[i]);
  int cnt_all = 0;
  int p = -1;
  for (int i = 0; i < n; i++)
    if (flag[i] == 0) {
      cnt = 0;
      dfs_comp(i);
      if (cnt > 0) {
        cnt_all++;
        p = i;
      }
    }
  if (cnt_all > 1) {
    cout << -1;
    return 0;
  }
  if (p == -1) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) flag[i] = 0;
  root = p;
  dfs(p, -1);
  if (now_chet[p] != chet[p]) ans.pop_back();
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i] + 1);
  return 0;
}
