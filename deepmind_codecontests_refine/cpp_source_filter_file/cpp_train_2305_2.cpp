#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
void qread(int &x) {
  int neg = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = 10 * x + c - '0', c = getchar();
  x *= neg;
}
const int maxn = 300005;
const int mlog = 20;
const int mod = 998244353;
int n, k;
int dep[maxn], par[maxn][mlog], a[maxn], dp[maxn][2], tmp[2];
vector<int> edge[maxn], pos[maxn];
bool used[maxn];
void prework(int x, int p, int d) {
  par[x][0] = p;
  dep[x] = d;
  for (int(j) = 1; (j) <= mlog - 1; j++) par[x][j] = par[par[x][j - 1]][j - 1];
  for (int(i) = 0; (i) < edge[x].size(); i++) {
    int y = edge[x][i];
    if (y == p) continue;
    prework(y, x, d + 1);
  }
}
void work(int x, int p) {
  dp[x][a[x] > 0] = 1;
  for (int(i) = 0; (i) < edge[x].size(); i++) {
    int y = edge[x][i];
    if (y == p) continue;
    work(y, x);
    for (int(f1) = 0; (f1) < 2; f1++)
      if (dp[x][f1])
        for (int(f2) = 0; (f2) < 2; f2++)
          if (dp[y][f2]) {
            int cur = 1LL * dp[x][f1] * dp[y][f2] % mod;
            if (!a[x]) {
              if (!f1 || !f2) tmp[f1 | f2] = (tmp[f1 | f2] + cur) % mod;
              if (f2) tmp[f1] = (tmp[f1] + cur) % mod;
            } else {
              assert(f1);
              if (f2)
                tmp[f1] = (tmp[f1] + cur) % mod;
              else if (!a[y])
                tmp[f1] = (tmp[f1] + cur) % mod;
            }
          }
    for (int(f) = 0; (f) < 2; f++) dp[x][f] = tmp[f], tmp[f] = 0;
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int diff = dep[x] - dep[y];
  for (int i = mlog - 1; i >= 0; i--)
    if (x & (1 << i)) x = par[x][i];
  if (x == y) return x;
  for (int i = mlog - 1; i >= 0; i--) {
    if (par[x][i] != par[y][i]) {
      x = par[x][i];
      y = par[y][i];
    }
  }
  return par[x][0];
}
int main() {
  qread(n);
  qread(k);
  for (int(i) = 1; (i) <= n; i++) qread(a[i]), pos[a[i]].push_back(i);
  for (int(i) = 1; (i) <= n - 1; i++) {
    int u, v;
    qread(u);
    qread(v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  prework(1, 0, 0);
  for (int(i) = 1; (i) <= k; i++) {
    vector<int> proc;
    int x = pos[i][0];
    used[x] = true;
    proc.push_back(x);
    for (int(j) = 1; (j) <= pos[i].size() - 1; j++) {
      int y = pos[i][j], z = lca(x, y);
      used[y] = true;
      proc.push_back(y);
      while (x != z && !used[par[x][0]]) {
        x = par[x][0];
        if (a[x] > 0 && a[x] != i) {
          printf("%d\n", 0);
          return 0;
        }
        a[x] = i;
        used[x] = true;
        proc.push_back(x);
      }
      while (y != z && !used[par[y][0]]) {
        y = par[y][0];
        if (a[y] > 0 && a[y] != i) {
          printf("%d\n", 0);
          return 0;
        }
        a[y] = i;
        used[y] = true;
        proc.push_back(y);
      }
      x = z;
    }
    for (int(j) = 0; (j) < proc.size(); j++) used[proc[j]] = false;
  }
  work(1, 0);
  printf("%d\n", dp[1][1]);
  return 0;
}
