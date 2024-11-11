#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
int deep[N];
int dp[N][2];
int ans1 = 1;
void dfs(int now, int pre) {
  int flag1 = 0, flag2 = 0;
  for (int i = 0; i < v[now].size(); i++) {
    if (v[now][i] == pre) continue;
    dfs(v[now][i], now);
    if (dp[v[now][i]][0] == 1) {
      flag1++;
    }
    if (dp[v[now][i]][1] == 1) {
      flag2++;
    }
  }
  if (flag1 == 0 && flag2 == 0) {
    dp[now][1] = 1;
    return;
  }
  if (v[now].size() == 1 && flag2 >= 1) {
    ans1 = 3;
  }
  if (flag1 >= 1 && flag2 >= 1) {
    ans1 = 3;
  }
  if (flag1 >= 1) {
    dp[now][1] = 1;
  }
  if (flag2 >= 1) {
    dp[now][0] = 1;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  int ans2 = n - 1;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < v[i].size(); j++) {
      if (v[v[i][j]].size() == 1) {
        cnt++;
      }
    }
    if (cnt > 1) ans2 -= cnt - 1;
  }
  printf("%d %d", ans1, ans2);
}
