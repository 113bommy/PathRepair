#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
const int INF = 1000000000LL;
int n;
int a[N][N];
long long f[N][N];
long long minv[N], cnt[N];
vector<pair<int, int> > adj[N];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      f[i][j] = INF;
    }
    f[i][i] = 0;
  }
  int m;
  int u, v, l;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &u, &v, &l);
    --u, --v;
    adj[u].push_back(make_pair(v, l));
    adj[v].push_back(make_pair(u, l));
    f[u][v] = f[v][u] = min(f[u][v], (long long)l);
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  for (int j = 1; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      minv[i] = INF;
      cnt[i] = 1;
      for (__typeof(adj[i].begin()) it = adj[i].begin(); it != adj[i].end();
           ++it) {
        int v = it->first;
        int tmp = it->second + f[v][j];
        if (tmp < minv[i]) {
          minv[i] = tmp;
          cnt[i] = 1;
        } else if (tmp == minv[i]) {
          ++cnt[i];
        }
      }
    }
    for (int i = 0; i < j; ++i) {
      if (f[i][j] == INF) {
        a[i][j] = 0;
        continue;
      }
      int ret = 0;
      for (int k = 0; k < n; ++k) {
        if (f[i][j] - f[i][k] == minv[k]) {
          ret += cnt[k];
        }
      }
      a[i][j] = ret;
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      printf("%d ", a[i][j]);
    }
}
int main() {
  solve();
  return 0;
}
