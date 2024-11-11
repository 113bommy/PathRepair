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
vector<ll> tree(_size << 1), cnt(_size << 1);
vector<ll> pos;
vector<ll> x;
vector<ll> price;
vector<ll> if_now;
vector<ll> to_pay;
vector<vector<pii>> gr;
vector<ll> ans;
void upd(int v, ll cn) {
  ll c = cn;
  cn *= price[v];
  v = pos[v];
  v += _size;
  cnt[v] += c;
  tree[v] += cn;
  v >>= 1;
  while (v) {
    tree[v] += cn;
    cnt[v] += c;
    v >>= 1;
  }
}
int find_f(ll t, int v = 1) {
  if (v >= _size) return v - _size;
  if (tree[v << 1] >= t)
    return find_f(t, v << 1);
  else
    return find_f(t - tree[v << 1], v << 1 | 1);
}
ll get_cnt(ll rr, int v = 1, int l = 0, int r = _size) {
  if (r <= rr) return cnt[v];
  if (l >= rr) return 0;
  return get_cnt(rr, v << 1, l, (r + l) >> 1) +
         get_cnt(rr, v << 1 | 1, (r + l) >> 1, r);
}
ll get_pay(ll rr, int v = 1, int l = 0, int r = _size) {
  if (r <= rr) return tree[v];
  if (l >= rr) return 0;
  return get_pay(rr, v << 1, l, (r + l) >> 1) +
         get_pay(rr, v << 1 | 1, (r + l) >> 1, r);
}
ll get_now(ll t) {
  0;
  0;
  0;
  0;
  int ind = find_f(t);
  0;
  ll ans = get_cnt(ind);
  0;
  t -= get_pay(ind);
  0;
  if (ind == _size || cnt[ind + _size] == 0 || to_pay[ind] == 0) {
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
