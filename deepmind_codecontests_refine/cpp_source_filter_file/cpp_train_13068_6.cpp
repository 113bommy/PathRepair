#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T& a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T& a, Args&... args) {
  cin >> a;
  __read(args...);
}
constexpr long long M7 = 1000000007ll;
constexpr long long M9 = 1000000009ll;
constexpr long long MFFT = 998244353ll;
template <class T>
void outv(T& a) {
  for (auto& x : a) cout << x << ' ';
}
mt19937 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
template <class T>
void random_shuffle(T s, T e) {
  shuffle(s, e, rnd);
};
static auto __super_speed__ = (ios_base::sync_with_stdio(0), cin.tie(0));
vector<pair<long long, long long>> e;
vector<long long> ans, was, t;
vector<vector<long long>> g;
vector<vector<long long>> cmp;
void dfs(long long v, long long r) {
  cmp.back().push_back(v);
  was[v] = 1;
  for (long long i : g[v]) {
    long long u = e[i].first;
    if (u == v) u = e[i].second;
    if (was[u]) continue;
    if ((t[i] ^ ans[v]) != r) ans[u] = 1;
    dfs(u, r);
  }
}
int32_t main() {
  long long n, m;
  __read(n, m);
  e = vector<pair<long long, long long>>(m);
  g = vector<vector<long long>>(n);
  t = vector<long long>(m);
  for (signed i = 0; i < (m); i++) {
    cin >> e[i].first >> e[i].second;
    string s;
    __read(s);
    t[i] = s == "R";
    e[i].first--, e[i].second--;
    g[e[i].first].push_back(i);
    g[e[i].second].push_back(i);
  }
  bool was_ans = false;
  vector<long long> res;
  for (long long r = 0; r < 2; ++r) {
    ans = was = vector<long long>(n);
    cmp.clear();
    for (long long v = 0; v < n; ++v) {
      if (!was[v]) {
        cmp.emplace_back();
        dfs(v, r);
      }
    }
    bool ok = true;
    for (long long i = 0; ok && i < m; ++i) {
      ok = (t[i] ^ ans[e[i].second] ^ ans[e[i].first]) == r;
    }
    if (ok) {
      vector<long long> z;
      for (auto& q : cmp) {
        long long cnt1 = 0;
        for (long long v : q) cnt1 += ans[v];
        for (long long v : q)
          if (ans[v] == (cnt1 * 2 < n)) z.push_back(v + 1);
      }
      if (!was_ans) res = z;
      if (z.size() < res.size()) res = z;
      was_ans = 1;
    }
  }
  if (was_ans) {
    cout << res.size() << '\n';
    outv(res);
  } else {
    cout << -1;
  }
  return 0;
}
