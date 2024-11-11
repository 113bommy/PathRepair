#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e5 + 5, LG = 30, inf = 1e18, mod = 1e9 + 7;
long long int t;
long long int n, m;
long long int h[M];
long long int a[M];
long long int qu[M];
vector<long long int> g[M];
long long int mark[M];
long long int au[M];
long long int ac[M];
void doo(long long int x, long long int t) {
  for (int i = n; i >= x; i--) {
    h[i] = min(h[i], h[i - x] + t);
  }
}
bool lucky(long long int x) {
  if (x == 0) return 0;
  while (x > 0) {
    if (x % 10 != 4 && x % 10 != 7) {
      return 0;
    }
    x /= 10;
  }
  return 1;
}
long long int dfs(long long int x) {
  long long int cnt = 1;
  mark[x] = 1;
  for (long long int y : g[x]) {
    if (!mark[y]) cnt += dfs(y);
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long int c = 0;
  for (int i = 0; i < n; i++) {
    if (!mark[i]) {
      a[c++] = dfs(i);
    }
  }
  sort(a, a + c);
  m = 0;
  au[0] = a[0];
  ac[0] = 1;
  for (int i = 1; i < c; i++) {
    if (a[i] == au[m]) {
      ac[m]++;
      continue;
    }
    au[++m] = a[i];
    ac[m] = 1;
  }
  for (int i = 0; i < n + 1; i++) {
    h[i] = inf;
  }
  h[0] = 0;
  m++;
  for (int i = 0; i < m; i++) {
    for (long long int z = 1; z < ac[i]; z *= 2) {
      doo(au[i] * z, z);
      ac[i] -= z;
    }
    doo(au[i] * ac[i], ac[i]);
  }
  long long int res = inf;
  for (int i = 0; i < n + 1; i++) {
    if (lucky(i)) res = min(res, h[i]);
  }
  cout << (res == inf ? -1 : res - 1);
}
