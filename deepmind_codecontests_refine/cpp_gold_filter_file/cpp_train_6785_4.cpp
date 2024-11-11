#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 311;
const long long oo = 1e17;
long long cnt[MAXN], pre[MAXN], t, ret = oo, flag, m, n, g[MAXN][MAXN],
                                   ed[MAXN][MAXN];
void floyd() {
  for (long long k = 1; k <= m; k++) {
    for (long long i = 1; i <= m; i++)
      for (long long j = 1; j <= m; j++) {
        if (i == j) continue;
        ret = min(ret, g[i][j] + ed[i][k] + ed[k][j]);
      }
    for (long long i = 1; i <= m; i++)
      for (long long j = 1; j <= m; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= 201; i++)
    for (long long j = 1; j <= 201; j++) g[i][j] = ed[i][j] = oo;
  for (long long i = 1; i <= n; i++) {
    cin >> t;
    bitset<63> bs(t);
    long long new_vertex = -1, flag = -1;
    for (long long j = 0; j <= 63; j++) {
      if (bs[j]) {
        cnt[j] = cnt[j] + 1;
        if (cnt[j] == 3) {
          cout << 3;
          return 0;
        }
        flag = 1;
      }
    }
    if (flag == -1) continue;
    new_vertex = ++m;
    for (long long j = 0; j <= 63; j++) {
      if (bs[j]) {
        if (cnt[j] == 1) pre[j] = new_vertex;
        if (cnt[j] == 2) {
          int u = new_vertex;
          int v = pre[j];
          g[u][v] = g[v][u] = ed[u][v] = ed[v][u] = 1;
        }
      }
    }
  }
  floyd();
  if (ret == oo) {
    cout << -1;
    return 0;
  }
  cout << ret;
}
