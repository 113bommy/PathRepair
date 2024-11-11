#include <bits/stdc++.h>
using namespace std;
long long int sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) {
  return a + sum(args...);
}
long long int sqr(long long int a) { return 1LL * a * a; }
long long int ans;
void fun(vector<long long int> a, vector<long long int> b,
         vector<long long int> c) {
  for (auto i : a) {
    auto gr = lower_bound(b.begin(), b.end(), i);
    auto lf = upper_bound(c.begin(), c.end(), i);
    if (gr == b.end() || lf == c.begin()) continue;
    lf--;
    ans = min(ans, sqr(i - *gr) + sqr(*gr - *lf) + sqr(i - *lf));
  }
}
void solve() {
  long long int r, g, b;
  cin >> r >> g >> b;
  ans = LLONG_MAX;
  vector<long long int> p, q, l;
  for (long long int i = 0; i < r; i++) {
    long long int arb;
    cin >> arb;
    p.push_back(arb);
  }
  for (long long int i = 0; i < g; i++) {
    long long int arb;
    cin >> arb;
    q.push_back(arb);
  }
  for (long long int i = 0; i < b; i++) {
    long long int arb;
    cin >> arb;
    l.push_back(arb);
  };
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  sort(l.begin(), l.end());
  fun(p, q, l);
  fun(p, l, q);
  fun(q, l, p);
  fun(q, p, l);
  fun(l, p, q);
  fun(l, q, p);
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
