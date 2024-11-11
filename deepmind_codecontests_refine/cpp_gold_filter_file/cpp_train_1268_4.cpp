#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Vi = vector<int>;
void run();
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(18);
  run();
  return 0;
}
int uplg(int n) { return 32 - __builtin_clz(n); }
int uplg(ll n) { return 64 - __builtin_clzll(n); }
struct SAT2 : Vi {
  vector<Vi> G;
  Vi order, flags;
  SAT2(int n = 0) : G(n * 2) {}
  int addVar() {
    G.resize(int((G).size()) + 2);
    return int((G).size()) / 2;
  }
  void imply(int i, int j) {
    i = max(i * 2 - 1, -i * 2 - 2);
    j = max(j * 2 - 1, -j * 2 - 2);
    G[i].push_back(j);
    G[j ^ 1].push_back(i ^ 1);
  }
  void either(int i, int j) { imply(-i, j); }
  void atMostOne(Vi& vars) {
    int first = addVar();
    for (auto& i : (vars)) {
      int second = addVar();
      imply(first, second);
      imply(i, -first);
      imply(i, second);
      first = second;
    }
  }
  bool solve() {
    assign(int((G).size()) / 2 + 1, -1);
    flags.assign(int((G).size()), 0);
    for (int i = (0); i < (int((G).size())); i++) dfs(i);
    while (!order.empty()) {
      if (!propag(order.back() ^ 1, 1)) return 0;
      order.pop_back();
    }
    return 1;
  }
  void dfs(int i) {
    if (flags[i]) return;
    flags[i] = 1;
    for (auto& e : (G[i])) dfs(e);
    order.push_back(i);
  }
  bool propag(int i, bool first) {
    if (!flags[i]) return 1;
    flags[i] = 0;
    if (at(i / 2 + 1) >= 0) return first;
    at(i / 2 + 1) = i & 1;
    for (auto& e : (G[i]))
      if (!propag(e, 0)) return 0;
    return 1;
  }
};
void run() {
  int n, p, M, m;
  cin >> n >> p >> M >> m;
  SAT2 sat(p + M + 1);
  for (int i = (1); i < (M + 1); i++) {
    sat.imply(p + i, p + i + 1);
  }
  for (int i = (0); i < (n); i++) {
    int first, second;
    cin >> first >> second;
    sat.either(first, second);
  }
  for (int i = (1); i < (p + 1); i++) {
    int l, r;
    cin >> l >> r;
    sat.imply(i, -p - l);
    sat.imply(i, p + r + 1);
  }
  for (int i = (0); i < (m); i++) {
    int u, v;
    cin >> u >> v;
    sat.either(-u, -v);
  }
  if (!sat.solve()) {
    cout << -1 << endl;
    return;
  }
  int f = 1;
  for (int i = (1); i < (M + 2); i++)
    if (sat[p + i]) {
      f = i - 1;
      break;
    }
  f = max(f, 1);
  Vi ans;
  for (int i = (1); i < (p + 1); i++)
    if (sat[i]) ans.push_back(i);
  cout << int((ans).size()) << ' ' << f << '\n';
  for (auto& a : (ans)) cout << a << ' ';
  cout << '\n';
}
