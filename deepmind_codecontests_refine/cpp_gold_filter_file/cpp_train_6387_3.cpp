#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> v[105];
int group[105];
int cnt_group[105][3] = {0};
bool vs[105];
int n_group;
int dfs(int in, int g) {
  vs[in] = true;
  group[in] = g;
  for (int i = 0; i < v[in].size(); i++) {
    if (!vs[v[in][i]]) dfs(v[in][i], g);
  }
  return 0;
}
int main() {
  scanf("%d %d", &n, &m);
  int a, b;
  for (int i = 0; i < n; i++) {
    group[i] = -1;
    vs[i] = false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    v[a - 1].push_back(b - 1);
    v[b - 1].push_back(a - 1);
  }
  n_group = 0;
  for (int i = 0; i < n; i++) {
    if (vs[i]) continue;
    dfs(i, n_group);
    n_group++;
  }
  int sol = 0;
  int cntcnt = 0;
  for (int i = 0; i < n_group; i++) {
    int cnt = 0;
    bool all2 = true;
    for (int j = 0; j < n; j++) {
      if (group[j] == i) {
        if (v[j].size() != 2) all2 = false;
        cnt++;
      }
    }
    if (all2) {
      if (cnt % 2 == 0) {
        cnt_group[i][0] = cnt / 2;
        cnt_group[i][1] = cnt / 2;
        cnt_group[i][2] = 0;
      } else {
        cnt_group[i][0] = cnt / 2;
        cnt_group[i][1] = cnt / 2;
        cnt_group[i][2] = 1;
        sol++;
      }
    } else {
      if (cnt % 2 == 0) {
        cnt_group[i][0] = cnt / 2;
        cnt_group[i][1] = cnt / 2;
        cnt_group[i][2] = 0;
      } else {
        cnt_group[i][0] = cnt / 2 + 1;
        cnt_group[i][1] = cnt / 2;
        cnt_group[i][2] = 0;
        cntcnt++;
      }
    }
  }
  if (cntcnt % 2 == 0)
    printf("%d\n", sol);
  else
    printf("%d\n", sol + 1);
  return 0;
}
