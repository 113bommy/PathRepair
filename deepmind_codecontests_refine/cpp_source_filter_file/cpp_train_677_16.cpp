#include <bits/stdc++.h>
using namespace ::std;
const int N = 3000, M = 5000, INF = 1000000000;
int n, m;
vector<int> ad[N + 5];
int dist[N + 5][N + 5];
vector<pair<int, int> > dp1[N + 5];
vector<pair<int, pair<int, int> > > dp2[N + 5];
int path[N + 5][5];
bool chk[N + 5];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dist[i][j] = INF;
  for (int i = 0; i < m; i++) {
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    ad[v1].push_back(v2);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) chk[j] = false;
    queue<pair<int, int> > q;
    q.push(pair<int, int>(i, 0));
    dist[i][i] = 0, chk[i] = true;
    while (!q.empty()) {
      int now = q.front().first;
      int distance = q.front().second;
      q.pop();
      for (auto next : ad[now]) {
        if (!chk[next]) {
          chk[next] = true;
          dist[i][next] = distance + 1;
          q.push(pair<int, int>(next, distance + 1));
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] != INF && i != j) {
        dp1[i].push_back(pair<int, int>(dist[i][j], j));
        int now = dp1[i].size() - 1;
        while (now != 0 && dp1[i][now] < dp1[i][now - 1]) {
          swap(dp1[i][now], dp1[i][now - 1]);
          now--;
        }
        if (dp1[i].size() > 3) dp1[i].pop_back();
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] != INF && i != j) {
        for (int k = 0; k < dp1[j].size(); k++) {
          if (dp1[j][k].second == i) continue;
          dp2[i].push_back(
              pair<int, pair<int, int> >(dist[i][j] + dp1[j][k].first,
                                         pair<int, int>(j, dp1[j][k].second)));
          int now = dp2[i].size() - 1;
          while (now != 0 && dp2[i][now] < dp2[i][now - 1]) {
            swap(dp2[i][now], dp2[i][now - 1]);
            now--;
          }
          if (dp2[i].size() > 9) dp2[i].pop_back();
        }
      }
    }
  }
  int ans = -1, a1, a2, a3, a4;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] != INF && i != j) {
        for (int k = 0; k < dp2[j].size(); k++) {
          if (dp2[j][k].second.first == i || dp2[j][k].second.second == i)
            continue;
          if (ans < dist[i][j] + dp2[j][k].first)
            ans = dist[i][j] + dp2[j][k].first, a1 = i, a2 = j,
            a3 = dp2[j][k].second.first, a4 = dp2[j][k].second.second;
        }
      }
    }
  }
  printf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}
