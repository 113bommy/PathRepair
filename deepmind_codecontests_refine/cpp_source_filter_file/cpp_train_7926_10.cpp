#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const double pi = 3.14159265358979;
const int maxn = 1e5 + 5;
const int maxm = 1e7 + 233;
const int mod = 998244353;
struct edge {
  int to, nxt, w;
} edge[maxn << 1];
int tot, head[maxn << 1];
void init() {
  tot = 0;
  memset(head, -1, sizeof head);
}
void addedge(int u, int v, int w) {
  edge[tot].to = v;
  edge[tot].w = w;
  edge[tot].nxt = head[u];
  head[u] = tot++;
  edge[tot].to = u;
  edge[tot].w = w;
  edge[tot].nxt = head[v];
  head[v] = tot++;
}
int col[maxn];
bool dfs(int u, int w) {
  col[u] = w;
  for (int i = head[u]; ~i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (col[v] != -1) {
      if (col[v] != (edge[i].w ^ w)) return false;
    } else if (!dfs(v, edge[i].w ^ w))
      return false;
  }
  return true;
}
long long pow_(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
char s[105];
int main() {
  cin >> (s + 1);
  int n = strlen(s + 1);
  reverse(s + 1, s + 1 + n);
  int ans = 0;
  for (int m = 1; m <= n - 1; ++m) {
    init();
    for (int i = 1; i <= n / 2; ++i) addedge(i, n - i + 1, 0);
    for (int i = 1; i <= m / 2; ++i) addedge(n + i, n + m - i + 1, 0);
    addedge(n + 1, n + n + 2, 0);
    addedge(n + 1, n + m + 1, 1);
    addedge(n + m, n + n + 2, 0);
    addedge(n + m, n + m + 1, 1);
    for (int i = 1; i <= m; ++i)
      if (s[i] == '1')
        addedge(i, n + i, 1);
      else if (s[i] == '0')
        addedge(i, n + i, 0);
    for (int i = m + 1; i <= n; ++i)
      if (s[i] == '1')
        addedge(i, n + m + 2, 0), addedge(i, n + m + 1, 1);
      else if (s[i] == '0')
        addedge(i, n + m + 1, 0), addedge(i, n + m + 2, 1);
    memset(col, -1, sizeof col);
    int c = 0;
    for (int i = 1; i <= n + m + 2; ++i) {
      if (col[i] == -1) {
        if (dfs(i, 0))
          ++c;
        else {
          c = 0;
          break;
        }
      }
    }
    if (c) ans = (ans + pow_(2, c - 1)) % mod;
  }
  cout << ans << '\n';
  return 0;
}
