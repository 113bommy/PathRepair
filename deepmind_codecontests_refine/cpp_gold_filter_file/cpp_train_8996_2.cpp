#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct point {
  long long x, y;
  int ind;
  int ma;
};
int n;
point a[MAXN];
vector<int> graph[MAXN];
int depth[MAXN];
int up[25][MAXN];
long long ccw(point O, point A, point B) {
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
void read_input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &a[i].x, &a[i].y);
    a[i].ind = i;
    a[i].ma = i;
  }
}
point hull[MAXN];
void make_tree() {
  int k = 0;
  hull[k++] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    while (k > 1 && ccw(hull[k - 2], hull[k - 1], a[i]) < 0) k--;
    if (a[i].y > hull[k - 1].y) {
      graph[hull[k - 1].ma].push_back(i);
    } else {
      graph[hull[k - 1].ind].push_back(i);
    }
    int mP = a[i].x;
    while (k > 0 && hull[k - 1].y == a[i].y) {
      a[i].ma = hull[k - 1].ma;
      k--;
    }
    hull[k++] = a[i];
  }
}
void dfs(int v, int timer, int p) {
  depth[v] = timer;
  up[0][v] = p;
  for (int i = 1; i < 25; i++) {
    up[i][v] = up[i - 1][up[i - 1][v]];
  }
  int z = graph[v].size();
  for (int i = 0; i < z; i++) {
    int to = graph[v][i];
    dfs(to, timer + 1, v);
  }
}
void solve() {
  int a, b, t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &a, &b);
    a--;
    b--;
    for (int z = 24; z >= 0; z--) {
      if (depth[a] - (1 << z) >= depth[b]) {
        a = up[z][a];
      }
      if (depth[b] - (1 << z) >= depth[a]) {
        b = up[z][b];
      }
    }
    for (int z = 24; z >= 0; z--) {
      if (up[z][a] != up[z][b]) {
        a = up[z][a];
        b = up[z][b];
      }
    }
    if (a != b) {
      a = up[0][a];
    }
    printf("%d ", a + 1);
  }
}
int main() {
  read_input();
  make_tree();
  dfs(n - 1, 1, n - 1);
  solve();
  return 0;
}
