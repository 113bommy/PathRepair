#include <bits/stdc++.h>
using namespace std;
long long powMod(long long x, long long y) {
  long long p = 1;
  while (y) {
    if (y % 2) {
      p = (p * x) % (long long)1e9 + 7;
    }
    y /= 2;
    x = (x * x) % (long long)1e9 + 7;
  }
  return p;
}
long long invMod(long long x) { return powMod(x, (long long)1e9 + 7 - 2); }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long> > v;
  for (long long i = 0; i <= n - 1; i++) {
    long long x, y;
    cin >> y >> x;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  long long sum[n];
  sum[0] = 0;
  set<long long> s;
  long long mx = 0;
  long long add = 0;
  for (long long i = n - 1; i >= n - k; i--) {
    add += v[i].second;
    s.insert(v[i].second);
    sum[i] = add;
    mx = max(mx, sum[i] * v[i].first);
  }
  for (long long i = n - k - 1; i >= 1; i--) {
    s.insert(v[i].second);
    add += v[i].second;
    add -= *s.begin();
    s.erase(*s.begin());
    sum[i] = add;
    mx = max(mx, sum[i] * v[i].first);
  }
  cout << mx << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
