#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using bs = basic_string<int>;
const ll Mod = 1e9 + 7;
map<string, int> mp, m1;
unordered_map<int, int> g[8010];
bs v[1010];
vector<bs> v1;
vector<vector<bs>> now[20];
ll s[20], ans, vl[20];
int n, m, _, siz[20];
ll f[1010][8010];
string h4sh(int p, int f, vector<bs>& v) {
  vector<string> sn;
  for (int i : v[p])
    if (i != f) sn.push_back(h4sh(i, p, v));
  sort(sn.begin(), sn.end());
  string re = "(";
  for (auto& s : sn) re += s;
  return re + ")";
}
void dfs(int p, int fa = 0) {
  f[p][1] = 1;
  for (int i : v[p])
    if (i != fa) {
      dfs(i, p);
      for (int j = _; j; j--)
        for (auto& [x, y] : g[j]) (f[p][y] += f[i][x] * f[p][j]) %= Mod;
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x] += y, v[y] += x;
  }
  scanf("%d", &m);
  now[1].push_back({{}, {}});
  mp["()"] = _ = 1;
  for (int i = 1; i < m; i++)
    for (auto& v : now[i]) {
      auto w = v;
      for (int j = 1; j <= i; j++) {
        w = v;
        w.push_back({j});
        w[j] += i + 1;
        string vl = h4sh(1, 0, w);
        if (!mp.count(vl)) mp[vl] = ++_, now[i + 1].push_back(w);
      }
    }
  for (int x = 1; x < m; x++)
    for (auto& u : now[x])
      for (int y = 1; y + x <= m; y++)
        for (auto& v : now[y]) {
          auto w = u;
          for (int i = 1; i <= y; i++) {
            w.push_back({});
            for (int j : v[i]) w.back() += j + x;
          }
          w[1] += x + 1;
          w[x + 1] += 1;
          g[mp[h4sh(1, 0, u)]][mp[h4sh(1, 0, v)]] = mp[h4sh(1, 0, w)];
        }
  dfs(1);
  v1.resize(m + 1);
  for (int i = 1, x, y; i < m; i++)
    scanf("%d%d", &x, &y), v1[x] += y, v1[y] += x;
  for (int i = 1; i <= m; i++) {
    string vl = h4sh(i, 0, v1);
    if (!m1.count(vl)) {
      m1[vl] = 1;
      for (int j = 1; j <= n; j++) (ans += f[j][mp[vl]]) %= Mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
