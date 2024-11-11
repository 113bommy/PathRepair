#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <class T, class T2>
T _f_pow(T a, T2 b) {
  T res = 1LL;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return (res);
}
template <class T>
T gcd(T a, T b) {
  while (a && b)
    if (a > b)
      (a %= b);
    else
      (b %= a);
  return a + b;
}
template <class T>
T lcm(T a, T b) {
  return (a * b) / gcd(a, b);
}
int n, m;
long long par[(int)2e6 + 5], sz[(int)2e6 + 5], cmp, mxComp;
void init() {
  iota(par, par + n + 1, 0);
  fill(sz, sz + n + 1, 1);
  cmp = n;
  mxComp = 1;
}
int Find(int u) { return u == par[u] ? u : par[u] = Find(par[u]); }
int join(int u, int v) {
  u = Find(u);
  v = Find(v);
  if (u == v) return 0;
  if (sz[u] > sz[v]) swap(u, v);
  par[u] = v;
  sz[v] += sz[u];
  mxComp = max(mxComp, sz[v]);
  cmp--;
  return 1;
}
int from[(int)2e6 + 5], to[(int)2e6 + 5], cst[(int)2e6 + 5],
    sorted[(int)2e6 + 5];
int f, s;
int krus() {
  init();
  sort(sorted, sorted + m, [](int a, int b) { return cst[a] < cst[b]; });
  int ret = 0;
  for (int k = 0; k < m; k++) {
    int e = sorted[k];
    if (join(from[e], to[e])) {
      if (Find(f) == Find(s)) {
        cout << cst[e] << endl;
        return 0;
      }
      ret += cst[e];
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> m;
  int tm;
  m--;
  cin >> f >> s >> tm;
  for (int i = 0, _n = (m); i < _n; i++) {
    cin >> from[i] >> to[i] >> cst[i];
    sorted[i] = i;
  }
  if (krus()) cout << ((int)1e9) << endl;
  return 0;
}
