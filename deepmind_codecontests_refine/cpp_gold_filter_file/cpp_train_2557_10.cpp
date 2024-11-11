#include <bits/stdc++.h>
using namespace std;
int f[1000010];
vector<int> G[1000010];
int col[1000010];
int tot, s, cnt;
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
void dfs(int x, int color) {
  for (auto to : G[x])
    if (!col[to]) col[to] = color, f[color]++, dfs(to, color);
}
int n = read(), m = read(), k = read();
int main() {
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (!col[i]) cnt++, col[i] = ++tot, f[tot]++, dfs(i, tot);
  for (int i = 1; i <= tot; i++) f[i] = min(f[i], k), s += f[i];
  int ans = max(0, cnt - s / 2 - 1);
  if (k == 1)
    cout << max(0, cnt - 2) << endl;
  else
    cout << ans << endl;
  return 0;
}
