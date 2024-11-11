#include <bits/stdc++.h>
using namespace std;
map<int, int> adj1, adj2;
int v1, v2, sum1, sum2, di;
int N, p[300011][20], dpth[300011];
int elevate(int a, int d) {
  for (int i = 19; i >= 0; i--)
    if (d & (1 << i)) a = p[a][i];
  return a;
}
int lca(int a, int b) {
  if (dpth[a] > dpth[b]) swap(a, b);
  b = elevate(b, dpth[b] - dpth[a]);
  if (a == b) return a;
  for (int i = 19; i >= 0; i--)
    if (p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
  return p[a][0];
}
int dx(int a, int b) {
  int c = lca(a, b);
  if (a == b) return a;
  if (c != a) return p[a][0];
  return elevate(b, dpth[b] - dpth[a] - 1);
}
int dist(int a, int b) {
  int c = lca(a, b);
  return dpth[a] + dpth[b] - 2 * dpth[c];
}
int main() {
  if (fopen("data.in", "r")) freopen("data.in", "r", stdin);
  scanf("%d", &N);
  p[1][0] = dpth[1] = 1;
  for (int i = 2; i <= N + 1; i++) {
    scanf("%d", &p[i][0]);
    dpth[i] = dpth[p[i][0]] + 1;
  }
  for (int x = 1; x < 20; x++)
    for (int i = 1; i <= N + 1; i++) p[i][x] = p[p[i][x - 1]][x - 1];
  v1 = 1, v2 = -1, di = 0;
  sum1 = 1, sum2 = 0, adj1[1] = 1;
  for (int i = 2; i <= N + 1; i++) {
    if (v2 == -1) {
      int d = dist(v1, i);
      int v = dx(v1, i);
      if (d == di)
        adj1[v]++, sum1++;
      else if (d > di) {
        if (v == p[v1][0]) {
          v2 = v;
          sum1 -= adj1[v];
          adj1[v] = 0;
          adj2[dx(v2, i)] = 1;
          sum2 = 1;
        } else {
          v2 = v1;
          v1 = v;
          swap(adj1, adj2);
          swap(sum1, sum2);
          sum2 -= adj2[v];
          adj2[v] = 0;
          adj1[dx(v1, i)] = 1;
          sum1 = 1;
        }
      }
    } else {
      if (lca(v1, i) == v1) {
        int d = dist(v1, i);
        int v = dx(v1, i);
        if (d == di)
          adj1[v]++, sum1++;
        else if (d > di) {
          di++;
          adj1.clear();
          adj2.clear();
          adj1[v] = 1;
          sum1 = 1 + sum2;
          adj1[v2] = sum2;
          sum2 = 0, v2 = -1;
        }
      } else {
        int d = dist(v2, i);
        int v = dx(v2, i);
        if (d == di)
          adj2[v]++, sum2++;
        else if (d > di) {
          di++;
          swap(v1, v2);
          swap(adj1, adj2);
          swap(sum2, sum2);
          adj1.clear();
          adj2.clear();
          adj1[v] = 1;
          sum1 = 1 + sum2;
          adj1[v2] = sum2;
          sum2 = 0, v2 = -1;
        }
      }
    }
    printf("%d\n", sum1 + sum2);
  }
  return 0;
}
