#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2) % 1000000007;
  if (y % 2 == 0)
    return (temp % 1000000007 * temp % 1000000007) % 1000000007;
  else
    return ((x % 1000000007) *
            ((temp % 1000000007 * temp % 1000000007) % 1000000007)) %
           1000000007;
}
bool comp(pair<long long, long long>& a, pair<long long, long long>& b) {
  return (a.first < b.first);
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v;
  set<long long> s;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back({a, b});
    s.insert(a);
  }
  sort(v.begin(), v.end(), comp);
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    long long x = v[i].first;
    long long h = v[i].second;
    auto itr1 = s.lower_bound(x - h);
    auto itr2 = s.lower_bound(x + h);
    if (s.find(x - h) == s.end() && (i == 0 || *itr1 == v[i - 1].first)) {
      s.insert(x - h);
      c++;
    } else if (i == n - 1) {
      c++;
    } else if (s.find(x + h) == s.end() && *itr2 == v[i + 1].first) {
      s.insert(x + h);
      c++;
    }
  }
  cout << c << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
