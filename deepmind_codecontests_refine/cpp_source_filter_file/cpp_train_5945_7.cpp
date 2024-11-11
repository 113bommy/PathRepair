#include <bits/stdc++.h>
using namespace std;
void use_cio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
template <typename... Args>
void dbg(Args... args) {
  ((cout << args << " "), ...);
  cout << endl;
}
long long a, b;
long long solve(long long n, long long m) {
  long long nm = n + m;
  vector<pair<pair<long long, long long>, int>> posall;
  for (long long i = 1; i * i <= nm; i++)
    if (nm % i == 0) {
      posall.push_back({{i, nm / i}, 1});
    }
  for (long long i = 1; i * i <= n; i++)
    if (n % i == 0) {
      posall.push_back({{i, n / i}, 0}), posall.push_back({{n / i, i}, 0});
    }
  sort(posall.begin(), posall.end());
  vector<long long> Va;
  long long ret = 9123456789123456789;
  for (auto [x, y] : posall) {
    if (y) {
      if (lower_bound(Va.begin(), Va.end(), -x.second) <= Va.end()) {
        ret = min(ret, 2 * (x.first + x.second));
      }
    } else {
      Va.push_back(-x.second);
    }
  }
  return ret;
}
int main() {
  use_cio();
  cin >> a >> b;
  long long ans1 = solve(a, b);
  swap(a, b);
  long long ans2 = solve(a, b);
  cout << min(ans1, ans2);
}
