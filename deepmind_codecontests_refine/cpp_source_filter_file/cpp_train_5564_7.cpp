#include <bits/stdc++.h>
using namespace std;
int n, m, K, w;
char field[1000][10][11];
vector<tuple<int, int, int>> edge[1001];
int from[1001];
int main(void) {
  scanf("%d %d %d %d", &n, &m, &K, &w);
  for (int i = 0; i < K; i++)
    for (int j = 0; j < n; j++) scanf("%s", field[i][j]);
  for (int i = 0; i < K; i++)
    for (int j = i + 1; j < K; j++) {
      int curCost = 0;
      for (int k = 0; k < n; k++)
        for (int l = 0; l < m; l++)
          curCost += (field[i][k][l] != field[j][k][l]);
      edge[i].push_back(make_tuple(curCost * w, j, i));
      edge[j].push_back(make_tuple(curCost * w, i, j));
    }
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      q;
  for (int i = 0; i < K; i++) q.push(make_tuple(n * m, i, n));
  fill(from, from + K, -1);
  int ans = 0;
  vector<pair<int, int>> history;
  while (!q.empty()) {
    int curCost, cur, curFrom;
    tie(curCost, cur, curFrom) = q.top();
    q.pop();
    if (from[cur] != -1) continue;
    if (curFrom == n)
      history.push_back(make_pair(cur + 1, 0));
    else
      history.push_back(make_pair(cur + 1, curFrom + 1));
    from[cur] = curFrom;
    ans += curCost;
    for (auto &e : edge[cur]) q.push(e);
  }
  printf("%d\n", ans);
  for (auto &h : history) printf("%d %d\n", h.first, h.second);
  return 0;
}
