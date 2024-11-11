#include <bits/stdc++.h>
using namespace std;
int INF = int(1e7);
long long int MAX = (1LL << 32LL) - 1LL;
long long int MOD = int(1e9) + 7;
vector<int> g[(int)(1e5 + 5)];
int qs[(int)(1e5 + 5)], qr[(int)(1e5 + 5)], q[(int)(1e5 + 5)],
    deg[(int)(1e5 + 5)];
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> qs[i] >> qr[i];
  }
  int l = 0, r = m + 1, mid;
  while (r - l > 1) {
    mid = (r + l) >> 1;
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      deg[i] = 0;
    }
    for (int i = 0; i < mid; i++) {
      g[qs[i]].push_back(qr[i]);
      deg[qr[i]]++;
    }
    int t = 0, x = 0;
    for (int i = 1; i <= n; i++)
      if (!deg[i]) q[t++] = i;
    while (x < t) {
      int v = q[x++];
      for (int u : g[v]) {
        deg[u]--;
        if (!deg[u]) q[t++] = u;
      }
    }
    bool has = false, ok = true;
    for (int i = 0; i < t - 1; i++) {
      int v = q[i];
      int u = q[i + 1];
      has = false;
      for (int x : g[v]) {
        if (x == u) {
          has = true;
          break;
        }
      }
      if (!has) {
        ok = false;
        break;
      }
    }
    if (ok)
      r = mid;
    else
      l = mid + 1;
  }
  if (l > m) l = -1;
  cout << l << endl;
  return 0;
}
