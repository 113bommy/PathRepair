#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10, SEGM = 524288;
pair<int, int> zkw[2 * SEGM];
int a[MAXN], b[MAXN], ans[MAXN], n;
bool vis[MAXN];
vector<int> ord;
pair<int, int> Query(int l, int r) {
  pair<int, int> res = make_pair(0, 0);
  for (l += SEGM, r += SEGM; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    res = max(res, max(zkw[l], zkw[r]));
  return res;
}
void Modify(int p, pair<int, int> nw) {
  zkw[p += SEGM] = nw;
  for (; p > 1; p >>= 1) zkw[p >> 1] = max(zkw[p], zkw[p ^ 1]);
}
static int dfsd = 0;
void dfs(int u) {
  dfsd++;
  vis[u] = true;
  Modify(u, make_pair(0, u));
  if (b[u] < n) {
    pair<int, int> nx = Query(b[u], b[u]);
    if (nx.first > 0) dfs(nx.second);
  }
  while (true) {
    pair<int, int> nx = Query(1, a[u] - 1);
    if (nx.first > u)
      dfs(nx.second);
    else
      break;
  }
  ord.push_back(u);
  dfsd--;
}
int main() {
  scanf("%d", &n);
  fill_n(b, n + 1, n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] != -1) {
      b[a[i]] = i;
    } else
      a[i] = n + 1;
  }
  for (int i = 1; i <= n; i++) zkw[i + SEGM] = make_pair(b[i], i);
  for (int i = SEGM - 1; i; i--) zkw[i] = max(zkw[i << 1], zkw[i << 1 | 1]);
  for (int u = 1; u <= n; u++)
    if (!vis[u]) dfs(u);
  for (int i = 0; i < ord.size(); i++) ans[ord[i]] = i + 1;
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
  return 0;
}
