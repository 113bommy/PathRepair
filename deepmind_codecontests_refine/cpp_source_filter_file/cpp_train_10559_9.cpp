#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 1, inf = 1e9;
int n, ted;
bool mark[maxn];
vector<int> e[maxn], e_rev[maxn];
void dfs(int v) {
  mark[v] = 1;
  ted++;
  for (auto u : e[v]) {
    if (mark[u] == 0) {
      dfs(u);
    }
  }
  return;
}
void sfd(int v) {
  mark[v] = 1;
  ted++;
  for (auto u : e_rev[v]) {
    if (mark[u] == 0) {
      dfs(u);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int t;
      scanf("%d", &t);
      if (t > 0) {
        e[i].push_back(j);
        e_rev[j].push_back(i);
      }
    }
  }
  dfs(1);
  if (ted != n) {
    printf("NO\n");
    return 0;
  }
  ted = 0;
  for (int i = 1; i <= n; i++) {
    mark[i] = 0;
  }
  sfd(1);
  if (ted != n) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  return 0;
}
