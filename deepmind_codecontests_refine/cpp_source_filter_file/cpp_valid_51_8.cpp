#include <bits/stdc++.h>
using namespace std;
[[maybe_unused]] constexpr int INF = (numeric_limits<int>::max()) / 2;
[[maybe_unused]] constexpr long long INFLL =
    (numeric_limits<long long>::max()) / 2;
[[maybe_unused]] constexpr __int128 INF128 = numeric_limits<__int128>::max();
template <class T>
istream &operator>>(istream &is, vector<T> &a) {
  for (auto &i : a) is >> i;
  return is;
}
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
int getrand(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }
long double getrand(long double l, long double r) {
  return uniform_real_distribution<long double>(l, r)(gen);
}
vector<vector<int>> w;
vector<int> gg;
long long check(vector<pair<int, int>> t) {
  long long ans = 0;
  for (auto [i, j] : t) ans += w[i][j];
  return ans;
}
struct dsu {
  vector<int> p, s;
  dsu(){};
  dsu(int n) {
    p.resize(n);
    s.resize(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  int get(int v) {
    if (p[v] == v) return v;
    return p[v] = get(p[v]);
  }
  void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (s[a] < s[b]) swap(a, b);
    s[a] += s[b];
    p[b] = a;
  }
};
int n;
void get(vector<pair<int, int>> &t, vector<int> &d) {
  int i = getrand(0, n - 2);
  int govno = 1;
  while (govno++ < 228) {
    if (govno % 20 == 0) i = getrand(0, n - 2);
    auto dd = d;
    dsu tmp(n);
    for (int j = 0; j < n - 1; ++j) {
      if (j != i) tmp.unite(t[j].first, t[j].second);
    }
    int v = getrand(0, n - 1), u = getrand(0, n - 1);
    while (tmp.get(u) == tmp.get(v)) u = getrand(0, n - 1);
    --dd[t[i].first];
    --dd[t[i].second];
    ++dd[v];
    ++dd[u];
    bool check = true;
    for (int ggi = 0; ggi < gg.size(); ++ggi) {
      if (dd[ggi] > gg[ggi]) check = false;
    }
    if (check) {
      t.erase(t.begin() + i);
      t.push_back({u, v});
      d = dd;
      return;
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int k;
  cin >> n >> k;
  gg.resize(k);
  cin >> gg;
  w.resize(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cin >> w[i][j];
      w[j][i] = w[i][j];
    }
  }
  if (n < 8) {
    long long ans = INF;
    int m = n * (n - 1) / 2;
    vector<pair<int, int>> govno;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) govno.push_back({i, j});
    for (int mask = 0; mask < (1 << m); ++mask) {
      if (__builtin_popcount(mask) != n - 1) continue;
      dsu tmp(n);
      long long cur = 0;
      vector<int> d(n, 0);
      for (int i = 0; i < m; ++i)
        if ((mask >> i) & 1) {
          tmp.unite(govno[i].first, govno[i].second);
          ++d[govno[i].first];
          ++d[govno[i].second];
          cur += w[govno[i].first][govno[i].second];
        }
      bool check = true;
      for (int i = 0; i < n; ++i)
        if (tmp.get(0) != tmp.get(i)) check = false;
      for (int i = 0; i < k; ++i)
        if (d[i] > gg[i]) check = false;
      if (check) ans = min(ans, cur);
    }
    cout << ans;
    return 0;
  }
  int timera = 0;
  long long ans = INF;
  while (timera++ < 100) {
    long double temp = 1;
    int timerb = 0;
    vector<pair<int, int>> t;
    vector<int> d(n, 0);
    if (count(gg.begin(), gg.end(), 1) > 2) {
      dsu tmp(n);
      vector<int> zhopa(n);
      iota(zhopa.begin(), zhopa.end(), 0);
      int root = getrand(k, n - 1);
      for (int i = 0; i < k; ++i) {
        if (gg[i] == 1) {
          tmp.unite(i, root);
          zhopa.erase(find(zhopa.begin(), zhopa.end(), i));
          ++d[root];
          ++d[i];
          t.push_back({i, root});
        }
      }
      while (t.size() < n - 1) {
        int u = zhopa[getrand(0, zhopa.size() - 1)],
            v = zhopa[getrand(0, zhopa.size() - 1)];
        while (1) {
          while (tmp.get(u) == tmp.get(v)) v = getrand(0, n - 1);
          if (u < k && d[u] + 1 > gg[u] || v < k && d[v] + 1 > gg[v]) {
            u = getrand(0, n - 1);
            continue;
          }
          ++d[u];
          if (u < k && d[u] == gg[u])
            zhopa.erase(find(zhopa.begin(), zhopa.end(), u));
          ++d[v];
          if (v < k && d[v] == gg[v])
            zhopa.erase(find(zhopa.begin(), zhopa.end(), v));
          tmp.unite(u, v);
          t.push_back({u, v});
          break;
        }
      }
    } else {
      int leaf1 = 0, leaf2 = n - 1;
      if (count(gg.begin(), gg.end(), 1) >= 1)
        leaf1 = find(gg.begin(), gg.end(), 1) - gg.begin();
      if (count(gg.begin(), gg.end(), 1) == 2) {
        for (int i = k - 1; i >= 0; --i)
          if (gg[i] == 1) {
            leaf2 = i;
            break;
          }
      }
      for (int i = 0; i + 1 < n; ++i) t.push_back({i, i + 1});
      int govno1 = 0, govno2 = n - 1;
      for (int i = 0; i + 1 < n; ++i) {
        if (t[i].first == govno1) t[i].first = leaf1;
        if (t[i].second == govno2) t[i].second = leaf2;
        if (t[i].first == leaf1) t[i].first = govno1;
        if (t[i].second == leaf2) t[i].second = govno2;
      }
      for (auto [i, j] : t) {
        ++d[i];
        ++d[j];
      }
    }
    ans = min(ans, check(t));
    while (timerb++ < 10000) {
      temp *= 0.99;
      auto oldt = t;
      auto oldd = d;
      get(t, d);
      long long res = check(oldt) - check(t);
      if (exp((long double)res / temp) >
          getrand((long double)0.0, (long double)1.0)) {
        ans = min(ans, check(t));
        continue;
      }
      t = oldt;
      d = oldd;
    }
  }
  cout << ans;
  cout << "\n";
}
