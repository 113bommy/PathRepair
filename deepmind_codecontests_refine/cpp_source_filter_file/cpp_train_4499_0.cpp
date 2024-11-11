#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <size_t I, class T>
struct n_vector : vector<n_vector<I - 1, T>> {
  n_vector() = default;
  template <class... Args>
  n_vector(size_t n, Args... args)
      : vector<n_vector<I - 1, T>>(n, n_vector<I - 1, T>(args...)) {}
};
template <class T>
struct n_vector<1, T> : vector<T> {
  template <class... Args>
  n_vector(Args... args) : vector<T>(args...) {}
};
vector<ll> fib = {1ll, 2ll};
const ll N = 1e18;
int main() {
  for (ll new_v; (new_v = *fib.rbegin() + *(fib.rbegin() + 1)) && (new_v <= N);)
    fib.push_back(new_v);
  int m = fib.size();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = m - 1; i >= 0; i--)
      if (fib[i] <= n) n -= fib[i], a.push_back(i + 1);
    a.push_back(0);
    reverse(a.begin(), a.end());
    n_vector<2, int> dp((int)a.size(), 2);
    dp[0][0] = 1, dp[0][1] = 0;
    for (int i = 1; i < (int)a.size(); i++) {
      dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] * ((a[i] - a[i - 1] - 1) / 2) +
                 dp[i - 1][1] * ((a[i] - a[i - 1]) / 2);
    }
    cout << dp[(int)a.size() - 1][0] + dp[(int)a.size() - 1][1] << endl;
  }
}
