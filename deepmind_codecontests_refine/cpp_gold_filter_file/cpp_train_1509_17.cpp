#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
int s, t;
long long a[2005];
vector<pair<long long, long long>> edge[2005];
long long dis[2][2005];
map<long long, int> num[2];
vector<int> ord[2][2005];
int c[2][2005];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
               greater<pair<long long, long long>>>
    pq;
long long d[2][2005][2005];
long long e[2][2005][2005];
long long dat[2][2005][2005];
int isgood[2][2005][2005];
int nex[2][2005][2005];
int check[2005];
int main() {
  int i, j, k;
  cin >> n >> m;
  cin >> s >> t, s--, t--;
  for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
  for (i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z), x--, y--;
    edge[x].push_back(make_pair(y, z));
    edge[y].push_back(make_pair(x, z));
  }
  for (i = 0; i < 2; i++) fill(dis[i], dis[i] + n, ((1ll << 62) - 1));
  dis[0][s] = 0;
  pq.push(pair<long long, long long>(0, s));
  while (pq.size()) {
    auto x = pq.top();
    pq.pop();
    if (c[0][x.second] == 1) continue;
    c[0][x.second] = 1;
    for (auto e : edge[x.second]) {
      if (dis[0][e.first] > x.first + e.second) {
        dis[0][e.first] = x.first + e.second;
        pq.push(pair<long long, long long>(dis[0][e.first], e.first));
      }
    }
  }
  dis[1][t] = 0;
  pq.push(pair<long long, long long>(0, t));
  while (pq.size()) {
    auto x = pq.top();
    pq.pop();
    if (c[1][x.second] == 1) continue;
    c[1][x.second] = 1;
    for (auto e : edge[x.second]) {
      if (dis[1][e.first] > x.first + e.second) {
        dis[1][e.first] = x.first + e.second;
        pq.push(pair<long long, long long>(dis[1][e.first], e.first));
      }
    }
  }
  for (i = 0; i < 2; i++)
    for (j = 0; j < n; j++) num[i][dis[i][j]] = 0;
  for (i = 0; i < 2; i++) {
    int now = 0;
    for (auto it = num[i].begin(); it != num[i].end(); it++) {
      it->second = now++;
    }
  }
  for (i = 0; i < 2; i++)
    for (j = 0; j < n; j++) ord[i][num[i][dis[i][j]]].push_back(j);
  for (i = 0; i < 2; i++) {
    int x = i, y = !i;
    fill(check, check + n, 0);
    for (j = 0; j <= n; j++) {
      long long sum = 0;
      int good = 0;
      for (k = 0; k <= n; k++) {
        dat[i][k][j] = sum;
        isgood[i][k][j] = good;
        good = 0;
        for (auto e : ord[x][k])
          if (!check[e]) sum += a[e], good = 1;
      }
      for (auto e : ord[y][j]) check[e] = 1;
    }
  }
  for (k = 0; k < 2; k++) {
    for (j = 0; j <= n; j++) {
      int last = n + 1;
      for (i = n; i >= 0; i--) {
        nex[k][i][j] = last;
        if (isgood[k][i][j]) last = i;
      }
    }
  }
  for (i = 0; i <= n + 1; i++)
    for (j = 0; j <= n + 1; j++)
      e[0][i][j] = -((1ll << 62) - 1), e[1][i][j] = ((1ll << 62) - 1);
  for (i = n; i >= 0; i--) {
    for (j = n; j >= 0; j--) {
      if (nex[0][i][j] != n + 1)
        d[0][i][j] = e[0][nex[0][i][j]][j] - dat[0][i][j];
      if (nex[1][j][i] != n + 1)
        d[1][i][j] = e[1][i][nex[1][j][i]] + dat[1][j][i];
      e[0][i][j] = max(e[0][i + 1][j], d[1][i][j] + dat[0][i][j]);
      e[1][i][j] = min(e[1][i][j + 1], d[0][i][j] - dat[1][j][i]);
    }
  }
  if (d[0][0][0] > 0)
    printf("Break a heart");
  else if (d[0][0][0] == 0)
    printf("Flowers");
  else
    printf("Cry");
  return 0;
}
