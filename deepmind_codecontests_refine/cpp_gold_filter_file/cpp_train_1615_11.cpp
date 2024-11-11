#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)2e5 + 10;
const int INF = (int)0x3f3f3f3f;
int n, m, ans[MAXN], cnt[MAXN], len[MAXN], tot[MAXN];
vector<int> adj[MAXN], c[MAXN];
bool fre[MAXN], atk[MAXN];
void DFS(int u) {
  fre[u] = false;
  cnt[u] = atk[u];
  for (int i = 0; i < (int)adj[u].size(); ++i) {
    int v = adj[u][i];
    if (fre[v]) {
      DFS(v);
      if (cnt[v] > 0) {
        cnt[u] += cnt[v];
        tot[u] += tot[v] + 2;
        len[u] = max(len[u], len[v] + 1);
        c[u].push_back(v);
      }
    }
  }
}
void Cal(int u, int s, int d) {
  ans[u] = tot[u] + ((cnt[1] == cnt[u]) ? 0 : (s + 2)) - max(d, len[u]);
  vector<int> t;
  for (int i = 0; i < (int)c[u].size(); ++i) {
    int v = c[u][i];
    t.push_back(len[v]);
  }
  sort(t.begin(), t.end(), greater<int>());
  for (int i = 0; i < (int)c[u].size(); ++i) {
    int v = c[u][i];
    int ns = ((cnt[1] == cnt[u]) ? 0 : (s + 2)) + tot[u] - tot[v] - 2;
    int nd = (cnt[1] == cnt[v])
                 ? 0
                 : max(d + 1, ((t.size() == 1)
                                   ? 1
                                   : (((len[v] == t[0]) ? t[1] : t[0]) + 2)));
    Cal(v, ns, nd);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    atk[x] = true;
  }
  for (int i = 1; i <= n; ++i)
    if (atk[i] == false) ans[i] = INF;
  memset(fre, true, sizeof fre);
  DFS(1);
  Cal(1, 0, 0);
  int v = min_element(ans + 1, ans + 1 + n) - ans;
  printf("%d\n", v);
  printf("%d\n", ans[v]);
  return 0;
}
