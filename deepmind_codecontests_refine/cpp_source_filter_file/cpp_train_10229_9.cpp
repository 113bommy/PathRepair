#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
void DBG() {
  cerr << "]"
       << "\n";
}
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << h;
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
template <class H>
void DBG(vector<H> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    cerr << v[i];
    if (i != (int)v.size() - 1) cerr << ", ";
  }
  cerr << ']' << "\n";
}
constexpr long long MOD = 1e9 + 7;
constexpr long long inf = 1e9 + 7;
void solve(int tc) {
  int a, b, n;
  cin >> a >> b >> n;
  int cnt = 0;
  while (a < n and b < n) {
    if (a > b)
      b += a;
    else
      a += b;
    cnt++;
  }
  cout << cnt << "\n";
}
signed main() {
  ios::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);
  int tc = 0;
  cin >> tc;
  for (int i = 0; i < tc; i++) solve(i + 1);
}
