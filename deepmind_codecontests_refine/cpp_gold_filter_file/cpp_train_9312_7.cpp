#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
vector<int> G[MAXN];
int l[MAXN], r[MAXN], eN;
inline int other(int e, int u) { return (l[e] == u ? r[e] : l[e]); }
stack<int> s;
int comp[MAXN], ind[MAXN], indN;
bool active[MAXN];
void tarjan(int u) {
  comp[u] = ind[u] = indN++;
  s.push(u);
  active[u] = true;
  for (int i = 0; i < G[u].size(); i++) {
    int v = r[G[u][i]];
    if (ind[v] == -1) {
      tarjan(v);
      comp[u] = min(comp[u], comp[v]);
    } else if (active[v])
      comp[u] = min(comp[u], ind[v]);
  }
  if (comp[u] == ind[u])
    while (true) {
      int v = s.top();
      s.pop();
      active[v] = false;
      comp[v] = ind[u];
      if (v == u) break;
    }
}
int p[MAXN], toval[MAXN], tN;
int found(int x) {
  int ind = lower_bound(toval, toval + tN, x) - toval;
  if (ind == tN || toval[ind] != x)
    return -1;
  else
    return ind;
}
inline int tr(int x) { return 2 * x; }
inline int fs(int x) { return 2 * x + 1; }
inline void add(int u, int v) {
  l[eN] = u;
  r[eN] = v;
  G[u].push_back(eN);
  eN++;
}
vector<int> H[MAXN];
bool vis[MAXN];
int ord[MAXN], oN, in[MAXN];
void topol(int u) {
  vis[u] = true;
  for (int i = 0; i < H[u].size(); i++) {
    int v = H[u][i];
    if (!vis[v]) topol(v);
  }
  ord[oN++] = u;
}
int ans[MAXN], id[MAXN];
pair<int, int> tmp[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  memset(ind, -1, sizeof ind);
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    toval[tN++] = p[i];
  }
  sort(toval, toval + tN);
  tN = unique(toval, toval + tN) - toval;
  for (int i = 0; i < n; i++) {
    int x = found(a - toval[i]), y = found(b - toval[i]);
    if (x != -1) {
      add(tr(i), tr(x));
      add(fs(i), fs(x));
    } else
      add(tr(i), fs(i));
    if (y != -1) {
      add(fs(i), fs(y));
      add(tr(i), tr(y));
    } else
      add(fs(i), tr(i));
  }
  for (int i = 0; i < tN * 2; i++)
    if (ind[i] == -1 && in[i] == 0) tarjan(i);
  for (int i = 0; i < tN; i++)
    if (comp[fs(i)] == comp[tr(i)]) {
      cout << "NO";
      return 0;
    }
  for (int i = 0; i < eN; i++) {
    int u = comp[l[i]], v = comp[r[i]];
    if (u != v) {
      H[u].push_back(v);
      in[v]++;
    }
  }
  memset(ans, -1, sizeof ans);
  for (int i = 0; i < tN * 2; i++)
    if (!vis[i] && in[i] == 0) topol(i);
  for (int i = 0; i < tN * 2; i++) id[ord[i]] = i;
  for (int i = 0; i < tN * 2; i++) tmp[i] = pair<int, int>(ord[comp[i]], i);
  sort(tmp, tmp + tN * 2);
  for (int i = 0; i < tN * 2; i++) {
    int u = tmp[i].second;
    if (ans[u / 2] == -1) ans[u / 2] = u % 2;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << ans[found(p[i])] << " ";
}
