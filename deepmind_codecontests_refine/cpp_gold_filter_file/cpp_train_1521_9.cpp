#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
long long n, x[maxn], y[maxn], r[maxn];
vector<int> e[maxn];
int par[maxn];
long long f[maxn][2][2];
static const double PI = acos(-1.0);
bool circle_contains(int i, int j) {
  long long dx = x[j] - x[i];
  long long dy = y[j] - y[i];
  return (dx * dx) + (dy * dy) <= (r[i] - r[j]) * (r[i] - r[j]);
}
void dfs(int v) {
  long long g[2][2] = {{0}};
  for (int u : e[v]) {
    dfs(u);
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= 1; j++) {
        g[i][j] += f[u][i][j];
      }
    }
  }
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      f[v][i][j] = max(g[i ^ 1][j] + r[v] * r[v] * (i == 0 ? +1 : -1),
                       g[i][j ^ 1] + r[v] * r[v] * (j == 0 ? +1 : -1));
    }
  }
}
int main() {
  cin >> n;
  memset(f, 0, sizeof f);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  memset(par, -1, sizeof par);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (r[j] > r[i] && circle_contains(i, j)) {
        if (par[i] == -1 || r[par[i]] > r[j]) par[i] = j;
      }
    }
    e[par[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (par[i] == -1) {
      dfs(i);
      ans += f[i][0][0];
    }
  }
  printf("%.8f", (double)ans * PI);
  return 0;
}
