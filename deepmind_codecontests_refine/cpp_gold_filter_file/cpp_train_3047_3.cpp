#include <bits/stdc++.h>
namespace cplib {
using namespace std;
template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void read_n(InputIt it, int n) {
  copy_n(istream_iterator<T>(cin), n, it);
}
template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void read(InputIt first, InputIt last) {
  read_n(first, distance(first, last));
}
template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void write(InputIt first, InputIt last, const char *delim = "\n") {
  copy(first, last, ostream_iterator<T>(cout, delim));
}
}  // namespace cplib
using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
ll solve(vector<ll> a, vector<ll> r, ll d) {
  int n = a.size();
  ll const INF = 1e16;
  vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
  dp[0][0] = r[0] * a[0] + r[2];
  dp[0][1] = min(r[1], r[0] * a[0] + r[0]);
  for (int i = 1; i < n; ++i) {
    dp[i][0] =
        min({dp[i - 1][0] + d + r[0] * a[i] + r[2],
             dp[i - 1][1] + d + r[0] * a[i] + r[2] + d + r[0] + d,
             dp[i - 1][1] + d + r[0] * a[i] + r[0] + d + r[0] + d + r[0],
             dp[i - 1][1] + d + r[1] + d + r[0] + d + r[0],
             (i == n - 1 ? dp[i - 1][1] + d + r[0] * a[i] + r[2] + d + r[0]
                         : INF)});
    dp[i][1] =
        min({dp[i - 1][0] + d + r[0] * a[i] + r[0], dp[i - 1][0] + d + r[1],
             dp[i - 1][1] + d + r[0] * a[i] + r[0] + d + r[0] + d,
             dp[i - 1][1] + d + r[1] + d + r[0] + d});
  }
  return dp[n - 1][0];
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int n;
  ll d;
  cin >> n;
  vector<ll> r(3);
  read(begin(r), end(r));
  cin >> d;
  vector<ll> a(n);
  read(begin(a), end(a));
  cout << solve(a, r, d) << endl;
  return 0;
}
