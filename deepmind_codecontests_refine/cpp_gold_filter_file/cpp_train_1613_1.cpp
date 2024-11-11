#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int max_n = 3005;
int n, m;
vector<int> g[max_n];
int d[max_n][max_n];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  memset(d, -1, sizeof d);
  for (int i = 0; i < (int)n; i++) {
    queue<int> q;
    q.push(i);
    d[i][i] = 0;
    while (!q.empty()) {
      int s = q.front();
      q.pop();
      for (int j = 0; j < (int)g[s].size(); j++) {
        int to = g[s][j];
        if (d[i][to] == -1) {
          d[i][to] = d[i][s] + 1;
          q.push(to);
        }
      }
    }
  }
  int s[2], t[2], l[2];
  scanf("%d%d%d", &s[0], &t[0], &l[0]);
  scanf("%d%d%d", &s[1], &t[1], &l[1]);
  s[0]--;
  s[1]--;
  t[0]--;
  t[1]--;
  int ans = m + 1;
  for (int iter = 0; iter < (int)2; iter++) {
    swap(s[0], t[0]);
    for (int i = 0; i < (int)n; i++) {
      for (int j = 0; j < (int)n; j++) {
        int v[] = {d[s[0]][i] + d[i][j] + d[j][t[0]],
                   d[s[1]][i] + d[i][j] + d[j][t[1]]};
        if (v[0] <= l[0] && v[1] <= l[1]) ans = min(ans, v[0] + v[1] - d[i][j]);
      }
    }
  }
  if (d[s[0]][t[0]] <= l[0] && d[s[1]][t[1]] <= l[1])
    ans = min(ans, d[s[0]][t[0]] + d[s[1]][t[1]]);
  if (m < ans)
    printf("-1");
  else
    printf("%d", m - ans);
  return 0;
}
