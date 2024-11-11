#include <bits/stdc++.h>
using namespace std;
struct aho_corasick {
  static const int alpha = 26;
  vector<array<int, alpha>> go;
  vector<int> fail;
  vector<int> endpos;
  aho_corasick() { add_node(); }
  int add_string(const string &str) {
    int e = 0;
    for (char c : str) {
      if (!go[e][c - 'a']) {
        int nn = add_node();
        go[e][c - 'a'] = nn;
      }
      e = go[e][c - 'a'];
    }
    ++endpos[e];
    return e;
  }
  void build() {
    queue<int> que;
    for (int c = 0; c < alpha; ++c)
      if (go[0][c]) que.push(go[0][c]);
    for (; !que.empty(); que.pop()) {
      int e = que.front();
      int f = fail[e];
      for (int c = 0; c < alpha; ++c)
        if (!go[e][c])
          go[e][c] = go[f][c];
        else {
          fail[go[e][c]] = go[f][c];
          endpos[go[e][c]] += endpos[go[f][c]];
          que.push(go[e][c]);
        }
    }
  }

 private:
  int add_node() {
    int pos = go.size();
    go.emplace_back(array<int, alpha>());
    fail.emplace_back(0);
    endpos.emplace_back(0);
    return pos;
  }
};
template <typename T>
struct fenwick {
  int n;
  vector<T> f;
  fenwick(int n) : n(n), f(n + 1) {}
  T query(int b) {
    T ret = 0;
    for (; b; b -= b & -b) ret += f[b];
    return ret;
  }
  void update(int a, int b, T c) {
    for (; a <= n; a += a & -a) f[a] += c;
    for (++b; b <= n; b += b & -b) f[b] -= c;
  }
};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int q, k;
  cin >> q >> k;
  vector<int> p(k + 1);
  vector<string> s(k);
  aho_corasick ac;
  int u = 0;
  for (auto &i : s) cin >> i, p[++u] = ac.add_string(i);
  ac.build();
  int n = ac.go.size();
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) g[ac.fail[i]].push_back(i);
  int t = 0;
  vector<int> dt(n), ft(n);
  function<void(int)> dfs = [&](int x) {
    dt[x] = ++t;
    for (auto v : g[x]) dfs(v);
    ft[x] = t;
  };
  dfs(0);
  fenwick<long long> abi(n);
  vector<int> cur(k + 1, 1);
  for (string x; q--;) {
    cin >> x;
    char z = x[0];
    x = x.substr(1, x.length() - 1);
    if (z == '?') {
      long long ans = u = 0;
      for (auto c : x)
        u = ac.go[u][c - 'a'], ans += ac.endpos[u] + abi.query(dt[u]);
      cout << ans << "\n";
      continue;
    }
    int add = z == '+' ? 1 : -1;
    u = p[stoi(x)];
    if (add != cur[u]) cur[u] = add, abi.update(dt[u], ft[u], add);
  }
  return 0;
}
