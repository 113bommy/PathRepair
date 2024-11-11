#include <bits/stdc++.h>
using namespace std;
const int N = 1300000;
int n;
vector<int> e[N];
int siz[N], im[N], del[N];
void dfs(int x, int fa) {
  if (siz[x] <= 2) {
    del[x] = 1;
    for (int i = 0; i < (int)e[x].size(); i++)
      if (e[x][i] != fa) dfs(e[x][i], x);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) siz[i] = (int)e[i].size();
  for (int i = 1; i <= n; i++)
    if (siz[i] == 1) dfs(i, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < (int)e[i].size(); j++)
      if (del[e[i][j]]) ++im[i];
  for (int i = 1; i <= n; i++)
    if (!del[i]) {
      int cnt = 0;
      for (int j = 0; j < (int)e[i].size(); j++)
        if (siz[e[i][j]] - ((im[e[i][j]]) < (2) ? (im[e[i][j]]) : (2)) > 1 &&
            (!del[i]))
          cnt++;
      if (cnt > 2) {
        printf("No");
        return 0;
      }
    }
  printf("Yes");
  return 0;
}
