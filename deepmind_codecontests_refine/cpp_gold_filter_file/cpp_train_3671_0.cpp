#include <bits/stdc++.h>
using namespace std;
bool isrange(int second, int first, int n, int m) {
  if (0 <= second && second < n && 0 <= first && first < m) return true;
  return false;
}
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1},
    ddy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, ddx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
vector<int> v[222222];
int sz[222222], ch[222222], vis[222222];
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int e = 1; e <= n; e++) {
      v[e].clear();
      sz[e] = 0;
      ch[e] = 0;
      vis[e] = 0;
    }
    for (int e = 0; e < n - 1; e++) {
      int a, b;
      scanf("%d%d", &a, &b);
      v[a].push_back(b);
      v[b].push_back(a);
      sz[a]++;
      sz[b]++;
    }
    int tot = 0;
    queue<int> q;
    for (int e = 1; e <= n; e++) {
      if (sz[e] == 1) q.push(e);
    }
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      vis[now] = 1;
      for (int e = 0; e < (int)v[now].size(); e++) {
        int nx = v[now][e];
        if (vis[nx] == 0) {
          ch[nx]++;
          if ((ch[nx] % k) == 0) tot++;
          sz[nx]--;
          if (sz[nx] == 1 && (ch[nx] % k) == 0) q.push(nx);
        }
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
