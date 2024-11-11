#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, tot;
stack<int> S;
map<string, int> M;
string s[N], x, y;
vector<int> V[N], F[N];
pair<int, int> val[N], Val[N];
int dfn[N], sccno[N], dep, scc_cnt, vis[N];
template <class T>
void minimize(T& a, T b) {
  if (a > b) a = b;
}
int Tarjan(int u) {
  int lowu = dfn[u] = ++dep;
  S.push(u);
  for (int i = 0; i < V[u].size(); ++i) {
    int v = V[u][i];
    if (!dfn[v])
      lowu = min(lowu, Tarjan(v));
    else if (!sccno[v])
      lowu = min(lowu, dfn[v]);
  }
  if (lowu == dfn[u]) {
    ++scc_cnt;
    while (1) {
      int x = S.top();
      S.pop();
      sccno[x] = scc_cnt;
      if (x == u) break;
    }
  }
  return lowu;
}
void find_scc(int n) {
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) Tarjan(i);
}
void add(int u, int v) { V[u].push_back(v); }
void ctr_add(int u, int v) { F[u].push_back(v); }
void contract(int n) {
  for (int u = 1; u <= n; ++u) {
    if (Val[sccno[u]] == pair<int, int>(0, 0))
      Val[sccno[u]] = val[u];
    else
      minimize(Val[sccno[u]], val[u]);
    for (int i = 0; i < V[u].size(); ++i) {
      int v = V[u][i];
      if (sccno[u] != sccno[v]) {
        ctr_add(sccno[u], sccno[v]);
      }
    }
  }
}
void turn(string& s) {
  int sum = 0;
  for (int j = s.size() - 1; j >= 0; --j) {
    s[j] = tolower(s[j]);
    if (s[j] == 'r') ++sum;
  }
  if (M.count(s) == 0) {
    ++tot;
    val[tot] = pair<int, int>(sum, s.size());
    M[s] = tot;
  }
}
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < F[u].size(); ++i) {
    int v = F[u][i];
    if (!vis[v]) dfs(v);
    minimize(Val[u], Val[v]);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    turn(s[i]);
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    turn(x);
    turn(y);
    add(M[x], M[y]);
  }
  find_scc(tot);
  contract(tot);
  for (int i = 1; i <= scc_cnt; ++i) {
    if (!vis[i]) dfs(i);
  }
  int p = 0, q = 0;
  for (int i = 1; i <= n; ++i) {
    pair<int, int> t = Val[sccno[M[s[i]]]];
    p += t.first;
    q += t.second;
  }
  cout << p << " " << q << endl;
  return 0;
}
