#include <bits/stdc++.h>
using namespace std;
template <class C>
constexpr int sz(const C &c) {
  return int(c.size());
}
constexpr const char nl = '\n', sp = ' ';
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128_t;
using ui128 = __uint128_t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, K, A, B, C, D;
  cin >> N >> K >> A >> B >> C >> D;
  if (N == 4 || K < N + 1) {
    cout << -1 << nl;
    return 0;
  }
  vector<bool> seen(N + 1, false);
  seen[A] = seen[B] = seen[C] = seen[D] = true;
  vector<int> ord;
  for (int i = 1; i <= N; i++)
    if (!seen[i]) ord.push_back(i);
  cout << A << sp << C;
  for (int i = 0; i < sz(ord); i++) cout << sp << ord[i];
  cout << sp << B << sp << D << nl;
  cout << C << sp << A;
  for (int i = 0; i < sz(ord); i++) cout << sp << ord[i];
  cout << sp << D << sp << B << nl;
  return 0;
}
