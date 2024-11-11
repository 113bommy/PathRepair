#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2010;
int g[N][N], n;
ll d[N];
bool st[N];
void dijkstra(int S) {
  memset(d, 0x3f, sizeof d);
  memset(st, 0, sizeof st);
  d[S] = 0;
  for (int i = 1; i <= n; i++) {
    d[i] = g[S][i];
    for (int j = 1; j <= n; j++) d[i] = min(d[i], g[i][j] * 2ll);
  }
  for (int i = 1; i <= n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!st[j] && (t == -1 || d[t] > d[j])) t = j;
    st[t] = 1;
    for (int j = 1; j <= n; j++) d[j] = min(d[j], d[t] + g[t][j]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  int S = 1, mn = 0x3f3f3f3f;
  memset(g, 0x3f, sizeof g);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      cin >> g[i][j];
      g[j][i] = g[i][j];
      if (mn > g[i][j]) mn = g[i][j], S = i;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) g[i][j] -= mn;
  dijkstra(S);
  for (int i = 1; i <= n; i++) cout << 1ll * (n - 1) * mn + d[i] << '\n';
}
