#include <bits/stdc++.h>
using namespace std;
vector<int> E[100005];
int n, num = 0;
int tar;
vector<int> lea;
void dfs(int fa, int u) {
  if (E[u].size() == 1) lea.push_back(u);
  int q = 0;
  for (int i = 0; i < E[u].size(); i++) {
    if (E[u][i] != fa) {
      q++;
      dfs(u, E[u][i]);
    }
  }
  if (q > 1) {
    num++;
    tar = u;
  }
  return;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  int s;
  for (int i = 1; i <= n; i++) {
    if (E[i].size() == 1) {
      s = i;
      break;
    }
  }
  dfs(0, s);
  if (num <= 1) {
    if (num == 0) {
      printf("Yes\n1\n1 %d\n", lea[0], lea[1]);
      return 0;
    }
    printf("Yes\n%d\n", lea.size());
    for (int i = 0; i < lea.size(); i++) {
      printf("%d %d\n", tar, lea[i]);
    }
  } else
    printf("No\n");
  return 0;
}
