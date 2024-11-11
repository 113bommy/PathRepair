#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (long long i = 0; i < v.size(); ++i) os << v[i] << " ";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (auto it : v) os << it << " ";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << v.first << " " << v.second;
  return os;
}
const long long mod = 1e9 + 7;
const long long inf = 2e18;
const long long ninf = -2e18;
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  time_t t1, t2;
  t1 = clock();
  long long n, m, d;
  cin >> n >> m >> d;
  vector<pair<long long, long long> > arr;
  vector<long long> ans(n, -1);
  set<pair<long long, long long> > s;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s.insert(make_pair(x, i));
  }
  long long day = 1;
  while (!s.empty()) {
    long long curr = s.begin()->first;
    long long cind = s.begin()->second;
    s.erase(s.begin());
    ans[cind] = day;
    while (1) {
      auto it = s.lower_bound(make_pair(curr + d + 1, ninf));
      if (it == s.end()) {
        day++;
        break;
      }
      ans[it->second] = day;
      curr = it->first;
      s.erase(it);
    }
  }
  cout << day << '\n';
  cout << ans << '\n';
  t2 = clock();
  cerr << '\n' << t2 - t1 << '\n';
  return 0;
}
