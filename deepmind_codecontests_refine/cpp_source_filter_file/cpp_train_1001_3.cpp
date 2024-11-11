#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[100005];
pair<int, int> bruh[100005];
vector<int> e[100005];
int d[100005];
int p[100005];
vector<int> cyc;
void gc(int bt, int tp) {
  int mn = bt, mx = bt;
  int cur = bt;
  cyc.push_back(bt);
  while (cur != tp) {
    cur = p[cur];
    cyc.push_back(cur);
  }
}
bool dfs(int cn) {
  for (auto nn : e[cn]) {
    if (d[nn] == -1) {
      d[nn] = d[cn] + 1;
      p[nn] = cn;
      if (dfs(nn)) return true;
    } else if (nn != p[cn] && d[nn] < d[cn]) {
      if ((d[nn] - d[cn]) % 2 == 0) {
        gc(cn, nn);
        return true;
      }
    }
  }
  return false;
}
map<pair<int, int>, long long> res;
void ae(int u, int v, long long ch) {
  if (u > v) swap(u, v);
  res[{u, v}] += ch;
  c[u] += ch;
  c[v] += ch;
}
bool vis[100005];
void dfs2(int cn, int p) {
  vis[cn] = true;
  for (auto nn : e[cn]) {
    if (vis[nn]) continue;
    dfs2(nn, cn);
  }
  if (p != 0) {
    ae(cn, p, -c[cn]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = (1); i <= (signed)(n); i++) {
    int x;
    cin >> x;
    c[i] = -x;
  }
  for (int i = 0; i < (signed)(m); i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    e[u].push_back(v);
    e[v].push_back(u);
    bruh[i] = {u, v};
  }
  memset(d, -1, sizeof d);
  d[1] = 0;
  bool hmm = dfs(1);
  int rt;
  if (hmm) {
    rt = cyc[0];
  } else {
    rt = 1;
  }
  dfs2(rt, 0);
  if (!hmm) {
    if (c[rt] != 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < (signed)(m); i++) {
        cout << res[bruh[i]] << "\n";
      }
    }
  } else {
    long long d = -c[rt] / 2;
    for (int i = 0; i < (signed)(cyc.size() - 1); i++) {
      ae(cyc[i], cyc[i + 1], d);
      d = -d;
    }
    ae(cyc[0], cyc[cyc.size() - 1], d);
    cout << "YES\n";
    for (int i = 0; i < (signed)(m); i++) {
      cout << res[bruh[i]] << "\n";
    }
  }
  return 0;
}
