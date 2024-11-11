#include <bits/stdc++.h>
using namespace std;
int f[1001000];
int dp[22][1001000];
int get(int x, int k) {
  for (int i = 21; i >= 0; i--)
    if (k & (1 << i)) x = dp[i][x];
  return x;
}
int dist[1001000];
int foi[1001000];
vector<int> L[1001000];
char str[1001000];
char nova[1001000];
void bfs(int x, int dc) {
  queue<pair<int, int> > Q;
  Q.push(pair<int, int>(x, 0));
  while (Q.size()) {
    pair<int, int> u = Q.front();
    Q.pop();
    for (vector<int>::iterator it = L[u.first].begin(); it < L[u.first].end();
         it++)
      if (!foi[*it]) {
        foi[*it] = 1;
        dist[*it] = 1 + u.second;
        Q.push(pair<int, int>(*it, dist[*it]));
      }
  }
}
char debugs[1001000];
int main() {
  int n, m;
  scanf(" %s", str);
  n = strlen(str);
  scanf("%d", &m);
  while (m--) {
    int d, k;
    scanf("%d%d", &k, &d);
    for (int i = 0; i <= n; i++) {
      L[i].clear();
      dist[i] = 9999999;
      foi[i] = 0;
    }
    int cont = 0;
    for (int r = 0; r < d; r++)
      for (int i = r; i < k; i += d) {
        L[i + 1].push_back(cont);
        f[cont] = i + 1;
        ;
        cont++;
      }
    f[k] = k;
    bfs(k, 0);
    for (int i = 0; i < k; i++) dp[0][i] = f[i];
    dp[0][k] = k;
    for (int j = 1; j < 22; j++) {
      for (int i = 0; i < k; i++) {
        dp[j][i] = dp[j - 1][dp[j - 1][i]];
        ;
      }
      dp[j][k] = k;
    }
    for (int i = 0; i < k; i++)
      ;
    for (int i = 0; i < n; i++) {
      int y0 = 0;
      int p0 = i;
      int u = get(0, i + 1) - 1;
      if (i + k > n) y0 = i - n + k, p0 = n - k;
      u = get(y0, p0 + 1) - 1;
      ;
      if (dist[y0] > p0) {
        nova[i] = str[u];
        continue;
      }
      int p = dist[y0];
      nova[i] = str[p0 - p + k];
      debugs[i] = str[p0 - p + k];
      if (debugs[i] < 'a' || debugs[i] > 'z') debugs[i] = '?';
    }
    for (int i = 0; i < n; i++) str[i] = nova[i];
    printf("%s\n", str);
    for (int i = 0; i < n; i++)
      ;
    ;
  }
}
