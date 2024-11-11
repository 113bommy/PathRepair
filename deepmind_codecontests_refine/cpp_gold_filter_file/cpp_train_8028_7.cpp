#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 2e5 + 5, inf = 1e18, mod = 1000000007;
const double PI = 3.1415926536;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& mas) {
  for (const auto& x : mas) {
    out << x << ' ';
  }
  return out;
}
void ok() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }
inline long long nxt() {
  long long x;
  cin >> x;
  return x;
}
struct Node {
  vector<int> g;
  long long sum = 0;
  long long sum1 = 0;
  void push(int v) { g.push_back(v); }
  vector<int>::iterator begin() { return g.begin(); }
  vector<int>::iterator end() { return g.end(); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n = nxt();
  vector<Node> g(n);
  vector<long long> a(n);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    a[i] = nxt();
    total += a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int v = nxt() - 1, u = nxt() - 1;
    g[v].push(u);
    g[u].push(v);
  }
  vector<int> lvl(n);
  function<void(int, int)> dfs = [&](int v, int p) {
    g[v].sum1 = a[v] * lvl[v];
    g[v].sum = a[v];
    for (const auto& to : g[v]) {
      if (to != p) {
        lvl[to] += lvl[v] + 1;
        dfs(to, v);
        g[v].sum += g[to].sum;
        g[v].sum1 += g[to].sum1;
      }
    }
  };
  dfs(0, -1);
  long long ans = 0;
  long long res = g[0].sum1;
  function<void(int, int)> calc = [&](int v, int p) {
    ans = max(ans, res);
    for (const auto& to : g[v]) {
      if (to == p) continue;
      g[v].sum -= g[to].sum;
      res -= g[to].sum;
      g[to].sum += g[v].sum;
      res += g[v].sum;
      calc(to, v);
      res -= g[v].sum;
      g[to].sum -= g[v].sum;
      res += g[to].sum;
      g[v].sum += g[to].sum;
    }
  };
  calc(0, -1);
  cout << ans;
  return 0;
}
