#include <bits/stdc++.h>
using namespace std;
vector<int> E[2005];
int belong[2000 + 5], used[2000 + 5];
int group[2000 + 5], cnt[2000 + 4];
void dfs(int p, int d) {
  int i;
  if (used[p] == 1) return;
  used[p] = 1;
  belong[p] = d;
  for (i = 0; i < E[p].size(); i++) dfs(E[p][i], d);
}
int main() {
  int i, j, k;
  int n, m;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  int idx = 0;
  for (i = 1; i <= n; i++) {
    if (used[i] == 0) {
      idx++;
      dfs(i, idx);
    }
  }
  int mm = 0;
  scanf("%d", &mm);
  for (i = 1; i <= n; i++) {
    cnt[belong[i]]++;
  }
  for (i = 1; i <= mm; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (belong[a] == belong[b]) group[belong[a]] = 1;
  }
  int Max = -1;
  for (i = 1; i <= idx; i++) {
    if (group[i] == 0) {
      if (cnt[i] > Max) Max = cnt[i];
    }
  }
  printf("%d\n", Max);
}
