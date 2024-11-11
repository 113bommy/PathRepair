#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char& s) {
  string res = "'";
  res += s;
  res += "'";
  return res;
}
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i) res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long long mod = 998244353;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long>> g(k);
  vector<vector<long long>> a(n);
  vector<vector<long long>> G(n);
  for (long long i = 0; i < n; i++) {
    long long m;
    cin >> m;
    for (long long j = 0; j < m; j++) {
      long long x;
      cin >> x;
      x--;
      a[i].push_back(x);
      g[x].push_back(i);
    }
  }
  long long usd = 0;
  for (long long i = 0; i < k; i++) {
    if ((long long)(g[i]).size() == 0)
      usd++;
    else {
      for (auto x : g[i]) {
        if (x != g[i][0]) {
          G[x].push_back(g[i][0]);
          G[g[i][0]].push_back(x);
        }
      }
    }
  }
  vector<long long> p(n, -1), ts;
  function<void(long long)> dfs = [&](long long v) {
    ts.push_back(v);
    for (auto x : G[v]) {
      if (p[x] == -1) {
        p[x] = v;
        dfs(x);
      }
    }
  };
  vector<long long> AB(5 * k, 0), pos(k);
  map<long long, long long> d;
  for (long long i = 0; i < n; i++) {
    if (p[i] != -1) continue;
    ts.clear();
    p[i] = n;
    dfs(i);
    vector<long long> C;
    for (auto v : ts) {
      for (auto x : a[v]) C.push_back(x);
    }
    sort((C).begin(), (C).end());
    C.resize(unique((C).begin(), (C).end()) - C.begin());
    long long ok = 1;
    for (auto v : ts) {
      auto A = a[v];
      sort((A).begin(), (A).end());
      for (long long i = 0; i < (long long)(A).size() - 1; i++)
        if (A[i] == A[i + 1]) ok = 0;
    }
    if (!ok) continue;
    long long st = 2 * k;
    for (auto x : a[ts[0]]) {
      AB[st] = x;
      pos[x] = st;
      st++;
    }
    for (auto v : ts) {
      if (v == ts[0]) continue;
      long long first = 0;
      for (long long j = 0; j < (long long)(a[v]).size(); j++) {
        if (pos[a[v][j]] != -1) {
          first = pos[a[v][j]] - j;
          break;
        }
      }
      for (long long j = 0; j < (long long)(a[v]).size(); j++) {
        if (first + j < 0 || first + j >= (long long)(AB).size()) {
          ok = 0;
          break;
        }
        if (pos[AB[first + j]] == first + j) {
          if (AB[first + j] != a[v][j]) ok = 0;
        } else {
          if (pos[a[v][j]] == -1) {
            AB[first + j] = a[v][j];
            pos[a[v][j]] = first + j;
          } else {
            ok = 0;
          }
        }
      }
      if (!ok) break;
    }
    if (!ok) {
      for (auto x : C) pos[x] = -1;
      continue;
    }
    long long mn = 1e18, mx = -1e18;
    for (auto x : C) {
      mn = min(mn, pos[x]);
      mx = max(mx, pos[x]);
    }
    d[mx - mn + 1]++;
    for (auto x : C) pos[x] = -1;
  }
  vector<long long> dp(m + 1);
  dp[0] = 1;
  for (long long i = 0; i < m; i++) {
    dp[i + 1] = (dp[i] * usd) % mod;
    for (auto [x, y] : d) {
      if (x <= i + 1) {
        dp[i + 1] = (dp[i + 1] + dp[i + 1 - x] * y) % mod;
      }
    }
  }
  cout << dp[m];
}
