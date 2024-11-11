#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795l;
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
struct Input {
  int n, k;
  vector<int> a;
  vector<vector<int> > g;
  bool read() {
    if (scanf("%d%d", &n, &k) != 2) return 0;
    a.resize(n);
    for (int i = int(0); i < int(n); ++i) scanf("%d", &a[i]);
    g.assign(n, vector<int>());
    for (int i = int(0); i < int(n - 1); ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    return 1;
  }
  void init(const Input& input) { *this = input; }
};
struct Data : Input {
  int ans;
  void write() { printf("%d\n", ans); }
};
struct Solution : Data {
  void filter() {
    for (int i = int(0); i < int(n); ++i) {
      sort((g[i]).begin(), (g[i]).end());
    }
    g[0].push_back(n);
  }
  vector<int> alpha, beta;
  vector<int> good;
  void calc_dp(int v, int par) {
    for (int son : g[v]) {
      if (son == par) continue;
      calc_dp(son, v);
    }
    bool all_good = (good[v]);
    alpha[v] = 1;
    for (int son : g[v]) {
      if (son == par) continue;
      alpha[v] += alpha[son];
      if (alpha[son] == -1) all_good = false;
    }
    if (!all_good) {
      alpha[v] = -1;
    }
    if (good[v]) {
      int max_bad = 0;
      beta[v] = 1;
      for (int son : g[v]) {
        if (son == par) continue;
        if (alpha[son] != -1) {
          beta[v] += alpha[son];
        } else {
          umx(max_bad, beta[son]);
        }
      }
      beta[v] += max_bad;
    }
  }
  void update_val(int v, int par, int al, int bt, int& res) {
    ;
    int old_al = alpha[par], old_bt = beta[par];
    alpha[par] = al, beta[par] = bt;
    umx(res, beta[v] + bt);
    ;
    if (!good[v]) {
      for (int son : g[v]) {
        if (son == par) continue;
        update_val(son, v, -1, 0, res);
      }
    } else {
      int all_alpha = 1;
      int good_alpha = 1;
      vector<int> bad_alphas;
      vector<int> max_bt;
      for (int son : g[v]) {
        all_alpha += alpha[son];
        if (alpha[son] == -1) {
          bad_alphas.push_back(son);
          max_bt.push_back(beta[son]);
          sort(max_bt.rbegin(), max_bt.rend());
          max_bt.resize(2);
        } else {
          good_alpha += alpha[son];
        }
      }
      for (int son : g[v]) {
        if (son == par) continue;
        int new_al = -1;
        int new_bt = 0;
        if (bad_alphas.empty() ||
            (((int)(bad_alphas).size()) == 1 && bad_alphas.front() == son)) {
          new_al = all_alpha - alpha[son];
        }
        new_bt = good_alpha;
        if (alpha[son] != -1) {
          new_bt -= alpha[son];
          if (!max_bt.empty()) {
            new_bt += max_bt[0];
          }
        } else {
          if (max_bt[0] != beta[son]) {
            new_bt += max_bt[0];
          } else if (((int)(max_bt).size()) > 1) {
            new_bt += max_bt[1];
          }
        }
        update_val(son, v, new_al, new_bt, res);
      }
    }
    alpha[par] = old_al;
    beta[par] = old_bt;
  }
  bool can(int x) {
    alpha.assign(n + 1, -1);
    beta.assign(n + 1, 0);
    good.assign(n + 1, 0);
    for (int i = int(0); i < int(n); ++i) good[i] = a[i] >= x;
    good[n] = 0;
    calc_dp(0, n);
    int max_val = 0;
    ;
    ;
    update_val(0, n, 0, 0, max_val);
    return max_val >= k;
  }
  void solve() {
    filter();
    ans = 0;
    int l = 0, r = 1000001;
    while (l < r - 1) {
      int mid = (l + r) / 2;
      ;
      if (can(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    ans = l;
  }
  void clear() {
    ;
    *this = Solution();
  }
};
Solution sol;
int main() {
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  sol.read();
  sol.solve();
  sol.write();
  return 0;
}
