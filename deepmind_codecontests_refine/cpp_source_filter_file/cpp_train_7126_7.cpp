#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using LL = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename S>
using P = pair<T, S>;
using LD = long double;
template <typename T, typename S>
void check(T& a, const S& b) {
  if (a >= b) {
    a %= b;
  }
}
template <typename T>
T gcd(T u, T v) {
  if (u == v) return u;
  if (u == 0) return v;
  if (v == 0) return u;
  if (~u & 1) {
    if (v & 1)
      return gcd(u >> 1, v);
    else
      return gcd(u >> 1, v >> 1) << 1;
  }
  if (~v & 1) return gcd(u, v >> 1);
  if (u > v) return gcd((u - v) >> 1, v);
  return gcd((v - u) >> 1, u);
}
const int N = (int)3e5 + 10;
V<V<int>> g;
bool vis[N];
map<int, int> m;
map<int, V<int>> M;
V<int> p, fin, st;
int dfs(int u, int A, int col) {
  vis[u] = true;
  bool ans = !M[A - p[u]].empty();
  fin[u] = col;
  for (auto& i : g[u]) {
    if (!vis[i]) {
      ans &= dfs(i, A, col);
    }
  }
  st.push_back(u);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cerr.tie(NULL);
  ;
  int n, a, b;
  cin >> n >> a >> b;
  g.resize(n + 1);
  V<P<int, int>> t(n + 1);
  memset(vis, false, sizeof vis);
  p.resize(n + 1);
  fin.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    t[i] = {p[i], i};
    m[p[i]] = i;
    M[p[i]].push_back(i);
  }
  sort(t.begin(), t.end());
  for (int i = 1; i <= n; i++) {
    if (t[i].first == t[i - 1].first) continue;
    int x = t[i].first;
    int l = m[x];
    if (m[a - x]) {
      int r = m[a - x];
      g[l].push_back(r);
    } else if (m[b - x]) {
      int r = m[b - x];
      g[l].push_back(r);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      st.clear();
      bool ans = dfs(i, a, 0);
      if (!ans) {
        while (!st.empty()) vis[st.back()] = false, st.pop_back();
        ans = dfs(i, b, 1);
      }
      if (!ans) {
        cout << "NO\n";
        return 0;
      }
      while (!st.empty()) {
        for (int& j : M[p[st.back()]]) {
          fin[j] = fin[st.back()];
          vis[j] = true;
        }
        st.pop_back();
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << fin[i] << " \n"[i == n];
  }
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
