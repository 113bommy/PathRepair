#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, p[maxn][20], level[maxn], v1 = 2, v2 = 3, diameter = 2;
int curV = 4;
void preprocess() {
  for (int i = 1; i <= 1e6; i++) {
    for (int j = 1; 1 << j < n; j++) {
      p[i][j] = -1;
    }
  }
  p[2][0] = p[3][0] = p[4][0] = level[2] = level[3] = level[4] = 1;
}
void add(int node, int cur) {
  p[cur][0] = node;
  level[cur] = level[node] + 1;
  for (int j = 1; 1 << j < curV; j++) {
    if (p[cur][j - 1] != -1) {
      p[cur][j] = p[p[cur][j - 1]][j - 1];
    }
  }
}
int lca(int x, int y) {
  if (level[x] < level[y]) swap(x, y);
  int log;
  for (log = 1; 1 << log <= level[x]; log++)
    ;
  log--;
  for (int i = log; i >= 0; i--) {
    if (level[x] - (1 << i) >= level[y]) {
      x = p[x][i];
    }
  }
  if (x == y) return x;
  for (int i = log; i >= 0; i--) {
    if (p[x][i] != -1 && (p[x][i] != p[y][i])) {
      x = p[x][i], y = p[y][i];
    }
  }
  return p[x][0];
}
int dist(int a, int b) { return level[a] + level[b] - (2 * level[lca(a, b)]); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  preprocess();
  while (n--) {
    int v;
    cin >> v;
    add(v, ++curV);
    add(v, ++curV);
    int d1 = dist(curV, v1);
    int d2 = dist(curV, v2);
    if (d1 >= diameter && d1 >= d2) {
      diameter = d1;
      v2 = curV;
    }
    if (d2 >= diameter && d2 >= d1) {
      diameter = d2;
      v1 = curV;
    }
    printf("%d\n", diameter);
  }
  return 0;
}
