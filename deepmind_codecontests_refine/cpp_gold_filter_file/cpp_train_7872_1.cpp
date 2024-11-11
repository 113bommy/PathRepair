#include <bits/stdc++.h>
using namespace std;
long long n, m, q, t;
long long a, b, tmp;
long long vis[300000 + 5];
vector<long long> path[300000 + 5];
stack<long long> cir;
long long p[300000 + 5], pre[300000 + 5];
void DFS(long long now, long long par) {
  vis[now] = ++tmp;
  cir.push(now);
  for (long long i = 0; i < path[now].size(); i++) {
    if (path[now][i] == par) continue;
    if (!vis[path[now][i]])
      DFS(path[now][i], now);
    else if (vis[path[now][i]] < vis[now]) {
      long long mmin = now, mmax = now;
      while (cir.size()) {
        t = cir.top();
        cir.pop();
        mmin = min(mmin, t);
        mmax = max(mmax, t);
        if (t == path[now][i]) break;
      }
      p[mmin] = mmax - 1;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    cin >> a >> b;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  for (long long i = 1; i <= n; i++) p[i] = n;
  for (long long i = 1; i <= n; i++) {
    if (!vis[i]) DFS(i, 0);
  }
  for (long long i = n; i >= 1; i--) {
    tmp = min(tmp, p[i]);
    p[i] = tmp;
  }
  for (long long i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + p[i] - i + 1;
  }
  cin >> q;
  for (long long i = 0; i < q; i++) {
    cin >> a >> b;
    tmp = upper_bound(p + a, p + b + 1, b) - p;
    cout << (b - tmp + 2) * (b - tmp + 1) / 2 + pre[tmp - 1] - pre[a - 1]
         << endl;
  }
  return 0;
}
