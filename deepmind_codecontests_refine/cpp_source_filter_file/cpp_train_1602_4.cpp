#include <bits/stdc++.h>
using namespace std;
long long n, q, t;
long long cent[305] = {0};
int sb[305], x[305], y[305];
bool vis[305], num[305];
long long f[100005];
int circle = 0, cnt = 0;
int dfs(int b, int m) {
  vis[b] = 1;
  ++cnt;
  t -= cent[b] * m;
  if (x[b] == 0) return cent[b];
  if (vis[x[b]])
    circle = 1;
  else
    cent[b] += dfs(x[b], m + 1);
  return cent[b];
}
int main() {
  int i, j, a, b, nc = 0;
  cin >> n >> q >> t;
  for (i = 1; i <= n; ++i) cin >> cent[i];
  for (j = 1; j <= q; ++j) {
    cin >> a >> b;
    x[b] = a;
    y[a] = 1;
    sb[j] = b;
    if (!num[a]) {
      num[a] = 1;
      nc++;
    }
    if (!num[b]) {
      num[b] = 1;
      nc++;
    }
  }
  for (i = 1; i <= q; ++i) {
    b = sb[i];
    if (!y[b]) {
      dfs(b, 0);
    }
  }
  if (circle || cnt < nc) {
    cout << "0" << endl;
    return 0;
  }
  f[0] = 1;
  for (i = 1; i <= n; ++i)
    for (j = cent[i]; j <= t; ++j) {
      f[j] += f[j - cent[i]];
      f[j] %= 1000000007;
    }
  if (t > 0)
    cout << f[t] << endl;
  else
    cout << "0" << endl;
  return 0;
}
