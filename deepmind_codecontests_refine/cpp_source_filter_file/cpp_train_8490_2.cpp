#include <bits/stdc++.h>
using namespace std;
template <typename C>
auto test(C* x) -> decltype(cerr << *x, 0LL);
template <typename C>
char test(...);
template <typename C>
struct itr {
  C begin, end;
};
template <typename C>
itr<C> get_range(C b, C e) {
  return itr<C>{b, e};
};
struct debug {
  template <typename T>
  debug& operator<<(const T&) {
    return *this;
  }
};
string _ARR_(int* arr, int sz) {
  string ret = "{ " + to_string(arr[0]);
  for (int i = 1; i < sz; i++) ret += " , " + to_string(arr[i]);
  ret += " }";
  return ret;
}
const int INF = 1e9 + 7;
const int MxN = 2e5 + 100;
int n, up[MxN][22];
int64_t sum[MxN], w[MxN], a[MxN], d[MxN];
vector<int> adj[MxN];
void dfs_precalc(int u, int p) {
  sum[u] = 1;
  d[u] = d[p] + w[u];
  up[u][0] = p;
  for (int i = 1; i < 22; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (int v : adj[u]) {
    dfs_precalc(v, u);
  }
  return;
}
void update(int u, int val) {
  if (u == 0) return;
  for (int i = 21; i >= 0; i--) {
    if (d[up[u][i]] >= val) u = up[u][i];
  }
  if (u == 0) return;
  u = up[u][0];
  sum[u]--;
  return;
}
void dfs(int u) {
  update(u, d[u] - a[u]);
  for (int i : adj[u]) {
    dfs(i);
    sum[u] += sum[i];
  }
  return;
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  d[0] = 0;
  w[0] = 0;
  for (int u = 1; u < n; u++) {
    int v, W;
    cin >> v >> W;
    v--;
    adj[v].push_back(u);
    w[u] = W;
  }
  d[0] = 0;
  dfs_precalc(0, 0);
  dfs(0);
  for (int i = 0; i < n; i++) cout << sum[i] - 1 << ' ';
  cout << '\n';
  return 0;
}
