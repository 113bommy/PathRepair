#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 200002;
const long long INF = 200000000000;
int n;
long long t[N_MAX];
int h[N_MAX];
vector<int> edges[N_MAX];
long long down[N_MAX], up[N_MAX];
long long auxu[N_MAX];
long long auxd[N_MAX];
void dfs(int u, int parent = -1) {
  if ((int)edges[u].size() == 1 && u != 1) {
    down[u] = up[u] = 0;
    return;
  }
  for (int v : edges[u])
    if (v != parent) dfs(v, u);
  int U = 0, D = 0, F = 0;
  long long sumud = 0;
  long long sumfu = 0;
  long long sumfd = 0;
  for (int v : edges[u])
    if (v != parent) {
      if (h[u] < h[v]) {
        sumud += down[v];
        D++;
      } else if (h[u] > h[v]) {
        sumud += up[v];
        U++;
      } else {
        sumfu += up[v];
        sumfd += down[v];
        F++;
        auxu[F] = down[v] - up[v];
        auxd[F] = up[v] - down[v];
      }
    }
  sort(auxu + 1, auxu + F + 1);
  sort(auxd + 1, auxd + F + 1);
  long long down1 = INF, down2 = INF;
  if (F + D >= 1) {
    down1 = -t[u] + sumfu + sumud;
    long long mi = INF;
    long long sum = 0;
    for (int k = 0; k <= F; k++) {
      if (D + k >= 1) mi = min(mi, sum - min(D + k - 1, U + F - k) * t[u]);
      sum += auxu[k + 1];
    }
    down1 += mi;
  }
  {
    down2 = sumfu + sumud;
    long long mi = INF;
    long long sum = 0;
    for (int k = 0; k <= F; k++) {
      mi = min(mi, sum - min(D + k, U + F - k) * t[u]);
      sum += auxu[k + 1];
    }
    down2 += mi;
  }
  if (u == 1)
    down[u] = down2;
  else
    down[u] = min(down1, down2);
  long long up1 = INF, up2 = INF;
  if (F + U >= 1) {
    up1 = -t[u] + sumfd + sumud;
    long long mi = INF;
    long long sum = 0;
    for (int k = 0; k <= F; k++) {
      if (U + k >= 1) mi = min(mi, sum - min(U + k - 1, D + F - k) * t[u]);
      sum += auxd[k + 1];
    }
    up1 += mi;
  }
  {
    up2 = sumfd + sumud;
    long long mi = INF;
    long long sum = 0;
    for (int k = 0; k <= F; k++) {
      mi = min(mi, sum - min(D + k, U + F - k) * t[u]);
      sum += auxd[k + 1];
    }
    up2 += mi;
  }
  if (u == 1)
    up[u] = up2;
  else
    up[u] = min(up1, up2);
  down[u] = min(INF, down[u]);
  up[u] = min(INF, up[u]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) cin >> h[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += (int)edges[i].size() * t[i];
  dfs(1);
  ans += min(up[1], down[1]);
  cout << ans << "\n";
  return 0;
}
