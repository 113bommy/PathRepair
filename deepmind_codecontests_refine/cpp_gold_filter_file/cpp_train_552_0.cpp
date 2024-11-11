#include <bits/stdc++.h>
using namespace std;
const long double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
inline void io() {}
const long long mod = 1e9 + 7;
const long long maxn = 1e6 + 5;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort((v).begin(), (v).end(), cmp);
  map<pair<long long, long long>, long long> mp;
  map<long long, long long> h;
  for (long long i = 0; i < n; i++) mp[v[i]]++;
  cout << mp[v[m - 1]];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  io();
  long long tc = 1;
  while (tc--) {
    solve();
    cout << '\n';
  }
  return 0;
}
