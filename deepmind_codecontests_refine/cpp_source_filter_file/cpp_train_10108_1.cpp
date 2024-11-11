#include <bits/stdc++.h>
using namespace std;
int leaf[1000005], child1[1000005], child2[1000005], value[1000005],
    dp[1000005];
string type[1000005];
void dfs1(int cur) {
  if (leaf[cur]) return;
  if (child1[cur]) dfs1(child1[cur]);
  if (child2[cur]) dfs1(child2[cur]);
  if (type[cur] == "NOT")
    value[cur] = (1 - value[child1[cur]]);
  else if (type[cur] == "AND")
    value[cur] = value[child1[cur]] & value[child2[cur]];
  else if (type[cur] == "OR")
    value[cur] = value[child1[cur]] | value[child2[cur]];
  else
    value[cur] = value[child1[cur]] ^ value[child2[cur]];
  return;
}
void dfs2(int cur) {
  if (leaf[cur]) return;
  if (dp[cur] == 0) {
    dp[child1[cur]] = 0;
    dp[child2[cur]] = 0;
  } else {
    if (type[cur] == "NOT")
      dp[child1[cur]] = 1;
    else if (type[cur] == "AND") {
      if (value[child1[cur]] == 0 && value[child2[cur]] == 0) {
        dp[child1[cur]] = 0;
        dp[child2[cur]] = 0;
      } else if (value[child1[cur]] == 0 && value[child2[cur]] == 1) {
        dp[child1[cur]] = 1;
        dp[child2[cur]] = 0;
      } else if (value[child1[cur]] == 1 && value[child2[cur]] == 0) {
        dp[child1[cur]] = 0;
        dp[child2[cur]] = 1;
      } else {
        dp[child1[cur]] = 1;
        dp[child2[cur]] = 1;
      }
    } else if (type[cur] == "OR") {
      if (value[child1[cur]] == 0 && value[child2[cur]] == 0) {
        dp[child1[cur]] = 1;
        dp[child2[cur]] = 1;
      } else if (value[child1[cur]] == 0 && value[child2[cur]] == 1) {
        dp[child1[cur]] = 0;
        dp[child2[cur]] = 1;
      } else if (value[child1[cur]] == 1 && value[child2[cur]] == 0) {
        dp[child1[cur]] = 1;
        dp[child2[cur]] = 0;
      } else {
        dp[child1[cur]] = 0;
        dp[child2[cur]] = 0;
      }
    } else if (type[cur] == "XOR") {
      if (value[child1[cur]] == 0 && value[child2[cur]] == 0) {
        dp[child1[cur]] = 1;
        dp[child2[cur]] = 1;
      } else if (value[child1[cur]] == 0 && value[child2[cur]] == 1) {
        dp[child1[cur]] = 0;
        dp[child2[cur]] = 1;
      } else if (value[child1[cur]] == 1 && value[child2[cur]] == 0) {
        dp[child1[cur]] = 1;
        dp[child2[cur]] = 0;
      } else {
        dp[child1[cur]] = 1;
        dp[child2[cur]] = 1;
      }
    }
  }
  if (child1[cur]) dfs2(child1[cur]);
  if (child2[cur]) dfs2(child2[cur]);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  int i, n;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> type[i];
    if (type[i] == "IN") {
      cin >> value[i];
      leaf[i] = 1;
    } else {
      if (type[i] == "NOT")
        cin >> child1[i];
      else
        cin >> child1[i] >> child2[i];
    }
  }
  dfs1(1);
  dp[1] = 1;
  dfs2(1);
  for (i = 1; i <= n; i++) {
    if (!leaf[i]) continue;
    if (dp[i])
      cout << (1 - value[1]);
    else
      cout << value[1];
  }
  return 0;
}
