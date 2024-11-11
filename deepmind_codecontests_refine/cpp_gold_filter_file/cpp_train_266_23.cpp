#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int n, k, l, a[200], d[20000], dist[20][20], dp[10 + (1 << 20)];
bool f[20000], b[20000];
vector<int> all[20000], bs;
queue<int> q;
void bfs(int x) {
  q.push(x);
  d[x] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < all[v].size(); i++)
      if (d[all[v][i]] == inf) d[all[v][i]] = d[v] + 1, q.push(all[v][i]);
  }
}
int main() {
  scanf("%d%d%d", &n, &k, &l);
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    f[x] = true;
  }
  for (int i = 0; i <= n; i++) {
    b[i] = (f[i] ^ f[i + 1]);
    if (b[i]) bs.push_back(i);
  }
  for (int i = 0; i < l; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j <= n - a[i]; j++)
      all[j].push_back(j + a[i]), all[j + a[i]].push_back(j);
  }
  for (int i = 0; i < bs.size(); i++) {
    fill(d, d + n + 1, inf);
    bfs(bs[i]);
    for (int j = 0; j < bs.size(); j++) {
      dist[i][j] = d[bs[j]];
    }
  }
  int m = bs.size();
  fill(dp, dp + (1 << m), inf);
  dp[0] = 0;
  for (int i = 1; i < (1 << m); i++) {
    int fir = -1;
    for (int j = 0; j < m; j++) {
      if ((i >> j) & 1) {
        if (fir == -1)
          fir = j;
        else
          dp[i] = min(dp[i], dp[i ^ ((1 << fir) | (1 << j))] + dist[fir][j]);
      }
    }
  }
  if (dp[(1 << m) - 1] >= inf) dp[(1 << m) - 1] = -1;
  printf("%d\n", dp[(1 << m) - 1]);
}
