#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> e[200010];
int vis[200010];
int N, M;
vector<int> ans1, ans2, sub1, sub2;
bool Y1 = true, Y2 = true;
bool dfs(int x, int col, vector<int>& ans) {
  bool flg = 1;
  int bas = 0;
  if (vis[x] == 1) bas = 1;
  col ^= bas;
  for (int i = 0; i < e[x].size(); i++) {
    int to = e[x][i].first;
    int des;
    if (col == e[x][i].second)
      des = 2;
    else
      des = 1;
    if (!vis[to]) {
      if (des == 1) ans.push_back(to);
      vis[to] = des;
      flg &= dfs(to, col ^ bas, ans);
    } else {
      if (vis[to] != des) flg = 0;
    }
  }
  return flg;
}
void res(int x) {
  vis[x] = 0;
  for (int i = 0; i < e[x].size(); i++) {
    int to = e[x][i].first;
    if (vis[to]) res(to);
  }
}
signed main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; i++) {
    int f, t;
    string sub;
    scanf("%d %d", &f, &t);
    cin >> sub;
    if (sub[0] == 'R') {
      e[f].push_back({t, 0});
      e[t].push_back({f, 0});
    } else {
      e[f].push_back({t, 1});
      e[t].push_back({f, 1});
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= N; i++) {
    if (!vis[i]) {
      bool f1, f2;
      sub1.push_back(i);
      vis[i] = 1;
      f1 = dfs(i, 0, sub1);
      res(i);
      vis[i] = 2;
      f2 = dfs(i, 0, sub2);
      if (!f1 && !f2)
        Y1 = 0;
      else {
        if (!f1) {
          while (sub2.size() > 0) {
            ans1.push_back(sub2.back());
            sub2.pop_back();
          }
        } else if (!f2) {
          while (sub1.size() > 0) {
            ans1.push_back(sub1.back());
            sub1.pop_back();
          }
        } else if (sub1.size() < sub2.size()) {
          while (sub1.size() > 0) {
            ans1.push_back(sub1.back());
            sub1.pop_back();
          }
        } else {
          while (sub2.size() > 0) {
            ans1.push_back(sub2.back());
            sub2.pop_back();
          }
        }
      }
      sub1.clear();
      sub2.clear();
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= N; i++) {
    if (!vis[i]) {
      bool f1, f2;
      sub1.push_back(i);
      vis[i] = 1;
      f1 = dfs(i, 1, sub1);
      res(i);
      vis[i] = 2;
      f2 = dfs(i, 1, sub2);
      if (!f1 && !f2)
        Y2 = 0;
      else {
        if (!f1) {
          while (sub2.size() > 0) {
            ans2.push_back(sub2.back());
            sub2.pop_back();
          }
        } else if (!f2) {
          while (sub1.size() > 0) {
            ans2.push_back(sub1.back());
            sub1.pop_back();
          }
        } else if (sub1.size() < sub2.size()) {
          while (sub1.size() > 0) {
            ans2.push_back(sub1.back());
            sub1.pop_back();
          }
        } else {
          while (sub2.size() > 0) {
            ans2.push_back(sub2.back());
            sub2.pop_back();
          }
        }
      }
      sub1.clear();
      sub2.clear();
    }
  }
  if (!Y1 && !Y2)
    puts("-1");
  else if (!Y1) {
    printf("%d\n", ans2.size());
    for (int i = 0; i < ans2.size(); i++) printf("%d ", ans2[i]);
  } else if (!Y2) {
    printf("%d\n", ans1.size());
    for (int i = 0; i < ans1.size(); i++) printf("%d ", ans1[i]);
  } else if (ans1.size() > ans2.size()) {
    printf("%d\n", ans2.size());
    for (int i = 0; i < ans2.size(); i++) printf("%d ", ans2[i]);
  } else {
    printf("%d\n", ans1.size());
    for (int i = 0; i < ans1.size(); i++) printf("%d ", ans1[i]);
  }
  return 0;
}
