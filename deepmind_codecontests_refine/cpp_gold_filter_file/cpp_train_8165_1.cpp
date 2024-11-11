#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
ll getrndll(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
template <typename T1, typename T2>
inline bool relax(T1& a, const T2& b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool strain(T1& a, const T2& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 1e5 + 3;
int cnt[N];
ll dp[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  dp[1] = cnt[1];
  for (int i = 2; i < N; ++i) {
    dp[i] = max(dp[i - 2] + 1LL * i * cnt[i], dp[i - 1]);
  }
  cout << dp[N - 1] << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  srand(time(0));
  int t = 1;
  while (t--) solve();
  return 0;
}
