#include <bits/stdc++.h>
const long long inf = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mxn = 1e6 + 1;
using namespace std;
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (auto& i : a) in >> i;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (auto& i : a) out << i << " ";
  return out;
}
set<pair<long long, long long> > s;
vector<long long> v;
long long n, k;
void solve() {
  cin >> n >> k;
  v.resize(n + 2);
  for (long long i = 0; i < k; i++) {
    long long x;
    cin >> x;
    s.insert({x, x});
    v[x] = 1;
    if (v[x - 1]) s.insert({x - 1, x});
    if (v[x + 1]) s.insert({x, x + 1});
  }
  cout << n * 3 - 2 - (long long)s.size();
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
