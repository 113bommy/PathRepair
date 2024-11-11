#include <bits/stdc++.h>
using namespace std;
const int MAXN = 62;
const int MOD = 1000000007;
int n, a[MAXN], C[MAXN][MAXN], T[MAXN];
bool visited[MAXN];
int64_t f[1 << 17][MAXN];
vector<int> inf, sup, cc_inf, cc_sup;
vector<int> g[MAXN];
void readInput() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
}
void init() {
  for (int i = 1; i <= n; ++i) {
    bool isSup = false;
    for (int j = 1; j <= n; ++j) {
      if (i != j && a[i] % a[j] == 0) isSup = true;
    }
    if (isSup)
      sup.push_back(a[i]);
    else
      inf.push_back(a[i]);
  }
  for (auto u : sup) {
    for (auto v : sup) {
      bool ok = false;
      for (auto w : inf) ok = ok || (u % w == 0 && v % w == 0);
      if (ok && u != v) g[u].push_back(v);
    }
  }
  for (int i = 0; i <= n; ++i) C[i][i] = C[i][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
}
void visit(int u) {
  cc_sup.push_back(u);
  visited[u] = true;
  for (auto v : g[u]) {
    if (!visited[v]) visit(v);
  }
}
int64_t dp(int mask, int t) {
  if (t == cc_sup.size()) return 1;
  if (f[mask][t] > -1) return f[mask][t];
  int nPawn = 0;
  for (auto u : cc_sup) {
    if ((T[u] & mask) > 0 && (T[u] | mask) == mask) {
      ++nPawn;
    }
  }
  int64_t res = 0;
  if (nPawn > t) res = dp(mask, t + 1) * (nPawn - t) % MOD;
  for (auto u : cc_sup) {
    if ((T[u] & mask) > 0 && (T[u] | mask) > mask) {
      int newMask = (mask | T[u]);
      res = (res + dp(newMask, t + 1)) % MOD;
    }
  }
  return f[mask][t] = res;
}
void solve() {
  int64_t res = 1;
  vector<int> p, sz;
  {
    cerr << "inf"
         << " = ";
    for (int _ = 0; _ < inf.size(); ++_) cerr << inf[_] << ' ';
    cerr << '\n';
  };
  {
    cerr << "sup"
         << " = ";
    for (int _ = 0; _ < sup.size(); ++_) cerr << sup[_] << ' ';
    cerr << '\n';
  };
  for (auto u : sup) {
    if (!visited[u]) {
      cc_sup.clear();
      visit(u);
      memset(T, 0, sizeof(T));
      for (auto v : inf) {
        bool ok = false;
        for (auto w : cc_sup) ok = ok || (w % v == 0);
        if (ok) {
          for (auto w : cc_sup) {
            if (w % v == 0) T[w] |= (1 << cc_inf.size());
          }
          cc_inf.push_back(v);
        }
      }
      for (int mask = 0; mask < (1 << cc_inf.size()); ++mask) {
        for (int t = 0; t <= cc_sup.size(); ++t) {
          f[mask][t] = -1;
        }
      }
      int s = 0;
      for (auto v : cc_sup) {
        s = (s + dp(T[v], 1)) % MOD;
      }
      p.push_back(s);
      sz.push_back(cc_sup.size() - 1);
    }
  }
  for (int i = 0, cur = sup.size() - p.size(); i < p.size(); ++i) {
    res = res * p[i] % MOD * C[cur][sz[i]] % MOD;
    cur -= sz[i];
  }
  cout << res << '\n';
}
int main() {
  readInput();
  init();
  solve();
}
