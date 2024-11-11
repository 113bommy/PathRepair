#include <bits/stdc++.h>
const long long N = 1000006;
using namespace std;
const long long MOD = 1000000007LL;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T power(T x, T y, long long m = MOD) {
  T ans = 1;
  while (y > 0) {
    if (y & 1LL) ans = (ans * x) % m;
    y >>= 1LL;
    x = (x * x) % m;
  }
  return ans % m;
}
map<pair<string, string>, long long> m;
int32_t main() {
  long long n, a, b, k, f;
  cin >> n >> a >> b >> k >> f;
  string prev = "0";
  long long tc = 0;
  for (long long(i) = (0); i < (n); i++) {
    string s1, s2;
    cin >> s1 >> s2;
    vector<string> v;
    v.emplace_back(s1);
    v.emplace_back(s2);
    sort(v.begin(), v.end());
    if (s1 == prev) {
      m[make_pair(v[0], v[1])] += b;
      tc += b;
    } else
      m[make_pair(v[0], v[1])] += a, tc += a;
    prev = s2;
  }
  vector<long long> v;
  for (auto i : m) v.emplace_back(i.second);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (auto i : v) {
    if (k <= 0) break;
    long long save = i - f;
    if (save <= 0) break;
    tc -= save;
    --k;
  }
  cout << tc;
}
