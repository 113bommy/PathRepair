#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > table[5005];
int DP[5005][5005];
int from[5005][5005], path[5005];
bool can[5005], visited[5005];
int n, m, T;
int maxx;
bool DFS(int a) {
  if (a == 1) return true;
  if (visited[a]) return can[a];
  visited[a] = true;
  if (table[a].size() == 0) {
    can[a] = false;
    return false;
  }
  int fr;
  int cost;
  for (int i = 0; i < table[a].size(); i++) {
    if (DFS(table[a][i].first)) {
      fr = table[a][i].first;
      cost = table[a][i].second;
      for (int j = 1; j <= n; j++) {
        if (DP[fr][j] < maxx) {
          if (DP[fr][j] + cost < DP[a][j + 1]) {
            DP[a][j + 1] = DP[fr][j] + cost;
            from[a][j + 1] = fr;
          }
        }
      }
      can[a] = true;
    }
  }
  return can[a];
}
int main() {
  scanf("%d%d%d", &n, &m, &T);
  maxx = 2099999999;
  int a, b, c;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    table[b].push_back(make_pair(a, c));
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      DP[i][j] = maxx;
    }
  }
  DP[1][1] = 0;
  DFS(n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (DP[n][i] < maxx && DP[n][i] <= T) {
      ans = i;
    }
  }
  printf("%d\n", ans);
  int cur = 0, posi = n, jump = ans;
  while (posi != 1) {
    path[cur++] = posi;
    posi = from[posi][jump];
    jump--;
  }
  path[cur++] = 1;
  for (int i = cur - 1; i >= 0; i--) {
    printf("%d ", path[i]);
  }
}
