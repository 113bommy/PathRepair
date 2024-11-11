#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int S[5] = {0, 758, 19, 2606, 20020626};
pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
  return make_pair((a.first + b.first) % 998244353,
                   (a.second + b.second) % 1000000007);
}
pair<int, int> operator*(const pair<int, int>& a, const pair<int, int>& b) {
  return make_pair(1LL * a.first * b.first % 998244353,
                   1LL * a.second * b.second % 1000000007);
}
int n, m;
vector<int> G0[400005], G[400005];
int sid[400005];
int cor[400005];
void add_edge(int u, int v, vector<int> cur[]) {
  cur[u].push_back(v);
  cur[v].push_back(u);
}
int get_ver(char ch, int v) {
  if (ch == 'T')
    return v;
  else if (ch == 'R')
    return v + m;
  else if (ch == 'B')
    return 2 * m + n + 1 - v;
  else
    return 2 * (m + n) + 1 - v;
}
bool vis[400005];
vector<int> cyc[400005], cyc0[400005];
pair<pair<int, int>, int> hs[400005], hs0[400005];
void dfs(int v, vector<int> cg[], vector<int>& ret) {
  vis[v] = true;
  ret.push_back(v);
  for (int i = 0; i < (int)(cg[v].size()); i++) {
    int u = cg[v][i];
    if (!vis[u]) dfs(u, cg, ret);
  }
}
void gen_hash(int cv, vector<int> cg[], pair<pair<int, int>, int>& ret,
              vector<int> rcyc[]) {
  rcyc[cv].clear();
  dfs(cv, cg, rcyc[cv]);
  bool rev = false;
  pair<int, int> sum, t;
  ret.first = make_pair(-1, -1);
  for (int R = 0; R < (int)(2); R++) {
    sum = make_pair(0, 0);
    t = make_pair(1, 1);
    for (int i = 0; i < (int)(rcyc[cv].size()); i++) {
      sum = sum + t * make_pair(S[sid[rcyc[cv][i]]], S[sid[rcyc[cv][i]]]);
      t = t * make_pair(243, 1003);
    }
    for (int i = rcyc[cv].size() - 1; i >= 0; i--) {
      sum = sum * make_pair(243, 1003) +
            (make_pair(1, 1) + make_pair(998244352, 1000000006) * t) *
                make_pair(S[sid[rcyc[cv][i]]], S[sid[rcyc[cv][i]]]);
      if (sum > ret.first) {
        rev = R;
        ret = make_pair(sum, i);
      }
    }
    reverse(rcyc[cv].begin(), rcyc[cv].end());
  }
  if (rev) reverse(rcyc[cv].begin(), rcyc[cv].end());
  rotate(rcyc[cv].begin(), rcyc[cv].begin() + ret.second, rcyc[cv].end());
  ret.second = rcyc[cv][0];
  swap(rcyc[cv], rcyc[ret.second]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= (int)(2 * (m + n)); i++)
    sid[i] = (i > 0) + (i > m) + (i > m + n) + (i > 2 * m + n);
  for (int i = 1; i <= (int)(m); i++) {
    add_edge(i, 2 * m + n + 1 - i, G);
    add_edge(i, 2 * m + n + 1 - i, G0);
  }
  for (int i = 1; i <= (int)(n); i++) {
    add_edge(m + i, 2 * (m + n) + 1 - i, G);
    add_edge(m + i, 2 * (m + n) + 1 - i, G0);
  }
  int cnt = 0;
  for (int i = 0; i < (int)(m + n); i++) {
    char tu, tv;
    int pu, pv;
    cin >> tu >> tv >> pu >> pv;
    pu = get_ver(tu, pu);
    pv = get_ver(tv, pv);
    add_edge(pu, pv, G);
    if (sid[pu] + sid[pv] == 5) cnt++;
  }
  cnt /= 2;
  for (int i = 1; i <= (int)(cnt); i++) {
    add_edge(2 * (m + n) + 1 - i, i, G0);
    add_edge(m + n + 1 - i, m + n + i, G0);
  }
  for (int i = 1; i <= (int)(min(m, n) - cnt); i++) {
    add_edge(m + 1 - i, m + i, G0);
    add_edge(2 * m + n + 1 - i, 2 * m + n + i, G0);
  }
  if (n < m)
    for (int i = 1; i <= (int)(m - n); i++)
      add_edge(cnt + i, 2 * m + cnt + 1 - i, G0);
  else if (n > m)
    for (int i = 1; i <= (int)(n - m); i++)
      add_edge(2 * m - cnt + i, 2 * (m + n) - cnt + 1 - i, G0);
  cnt = 0;
  int cnt0 = 0;
  for (int i = 1; i <= (int)(2 * (m + n)); i++) vis[i] = false;
  for (int i = 1; i <= (int)(2 * (m + n)); i++)
    if (!vis[i]) gen_hash(i, G, hs[cnt++], cyc);
  for (int i = 1; i <= (int)(2 * (m + n)); i++) vis[i] = false;
  for (int i = 1; i <= (int)(2 * (m + n)); i++)
    if (!vis[i]) gen_hash(i, G0, hs0[cnt0++], cyc0);
  sort(hs, hs + cnt);
  sort(hs0, hs0 + cnt0);
  bool ok = cnt == cnt0;
  for (int i = 0; i < (int)(cnt); i++) ok &= hs[i].first == hs0[i].first;
  if (!ok) {
    cout << "No solution\n";
    return 0;
  }
  for (int i = 0; i < (int)(cnt); i++)
    for (int j = 0; j < (int)(cyc[hs[i].second].size()); j++)
      cor[cyc0[hs0[i].second][j]] = cyc[hs[i].second][j];
  for (int i = 1; i <= (int)(n); i++)
    cout << cor[m + i] - m << (i == n ? '\n' : ' ');
  for (int i = 1; i <= (int)(m); i++) cout << cor[i] << (i == m ? '\n' : ' ');
  return 0;
}
