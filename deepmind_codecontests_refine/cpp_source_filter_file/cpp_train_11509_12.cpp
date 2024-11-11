#include <bits/stdc++.h>
using namespace std;
int n, k, t, ans, vis[512][512], use[32000];
int component[512][512], csize[32000];
char mt[512][512];
void dfs(int x, int y) {
  if (vis[x][y] || mt[x][y] != '.') {
    return;
  }
  csize[component[x][y] = t]++;
  vis[x][y] = 1;
  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", mt[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!vis[i][j] && mt[i][j] == '.') {
        t++, dfs(i, j);
      }
    }
  }
  for (int i = 1; i <= n - k + 1; i++) {
    for (int x = i; x < i + k; x++) {
      for (int y = 1; y <= k; y++) {
        csize[component[x][y]]--;
      }
    }
    for (int j = 1; j <= n - k + 1; j++) {
      int cnt = k * k;
      for (int y = j; y < j + k; y++) {
        if (use[component[i - 1][y]] != t) {
          cnt += max(0, csize[component[i - 1][y]]);
          use[component[i - 1][y]] = t;
        }
      }
      for (int x = i; x < i + k; x++) {
        if (use[component[x][j - 1]] != t) {
          cnt += max(0, csize[component[x][j - 1]]);
          use[component[x][j - 1]] = t;
        }
      }
      for (int y = j; y < j + k; y++) {
        if (use[component[i + k][y]] != t) {
          cnt += max(0, csize[component[i + k][y]]);
          use[component[i + k][y]] = t;
        }
      }
      for (int x = i; x < i + k; x++) {
        if (use[component[x][j + k]] != t) {
          cnt += max(0, csize[component[x][j + k]]);
          use[component[x][j + k]] = t;
        }
      }
      ans = max(ans, cnt);
      if (j + 1 <= n - k + 1) {
        for (int x = i; x < i + k; x++) {
          csize[component[x][j + k]]--;
          csize[component[x][j]]++;
        }
      }
      t++;
    }
    for (int x = i; x < i + k; x++) {
      for (int y = n - k + 1; y <= n; y++) {
        csize[component[x][y]]++;
      }
    }
  }
  printf("%d\n", ans);
}
