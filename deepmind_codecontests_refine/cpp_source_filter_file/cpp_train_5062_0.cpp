#include <bits/stdc++.h>
using namespace std;
int c[200005];
int need[200005];
int hel[200005];
vector<int> sol;
vector<int> g[200005], a[200005];
int n, m;
void dfs(int in) {
  c[in] = 1;
  for (int i = 0; i < g[in].size(); i++) {
    int ch = g[in][i];
    if (!c[ch]) {
      dfs(ch);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int l;
    scanf("%d", &l);
    for (int j = 0; j < l; j++) {
      int v;
      scanf("%d", &v);
      a[i].push_back(v);
    }
  }
  for (int i = 1; i < n; i++) {
    int be = 0;
    while (be < a[i].size() && be < a[i + 1].size() &&
           a[i][be] == a[i + 1][be]) {
      be++;
    }
    if (a[i].size() > a[i + 1].size() && be == a[i + 1].size()) {
      printf("No\n");
      return 0;
    }
    if (be == a[i].size()) {
      continue;
    }
    if (a[i][be] < a[i + 1][be]) {
      g[a[i + 1][be]].push_back(a[i][be]);
      continue;
    }
    need[a[i][be]] = 1;
    hel[a[i + 1][be]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (need[i] && !c[i]) {
      dfs(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (c[i]) {
      sol.push_back(i);
      if (hel[i]) {
        printf("No\n");
        return 0;
      }
    }
  }
  printf("Yes\n");
  printf("%d\n", sol.size());
  for (int i = 0; i < sol.size(); i++) {
    printf("%d ", sol[i]);
  }
  cout << endl;
  return 0;
}
