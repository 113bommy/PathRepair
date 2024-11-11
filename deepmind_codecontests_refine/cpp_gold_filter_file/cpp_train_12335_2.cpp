#include <bits/stdc++.h>
using namespace std;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const int MAXN = 3010;
int d[MAXN][MAXN];
int n, m;
int s1, t1, s2, t2, l1, l2;
vector<int> g[MAXN];
queue<int> q;
void BFS(int src) {
  for (int i = 0; i < n; i++) {
    d[src][i] = (int)1e9;
  }
  d[src][src] = 0;
  q.push(src);
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (typeof((g[top]).begin()) v = (g[top]).begin(); v != (g[top]).end();
         ++v) {
      if (d[src][*v] > d[src][top] + 1) {
        d[src][*v] = d[src][top] + 1;
        q.push(*v);
      }
    }
  }
}
int main() {
  int a, b;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  for (int i = 0; i < n; i++) {
    BFS(i);
  }
  scanf("%d", &s1);
  scanf("%d", &t1);
  scanf("%d", &l1);
  scanf("%d", &s2);
  scanf("%d", &t2);
  scanf("%d", &l2);
  s1 = s1 - 1;
  t1 = t1 - 1;
  s2 = s2 - 1;
  t2 = t2 - 1;
  int ans = -1;
  if (d[s1][t1] <= l1 && d[s2][t2] <= l2) {
    ans = ((ans) > (m - d[s1][t1] - d[s2][t2]) ? (ans)
                                               : (m - d[s1][t1] - d[s2][t2]));
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (d[s1][i] + d[i][j] + d[j][t1] <= l1 &&
          d[s2][i] + d[i][j] + d[j][t2] <= l2) {
        ans = ((ans) > (m - d[s1][i] - d[s2][i] - d[i][j] - d[j][t1] - d[j][t2])
                   ? (ans)
                   : (m - d[s1][i] - d[s2][i] - d[i][j] - d[j][t1] - d[j][t2]));
      }
      if (d[s1][i] + d[i][j] + d[j][t1] <= l1 &&
          d[t2][i] + d[i][j] + d[j][s2] <= l2) {
        ans = ((ans) > (m - d[s1][i] - d[i][j] - d[t2][i] - d[j][t1] - d[j][s2])
                   ? (ans)
                   : (m - d[s1][i] - d[i][j] - d[t2][i] - d[j][t1] - d[j][s2]));
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
