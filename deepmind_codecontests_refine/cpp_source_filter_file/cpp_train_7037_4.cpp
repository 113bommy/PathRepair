#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
double mod2(int x) {
  while (x < 0) {
    x += 2;
  }
  while (x >= 2) {
    x -= 2;
  }
  return x;
}
int N;
vector<int> adj[MAXN];
map<int, int> eid[MAXN];
double tim[MAXN];
void dfs(int x, int p) {
  double t = mod2(tim[x] + 1.0);
  for (int y : adj[x]) {
    if (y == p) {
      continue;
    }
    t = tim[y] = mod2(t + 2.0 / adj[x].size());
    printf("1 %d ", eid[x][y]);
    if (t >= 1.0) {
      printf("%d %d %.10lf\n", y, x, t - 1.0);
    } else {
      printf("%d %d %.10lf\n", x, y, t);
    }
    dfs(y, x);
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
    eid[x][y] = eid[y][x] = i;
  }
  printf("%d\n", N - 1);
  dfs(1, 0);
}
