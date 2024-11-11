#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 200, lg = 17;
vector<pair<int, int> > adj[maxn];
set<pair<int, int> > restored;
int mark[maxn], par[maxn][lg + 1], h[maxn], st[maxn], en[maxn];
long long par_w[maxn][lg + 1];
int tim = 0, n, q, needto;
long long ans = 0;
void input() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
}
void dfs(int v) {
  mark[v] = 1;
  st[v] = tim;
  tim++;
  for (auto o : adj[v]) {
    int u = o.first, w = o.second;
    if (!mark[u]) {
      h[u] = h[v] + 1;
      par[u][0] = v;
      par_w[u][0] = w;
      dfs(u);
    }
  }
  en[v] = tim;
  tim++;
}
void set_par() {
  for (int f = 1; f < lg; f++) {
    for (int i = 0; i < n; i++) {
      par[i][f] = par[par[i][f - 1]][f - 1];
      par_w[i][f] = par_w[i][f - 1] + par_w[par[i][f - 1]][f - 1];
    }
  }
}
pair<int, long long> lc(int u, int v) {
  if (u == v) return {v, 0};
  if (st[u] <= st[v] and en[v] <= en[u]) return {u, 0};
  for (int f = lg - 1; f > -1; f--) {
    if (st[par[u][f]] >= st[v] or en[v] >= en[par[u][f]] or f == 0) {
      pair<int, long long> p = lc(par[u][f], v);
      pair<int, long long> pt = {p.first, p.second + par_w[u][f]};
      return (pt);
    }
  }
  cout << "i don f***ed up" << endl;
}
pair<int, long long> lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  needto = v;
  return lc(u, v);
}
long long calc_tot(int a, int b) {
  long long ans = 0;
  pair<int, long long> p = lca(a, b);
  int z = p.first;
  pair<int, long long> p1 = lca(z, needto);
  ans += p.second;
  ans += p1.second;
  return ans;
}
void add_to_r() {
  int t;
  cin >> t;
  t--;
  auto a = restored.upper_bound({st[t], t});
  if (restored.size() == 0) {
    restored.insert({st[t], t});
    ans = 0;
    return;
  }
  if (a == restored.begin()) {
    auto b = restored.end();
    b--;
    ans = ans + calc_tot(t, (*a).second) + calc_tot(t, ((*b).second)) -
          calc_tot((*a).second, (*b).second);
    restored.insert({st[t], t});
    return;
  }
  if (a == restored.end()) {
    auto b = restored.begin();
    a--;
    ans = ans + calc_tot(t, (*a).second) + calc_tot(t, ((*b).second)) -
          calc_tot((*a).second, (*b).second);
    restored.insert({st[t], t});
    return;
  }
  auto b = a;
  b--;
  ans = ans + calc_tot(t, (*a).second) + calc_tot(t, ((*b).second)) -
        calc_tot((*a).second, (*b).second);
  restored.insert({st[t], t});
  return;
}
void remove_from_r() {
  int t;
  cin >> t;
  t--;
  auto a = restored.find({st[t], t});
  restored.erase(a);
  a = restored.upper_bound({st[t], t});
  if (restored.size() == 0) {
    ans = 0;
    return;
  }
  if (a == restored.begin()) {
    auto b = restored.end();
    b--;
    ans = ans - calc_tot(t, (*a).second) - calc_tot(t, ((*b).second)) +
          calc_tot((*a).second, (*b).second);
    return;
  }
  if (a == restored.end()) {
    auto b = restored.begin();
    a--;
    ans = ans - calc_tot(t, (*a).second) - calc_tot(t, ((*b).second)) +
          calc_tot((*a).second, (*b).second);
    return;
  }
  auto b = a;
  b--;
  ans = ans - calc_tot(t, (*a).second) - calc_tot(t, ((*b).second)) +
        calc_tot((*a).second, (*b).second);
  return;
}
long long answer_q() {
  if (!restored.size()) return 0;
  auto a = restored.begin(), b = a;
  b++;
  long long ans = 0;
  for (int i = 0; i < restored.size() - 1; i++) {
    ans += calc_tot((*a).second, ((*b).second));
    a++;
    b++;
  }
  a = restored.begin();
  b--;
  ans += calc_tot((*a).second, ((*b).second));
  return ans;
}
void query() {
  cin >> q;
  for (int i = 0; i < q; i++) {
    char c;
    cin >> c;
    if (c == '?')
      cout << ans / 2 << '\n';
    else {
      if (c == '+')
        add_to_r();
      else
        remove_from_r();
    }
  }
}
void test() {
  while (1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cout << calc_tot(a, b) << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  dfs(0);
  set_par();
  query();
}
