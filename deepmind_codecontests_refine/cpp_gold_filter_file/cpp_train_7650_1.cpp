#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), primes;
  vector<int> ans;
  for (int i = 2; i <= n; i++) {
    if (!a[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j <= n; j += i) {
        a[j] = 1;
      }
    }
  }
  for (int p : primes) {
    for (int i = p; i <= n; i *= p) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << "\n";
  for (int x : ans) {
    cout << x << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
