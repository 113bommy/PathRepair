#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using dd = double;
using ldd = long double;
using si = short int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int _size = 1 << 17;
vector<ll> tree(_size), cnt(_size);
vector<ll> pos;
vector<ll> x;
vector<ll> price;
vector<ll> if_now;
vector<ll> to_pay;
vector<vector<pii>> gr;
vector<ll> ans;
void upd_fen(int l, ll d, vector<ll>& tree) {
  for (; l < tree.size(); l |= l + 1) tree[l] += d;
}
void upd(int v, ll cn) {
  ll c = cn;
  cn *= price[v];
  v = pos[v];
  upd_fen(v, cn, tree);
  upd_fen(v, c, cnt);
}
int find_f(ll t) {
  int ans = -1;
  for (int i = 16; i >= 0; --i) {
    if (ans + (1 << i) < tree.size() && tree[ans + (1 << i)] <= t) {
      ans += (1 << i);
      t -= tree[ans];
    }
  }
  return ans;
}
ll get_fen(int r, vector<ll>& tree) {
  ll ans = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) ans += tree[r];
  return ans;
}
ll get_cnt(ll rr) { return get_fen(rr, cnt); }
ll get_pay(ll rr) { return get_fen(rr, tree); }
ll get_now(ll t) {
  0;
  int ind = find_f(t);
  0;
  ll ans = get_cnt(ind);
  t -= get_pay(ind);
  0;
  0;
  ++ind;
  0;
  if (ind >= to_pay.size() || to_pay[ind] == 0) {
    return ans;
  }
  return ans + t / to_pay[ind];
}
void dfs(int v, ll t) {
  0;
  upd(v, x[v]);
  if_now[v] = get_now(t);
  for (pii i : gr[v]) {
    t -= i.second * 2;
    if (t >= 0) dfs(i.first, t);
    t += i.second * 2;
  }
  upd(v, -x[v]);
}
void afs(int v) {
  ans[v] = if_now[v];
  vector<ll> ch;
  for (pii i : gr[v]) {
    afs(i.first);
    ch.push_back(ans[i.first]);
  }
  sort((ch).begin(), (ch).end());
  reverse((ch).begin(), (ch).end());
  ans[v] = max(ans[v], (ch.size() >= 2 ? ch[1] : 0));
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n;
  ll t;
  cin >> n >> t;
  x.resize(n);
  pos.resize(n);
  price.resize(n);
  if_now.resize(n);
  gr.resize(n);
  to_pay.resize(n);
  ans.resize(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  map<int, int> ttt;
  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> price[i];
    ttt[price[i]] = 0;
  }
  for (auto& i : ttt) {
    i.second = s;
    to_pay[s] = i.first;
    ++s;
  }
  0;
  for (int i = 0; i < n; ++i) pos[i] = ttt[price[i]];
  0;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    gr[a - 1].push_back({i + 1, b});
  }
  0;
  dfs(0, t);
  0;
  afs(0);
  0;
  for (pii i : gr[0]) {
    ans[0] = max(ans[0], ans[i.first]);
  }
  cout << ans[0];
}
