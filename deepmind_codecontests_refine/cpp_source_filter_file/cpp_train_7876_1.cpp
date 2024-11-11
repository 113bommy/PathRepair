#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n, m, c;
int h[N], ne[N], e[N], idx;
int low[N], dfn[N], timestamp;
int din[N], scc_cnt, id[N];
int stk[N], top;
bool in_stk[N];
void add(int a, int b) { ne[idx] = h[a], e[idx] = b, h[a] = idx++; }
void tarjan(int u) {
  low[u] = dfn[u] = ++timestamp;
  stk[++top] = u, in_stk[u] = true;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!dfn[j]) {
      tarjan(j);
      low[u] = min(low[u], low[j]);
    } else if (in_stk[j])
      low[u] = min(low[u], dfn[j]);
  }
  if (dfn[u] == low[u]) {
    ++scc_cnt;
    int y;
    do {
      y = stk[top--];
      in_stk[y] = false;
      id[y] = scc_cnt;
    } while (y != u);
  }
}
int main() {
  memset(h, -1, sizeof(h));
  cin >> n >> m >> c;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= n; i++)
    for (int j = h[i]; j != -1; j = ne[j]) {
      int k = e[j];
      int a = id[i], b = id[k];
      if (a != b) din[b]++;
    }
  int ans = 0;
  for (int i = 1; i <= scc_cnt; i++)
    if (!din[i]) ans++;
  if (din[c] == 0) ans--;
  cout << ans << endl;
  return 0;
}
