#include <bits/stdc++.h>
using namespace std;
void solve();
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(12);
  solve();
  return 0;
}
template <typename T>
void prv(vector<T> v) {
  for (int __ii = 0; __ii < ((int)v.size()); __ii++) {
    if (__ii) cout << ' ';
    cout << v[__ii];
  }
  cout << '\n';
}
template <typename T>
void prm(vector<vector<T>> v) {
  for (int __ii = 0; __ii < ((int)v.size()); __ii++) {
    for (int __jj = 0; __jj < v[__ii].size(); __jj++) {
      if (__jj) cout << ' ';
      cout << v[__ii][__jj];
    }
    cout << '\n';
  }
}
template <typename T>
void sc(T& x) {
  cin >> x;
}
template <typename Head, typename... Tail>
void sc(Head& head, Tail&... tail) {
  cin >> head;
  sc(tail...);
}
template <typename T>
void pr(const T& x) {
  cout << x << '\n';
}
template <typename Head, typename... Tail>
void pr(const Head& head, const Tail&... tail) {
  cout << head << ' ';
  pr(tail...);
}
template <typename... T>
void err(const T&... cod) {
  pr(cod...);
  exit(0);
}
const int N = 1e6 + 10;
int cnt[N], n, k;
bool can(int x) {
  int z = 0;
  for (int i = 0; i + x < N; i += x) {
    z += cnt[i + k];
    if (i > 0) z -= cnt[i - 1];
  }
  return (z == n);
}
void solve() {
  sc(n, k);
  vector<int> a(n);
  for (int __ii = 0; __ii < n; __ii++) cin >> a[__ii];
  int ans = 1, mn = *min_element(a.begin(), a.end());
  if (mn <= k + 1) err(mn);
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
  for (int i = k + 1; i < N; i++)
    if (can(i)) ans = i;
  pr(ans);
}
