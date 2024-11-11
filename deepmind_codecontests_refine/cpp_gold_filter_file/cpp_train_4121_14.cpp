#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long x, y;
  Node() {}
  Node(long long a, long long b) {
    x = a;
    y = b;
  }
};
vector<int> eage[35];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int deg[35];
int vis[35];
int n;
long long len = 1 << 30;
Node coor[35];
void dfs(int p, int d) {
  int di = 0;
  for (int i = 0; i < eage[p].size(); i++) {
    if (vis[eage[p][i]] == 0) {
      if (di == d) di = (di + 1) % 4;
      vis[eage[p][i]] = 1;
      coor[eage[p][i]].x = coor[p].x + dir[di][0] * len;
      coor[eage[p][i]].y = coor[p].y + dir[di][1] * len;
      len = len / 2;
      dfs(eage[p][i], (di + 2) % 4);
      di = (di + 1) % 4;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    eage[a].push_back(b);
    eage[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  for (int i = 1; i <= n; i++)
    if (deg[i] > 4) {
      printf("NO\n");
      return 0;
    }
  vis[1] = 1;
  dfs(1, -10);
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%I64d %I64d\n", coor[i].x, coor[i].y);
  return 0;
}
