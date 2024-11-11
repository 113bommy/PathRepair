#include <bits/stdc++.h>
using namespace std;
template <typename tp>
inline void read(tp &x) {
  x = 0;
  char c = getchar();
  int f = 0;
  for (; c < '0' || c > '9'; f |= c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar())
    ;
  if (f) x = -x;
}
const int N = 3e5 + 233;
int n, m, h[N], vis[N], sg[N], sum[N];
vector<int> G[N];
inline void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  vector<int> mark(G[u].size() + 1, 0);
  for (int v : G[u]) {
    dfs(v);
    if (sg[v] < mark.size()) mark[sg[v]] = true;
  }
  while (mark[sg[u]]) sg[u]++;
  sum[sg[u]] ^= h[u];
}
int main(void) {
  read(n);
  read(m);
  for (register int i = 1; i <= (n); i++) read(h[i]);
  for (register int i = 1; i <= (m); i++) {
    int x, y;
    read(x);
    read(y);
    G[x].push_back(y);
  }
  for (register int i = 1; i <= (n); i++)
    if (!vis[i]) dfs(i);
  for (int i = n; i >= 0; i--)
    if (sum[i]) {
      cout << "WIN\n";
      for (register int k = 1; k <= (n); k++)
        if (sg[k] == i && h[k] > (h[k] ^ sum[i])) {
          auto flip = [](int x) {
            h[x] ^= sum[sg[x]];
            sum[sg[x]] = 0;
          };
          flip(k);
          for (int v : G[k]) flip(v);
          break;
        }
      for (register int k = 1; k <= (n); k++) cout << h[k] << " \n"[k == n];
      return 0;
    }
  cout << "LOSE\n";
}
