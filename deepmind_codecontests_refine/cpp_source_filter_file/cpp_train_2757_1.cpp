#include <bits/stdc++.h>
using namespace std;
int n, a[210], b[210], cap[210][210], flow[210][210], nflow[210], pre[210],
    dead[210], f, df, ans[110][110];
vector<int> v[210];
void insert(int uu, int vv, int c) {
  v[uu].push_back(vv);
  v[vv].push_back(uu);
  cap[uu][vv] = max(cap[uu][vv], c);
}
int bfs() {
  for (int i = 1; i <= 2 * n + 1; i++) dead[i] = 0, pre[i] = -1, nflow[i] = 0;
  queue<int> q;
  q.push(0);
  dead[0] = 1;
  nflow[0] = 2e9;
  while (q.size()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < v[now].size(); i++)
      if (!dead[v[now][i]] && cap[now][v[now][i]] - flow[now][v[now][i]] > 0) {
        dead[v[now][i]] = 1;
        pre[v[now][i]] = now;
        nflow[v[now][i]] =
            min(nflow[now], cap[now][v[now][i]] - flow[now][v[now][i]]);
        q.push(v[now][i]);
        if (v[now][i] == 2 * n + 1) return nflow[2 * n + 1];
      }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 0; i < m; i++) {
    int uu, vv;
    cin >> uu >> vv;
    insert(uu, n + vv, 2000000000);
    insert(vv, n + uu, 2000000000);
  }
  for (int i = 1; i <= n; i++) insert(0, i, a[i]);
  for (int i = 1; i <= n; i++) insert(i, n + i, a[i]);
  for (int i = 1; i <= n; i++) insert(n + i, 2 * n + 1, b[i]);
  pre[0] = -1;
  for (; df = bfs(); f += df)
    for (int now = 2 * n + 1; pre[now] != -1; now = pre[now]) {
      flow[pre[now]][now] += df;
      flow[now][pre[now]] -= df;
    }
  if (f == accumulate(a + 1, a + n + 1, 0) &&
      f == accumulate(b + 1, b + n + 1, 0)) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) cout << ans[i][n + j] << " \n"[j == n];
  } else
    cout << "NO\n";
}
