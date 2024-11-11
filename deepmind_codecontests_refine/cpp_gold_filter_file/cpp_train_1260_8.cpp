#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int arr = 2e5 + 10;
const int ar = 2e3 + 10;
const long double pi = acos(-1);
const long double eps = 1e-10;
const long long md = 1e9 + 7;
long long p1[arr];
long long p2[arr];
unordered_map<long long, int> hashes[101];
long long get_hash(pair<int, int> a) {
  return a.first * 1256336ll + a.second ^ 12453624ll;
}
void add_string(const string& s, int val) {
  long long h1 = 0;
  long long h2 = 0;
  for (int i = 0; i < (int)(s.size()); i++) {
    h1 = (h1 + 1ll * (s[i] - 'a' + 1) * p1[i] % (long long)(1e9 + 7)) %
         (long long)(1e9 + 7);
    h2 = (h2 + 1ll * (s[i] - 'a' + 1) * p2[i] % (long long)(1e9 + 9)) %
         (long long)(1e9 + 9);
    if (hashes[i + 1].count(get_hash({h1, h2}))) {
      hashes[i + 1][get_hash({h1, h2})] += val;
    }
  }
}
int get_cnt(const string& s) {
  long long h1 = 0;
  long long h2 = 0;
  for (int i = 0; i < (int)(s.size()); i++) {
    h1 = (h1 + 1ll * (s[i] - 'a' + 1) * p1[i] % (long long)(1e9 + 7)) %
         (long long)(1e9 + 7);
    h2 = (h2 + 1ll * (s[i] - 'a' + 1) * p2[i] % (long long)(1e9 + 9)) %
         (long long)(1e9 + 9);
  }
  return hashes[(int)(s.size())][get_hash({h1, h2})];
}
vector<pair<int, bool>> rem_req[arr];
int ans[arr];
string sss[arr];
void process(pair<int, bool> req) {
  if (req.second) {
    reverse(sss[abs(req.first)].begin(), sss[abs(req.first)].end());
  }
  if (req.first < 0) {
    ans[-req.first] -= get_cnt(sss[-req.first]);
  } else {
    ans[req.first] += get_cnt(sss[req.first]);
  }
  if (req.second) {
    reverse(sss[abs(req.first)].begin(), sss[abs(req.first)].end());
  }
}
vector<pair<int, char>> reb[arr];
int pred[arr][20];
char char_up[arr];
int d[arr];
void dfs(int now, int pred) {
  ::pred[now][0] = pred;
  for (int i = 1; i < 20; i++) {
    ::pred[now][i] = ::pred[::pred[now][i - 1]][i - 1];
  }
  for (auto wh : reb[now]) {
    if (wh.first != pred) {
      d[wh.first] = d[now] + 1;
      dfs(wh.first, now);
      char_up[wh.first] = wh.second;
    }
  }
}
void dfs2(int u, int pred) {
  string cur;
  cur.clear();
  int uu = u;
  while ((int)(cur.size()) < 100 && uu != 1) {
    cur += char_up[uu];
    uu = ::pred[uu][0];
  }
  add_string(cur, +1);
  for (auto q : rem_req[u]) {
    process(q);
  }
  for (auto wh : reb[u]) {
    if (wh.first != pred) {
      dfs2(wh.first, u);
    }
  }
  add_string(cur, -1);
}
int lca(int u, int v) {
  if (d[u] > d[v]) {
    swap(u, v);
  }
  for (int i = 19; i >= 0; i--) {
    if (d[pred[v][i]] >= d[u]) {
      v = pred[v][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = 19; i >= 0; i--) {
    if (pred[u][i] != pred[v][i]) {
      u = pred[u][i];
      v = pred[v][i];
    }
  }
  return pred[u][0];
}
int get_kth(int u, int k) {
  for (int i = 0; i < 20; i++) {
    if (k & (1ll << i)) {
      u = pred[u][i];
    }
  }
  return u;
}
int z[arr];
void build_z(const string& s) {
  for (int i = 1, l = 0, r = 0; i < (int)(s.size()); i++) {
    z[i] = 0;
    if (i <= r) {
      z[i] = min(z[i - l], r - i + 1);
    }
    while (i + z[i] < (int)(s.size()) && s[i + z[i]] == s[z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      r = i + z[i] - 1;
      l = i;
    }
  }
}
int get_naive(const string& s, const string& t) {
  string T = s + "#" + t;
  build_z(T);
  int res = 0;
  for (int i = 0; i + (int)(s.size()) - 1 < (int)(T.size()); i++) {
    res += (z[i] >= (int)(s.size()));
  }
  return res;
}
void do_req(int u, int v, const string& s, int id) {
  int l = lca(u, v);
  if (d[u] - d[l] > (int)(s.size())) {
    rem_req[u].push_back({id, 0});
    u = get_kth(u, d[u] - d[l] - (int)(s.size()));
    rem_req[u].push_back({-id, 0});
  }
  if (d[v] - d[l] > (int)(s.size())) {
    rem_req[v].push_back({id, 1});
    v = get_kth(v, d[v] - d[l] - (int)(s.size()));
    rem_req[v].push_back({-id, 1});
  }
  string t1 = "";
  string t2 = "";
  while (u != l) {
    t1 += char_up[u];
    u = pred[u][0];
  }
  while (v != l) {
    t2 += char_up[v];
    v = pred[v][0];
  }
  reverse(t2.begin(), t2.end());
  ans[id] += get_naive(s, t1 + t2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  p1[0] = 1;
  for (int i = 1; i < arr; i++) {
    p1[i] = p1[i - 1] * 31 % (long long)(1e9 + 7);
  }
  p2[0] = 1;
  for (int i = 1; i < arr; i++) {
    p2[i] = p2[i - 1] * 31 % (long long)(1e9 + 9);
  }
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    reb[u].push_back({v, c});
    reb[v].push_back({u, c});
  }
  dfs(1, 1);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    get_cnt(s);
    reverse(s.begin(), s.end());
    get_cnt(s);
    reverse(s.begin(), s.end());
    sss[i] = s;
    do_req(u, v, s, i);
  }
  dfs2(1, 1);
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << "\n";
  }
}
