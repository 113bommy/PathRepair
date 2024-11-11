#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int res[1005], u[1005], vv[1005];
int w[1005];
int in[1005], out[1005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int i, x, y;
  for (i = 1; i <= n; i++) w[i] = 1000005;
  for (i = 0; i < m; i++) {
    int d;
    scanf("%d%d%d", &x, &y, &d);
    if (d < w[x]) w[x] = d;
    if (d < w[y]) w[y] = d;
    v[x].push_back(y);
    in[y]++;
    out[x]++;
  }
  int inn = 0;
  for (i = 1; i <= n; i++) {
    if (in[i] == 0 && out[i] == 1) {
      queue<int> q;
      int ma = 1000005;
      q.push(i);
      u[inn] = i;
      res[inn] = ma;
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vv[inn] = cur;
        if (w[cur] < ma) ma = w[cur];
        res[inn] = ma;
        if (v[cur].size()) q.push(v[cur][0]);
      }
      inn++;
    }
  }
  printf("%d\n", inn);
  for (i = 0; i < inn; i++) printf("%d %d %d\n", u[i], vv[i], res[i]);
  return 0;
}
