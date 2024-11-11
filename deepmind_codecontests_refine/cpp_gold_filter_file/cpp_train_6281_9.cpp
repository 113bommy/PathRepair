#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, lg = 30;
long long n, u, v, w, q, par[N][lg + 10], h[N], cnt[N][lg + 10], ans, l;
long long ST[N], ip[N], t;
char c;
vector<pair<long long, long long> > G[N];
set<long long> st;
set<long long>::iterator it, it1, it2;
void dfs(long long x, long long p, long long d) {
  ST[x] = ++t;
  par[x][0] = p;
  cnt[x][0] = d;
  for (int i = 1; i <= lg; i++) {
    par[x][i] = par[par[x][i - 1]][i - 1];
    cnt[x][i] = cnt[x][i - 1] + cnt[par[x][i - 1]][i - 1];
  }
  for (auto i : G[x]) {
    if (i.first == p) continue;
    h[i.first] = h[x] + 1;
    dfs(i.first, x, i.second);
  }
}
long long get_par(long long x, long long y) {
  for (int i = 0; i <= lg; i++)
    if ((y >> i) & 1) x = par[x][i];
  return x;
}
long long get_par_cnt(long long x, long long y) {
  long long res = 0;
  for (int i = 0; i <= lg; i++)
    if ((y >> i) & 1) {
      res += cnt[x][i];
      x = par[x][i];
    }
  return res;
}
long long lca(long long x, long long y) {
  if (h[x] > h[y]) swap(x, y);
  y = get_par(y, h[y] - h[x]);
  if (x == y) return x;
  for (int i = lg; i >= 0; i--) {
    if (par[x][i] != par[y][i]) {
      x = par[x][i];
      y = par[y][i];
    }
  }
  return par[x][0];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i != n - 1; i++) {
    cin >> u >> v >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  dfs(1, 0, 0);
  cin >> q;
  for (int i = 1; i <= n; i++) ip[ST[i]] = i;
  for (int i = 0; i != q; i++) {
    cin >> c;
    if (c == '+') {
      u = 0;
      v = 0;
      w = 0;
      cin >> u;
      u = ST[u];
      st.insert(u);
      it = st.find(u);
      if (it == st.begin())
        it1 = st.end();
      else
        it1 = it;
      it1--;
      it2 = it;
      it2++;
      if (it2 == st.end()) it2 = st.begin();
      w = ip[(*it2)];
      u = ip[(*it1)];
      v = ip[(*it)];
      if (u != 0 && w != 0) l = lca(u, w);
      ans -= get_par_cnt(u, h[u] - h[l]);
      ans -= get_par_cnt(w, h[w] - h[l]);
      if (u != 0) l = lca(u, v);
      ans += get_par_cnt(u, h[u] - h[l]);
      ans += get_par_cnt(v, h[v] - h[l]);
      if (w != 0) l = lca(v, w);
      ans += get_par_cnt(v, h[v] - h[l]);
      ans += get_par_cnt(w, h[w] - h[l]);
    } else if (c == '?')
      cout << ans / 2 << endl;
    else {
      u = 0;
      v = 0;
      w = 0;
      cin >> u;
      u = ST[u];
      it = st.find(u);
      if (it == st.begin())
        it1 = st.end();
      else
        it1 = it;
      it1--;
      it2 = it;
      it2++;
      if (it2 == st.end()) it2 = st.begin();
      w = ip[(*it2)];
      u = ip[(*it1)];
      v = ip[(*it)];
      if (u != 0 && w != 0) l = lca(u, w);
      ans += get_par_cnt(u, h[u] - h[l]);
      ans += get_par_cnt(w, h[w] - h[l]);
      if (u != 0) l = lca(u, v);
      ans -= get_par_cnt(u, h[u] - h[l]);
      ans -= get_par_cnt(v, h[v] - h[l]);
      if (w != 0) l = lca(v, w);
      ans -= get_par_cnt(v, h[v] - h[l]);
      ans -= get_par_cnt(w, h[w] - h[l]);
      st.erase(ST[v]);
    }
  }
}
