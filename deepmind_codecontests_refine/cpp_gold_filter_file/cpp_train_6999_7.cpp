#include <bits/stdc++.h>
using namespace std;
const long long N = 500001;
long long mod = 998244353;
long long ans = 0;
long long sq(long long x) { return 1ll * x * x; }
void solve(vector<long long> a, vector<long long> b, vector<long long> c) {
  for (auto x : a) {
    auto l = upper_bound(c.begin(), c.end(), x);
    auto k = lower_bound(b.begin(), b.end(), x);
    if (l == c.begin() || k == b.end()) continue;
    l--;
    ans = min(ans, sq(x - *l) + sq(x - *k) + sq(*l - *k));
  }
}
void Main() {
  long long a;
  cin >> a;
  long long d;
  cin >> d;
  long long c;
  cin >> c;
  vector<long long> r, g, b;
  for (long long i = 0; i < a; i++) {
    long long l;
    cin >> l;
    r.push_back(l);
  }
  for (long long i = 0; i < d; i++) {
    long long l;
    cin >> l;
    g.push_back(l);
  }
  for (long long i = 0; i < c; i++) {
    long long l;
    cin >> l;
    b.push_back(l);
  }
  sort(r.begin(), r.end());
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  ans = 5e18;
  solve(r, g, b);
  solve(g, b, r);
  solve(b, r, g);
  solve(b, g, r);
  solve(r, b, g);
  solve(g, r, b);
  cout << ans << "\n";
}
int32_t main() {
  srand(time(0));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    Main();
  }
}
