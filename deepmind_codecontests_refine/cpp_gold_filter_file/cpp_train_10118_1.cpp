#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:2000000")
using namespace std;
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};
using ll = long long;
using db = long double;
using ii = pair<int, int>;
const int N = 1e5 + 5, LG = 19, MOD = 1e9 + 7;
const int SQ = 320;
const long double EPS = 1e-7;
mt19937 mt(time(0));
vector<int> adj[N];
int n, p[N];
int lvl[N];
int par[N];
int mx[N];
vector<int> ans;
vector<int> out;
int cnt = 0;
void dfs(int node) {
  ans.push_back(node);
  for (int i = 0; i < cnt; i++) out.push_back(node);
  sort(adj[node].begin(), adj[node].end(),
       [&](int i, int j) { return mx[i] < mx[j]; });
  cnt = 0;
  for (auto v : adj[node]) dfs(v);
  cnt++;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    adj[p[i]].push_back(i);
    lvl[i] = lvl[p[i]] + 1;
    mx[i] = lvl[i];
  }
  for (int i = n; i; --i) mx[p[i]] = max(mx[p[i]], mx[i]);
  dfs(0);
  for (auto x : ans) cout << x << ' ';
  cout << endl << out.size() << endl;
  for (auto x : out) cout << x << ' ';
  return 0;
}
