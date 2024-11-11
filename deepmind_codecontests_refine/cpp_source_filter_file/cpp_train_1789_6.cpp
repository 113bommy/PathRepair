#include <bits/stdc++.h>
using namespace std;
long long ksm(long long a, long long b) {
  if (!b) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % 998244353;
  if (b & 1) ns = ns * a % 998244353;
  return ns;
}
vector<int> eg[2005];
int sz[2005];
void dfs(int a, int f) {
  sz[a] = 1;
  for (int i = 0; i < eg[a].size(); i++) {
    if (eg[a][i] == f) continue;
    dfs(eg[a][i], a);
    sz[a] += sz[eg[a][i]];
  }
}
int nd[2][2005], ncnt[2];
struct th {
  int id, sz;
  bool operator<(const th &u) const { return sz > u.sz; }
} p[2005];
int tp[2005];
void dfs(int a, int f, int tp, int num) {
  for (int i = 0; i < eg[a].size(); i++) {
    int v = eg[a][i];
    if (v == f) continue;
    int nx = nd[tp][ncnt[tp]++];
    cout << a << " " << v << " " << nx - num << endl;
    dfs(v, a, tp, nx);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    eg[u].push_back(v), eg[v].push_back(u);
  }
  int mn = 2005, mpl = 0;
  for (int i = 1; i <= n; i++) {
    dfs(i, 0);
    int nr = 0;
    for (int j = 0; j < eg[i].size(); j++) {
      nr = max(nr, sz[eg[i][j]]);
    }
    if (nr < mn) mn = nr, mpl = i;
  }
  dfs(mpl, 0);
  int s[2] = {0, 0};
  int ss = eg[mpl].size();
  for (int i = 0; i < ss; i++) {
    int v = eg[mpl][i];
    p[i].id = v, p[i].sz = sz[v];
  }
  sort(p, p + ss);
  for (int i = 0; i < ss; i++) {
    if (s[0] < s[1])
      tp[i] = 0, s[0] += p[i].sz;
    else
      tp[i] = 1, s[1] += p[i].sz;
  }
  for (int i = 0; i < s[0]; i++) nd[0][i] = i + 1;
  for (int i = 0; i < s[1]; i++) nd[1][i] = (i + 1) * s[0] + 1;
  for (int i = 0; i < ss; i++) {
    int nr = nd[tp[i]][ncnt[tp[i]]++];
    cout << mpl << " " << p[i].id << " " << nr << endl;
    dfs(p[i].id, mpl, tp[i], nr);
  }
  return 0;
}
