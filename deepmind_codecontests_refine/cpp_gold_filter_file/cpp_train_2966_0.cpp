#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
int n, m, K, f[maxn][maxn], tot[maxn], fr[maxn], x[maxn], y[maxn];
bool vis[maxn];
queue<int> q;
int main() {
  cin >> n >> m >> K;
  for (int i = 0; i < (1 << n); i++) {
    int x = i, sum = 0;
    for (; x; x >>= 1) {
      if (x & 1) {
        ++tot[i];
        if (tot[i] == 1) fr[i] = (1 << sum);
      }
      ++sum;
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x[i], &y[i]);
    --x[i];
    --y[i];
    x[i] = 1 << x[i];
    y[i] = 1 << y[i];
    int now = x[i] + y[i];
    f[now][now] = 1;
    vis[now] = 1;
    q.push(now);
  }
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    for (int j = 0; j < (1 << n); j++)
      for (int i = 0; i < m; i++) {
        if ((k & x[i]) && (k & y[i])) continue;
        if (!(k & x[i]) && !(k & y[i])) continue;
        int to = k | x[i] | y[i];
        int son = j, NEW;
        if (son & x[i])
          son = son - x[i] + y[i], NEW = y[i];
        else if (son & y[i])
          son = son - y[i] + x[i], NEW = x[i];
        else if (k & x[i])
          son += y[i], NEW = y[i];
        else
          son += x[i], NEW = x[i];
        if (!vis[to]) q.push(to), vis[to] = 1;
        if (fr[son] == NEW) f[to][son] += f[k][j];
      }
  }
  n = 1 << n;
  --n;
  int ans = 0;
  for (int i = 0; i <= n; i++)
    if (tot[i] == K) ans += f[n][i];
  cout << ans;
  return 0;
}
