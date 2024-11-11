#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const long long A1 = 23, B1 = 17, C1 = 233, D1 = 19, mod1 = 1e9 + 7;
const long long A2 = 233, B2 = 19, C2 = 29, D2 = 23, mod2 = 1e9 + 9;
map<pair<long long, long long>, pair<long long, long long> > mp;
vector<int> g[N];
int u[N], v[N];
pair<long long, long long> dfs(int u, int fa) {
  if (mp.find(pair<long long, long long>(u, fa)) != mp.end())
    return mp[pair<long long, long long>(u, fa)];
  vector<pair<long long, long long> > tmp;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == fa) continue;
    tmp.push_back(dfs(v, u));
  }
  sort(tmp.begin(), tmp.end());
  long long h1 = g[u].size(), h2 = g[u].size();
  for (int i = 0; i < tmp.size(); i++) {
    h1 = ((h1 * A1) + tmp[i].first) % mod1;
    h2 = ((h2 * A2) + tmp[i].second) % mod2;
  }
  (h1 *= D1) %= mod1;
  (h2 *= D2) %= mod2;
  return mp[pair<long long, long long>(u, fa)] =
             pair<long long, long long>(h1, h2);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u[i], &v[i]);
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
  }
  set<pair<long long, long long> > st;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() < 4) st.insert(dfs(i, 0));
  }
  cout << st.size() << endl;
}
