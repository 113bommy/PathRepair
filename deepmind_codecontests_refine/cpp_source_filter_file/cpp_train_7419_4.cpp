#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 5e5 + 5;
vector<long long> v[N];
void solve() {
  long long n;
  cin >> n;
  v[0].clear();
  for (long long i = 1; i < n + 1; i++) {
    v[i].clear();
    v[i].push_back(-1);
  }
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v[x].push_back(i);
  }
  if ((long long)((v[0]).size()) < 2) {
    cout << "0\n";
    return;
  }
  long long z = (long long)((v[0]).size());
  long long L = v[0][(z + 1) / 2], R = v[0][z / 2 - 1];
  vector<pair<long long, long long> > vec;
  for (long long i = 1; i < n + 1; i++) {
    v[i].push_back(n + 2);
    long long l = *prev(lower_bound((v[i]).begin(), (v[i]).end(), L));
    long long r = *upper_bound((v[i]).begin(), (v[i]).end(), R);
    if (l != -1 || r != n + 2) vec.push_back({l, r});
  }
  for (long long x : v[0]) {
    if (x < L) vec.push_back({x, -1});
  }
  sort((vec).begin(), (vec).end(),
       [&](pair<long long, long long> a, pair<long long, long long> b) {
         return a.first > b.first;
       });
  long long ans = 0;
  set<long long> s;
  vector<long long> vis(n + 4);
  for (auto x : vec) {
    if (x.second == -1) {
      if ((long long)((s).size())) {
        long long r = -*s.begin();
        s.erase(s.begin());
        vis[r] = 1;
        ans++;
      }
    } else {
      s.insert(-x.second);
    }
  }
  vector<long long> vec2;
  for (auto x : vec) {
    if (x.second != -1 && !vis[x.second]) vec2.push_back(x.second);
  }
  for (long long x : v[0]) {
    if (x > R) vec2.push_back(x), vis[x] = 1;
  }
  s.clear();
  sort((vec2).begin(), (vec2).end());
  for (long long x : vec2) {
    if (vis[x]) {
      if ((long long)((s).size())) {
        s.erase(s.begin());
        ans++;
      }
    } else {
      s.insert(x);
    }
  }
  amin(ans, z / 2);
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
