#include <bits/stdc++.h>
using namespace std;
inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const long long inf = 2e9;
const long long maxN = 1e5 + 123;
const long long maxB = 31;
vector<long long> v;
long long bettr(long long n, set<long long> numbers) {
  if (numbers.size() == 0) {
    return 0;
  }
  set<long long> s1, s2;
  for (auto i : numbers) {
    if (((v[i] ^ (1 << n)) >> n) == 0) {
      s1.insert(i);
    } else {
      s2.insert(i);
    }
  }
  if (n == 0) {
    if (s1.size() == 0 || s2.size() == 0) {
      return 0;
    }
    return 1;
  }
  if (s1.size() == 0) {
    return bettr(n - 1, s2);
  }
  if (s2.size() == 0) {
    return bettr(n - 1, s1);
  }
  long long zero = bettr(n - 1, s1);
  long long one = bettr(n - 1, s2);
  return min(one, zero) + (1 << n);
}
void solve() {
  long long n;
  cin >> n;
  v.resize(n);
  for (long long i = 0; i < n; ++i) cin >> v[i];
  set<long long> s;
  for (long long i = 0; i < n; ++i) s.insert(i);
  long long mlen = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; (1 << j) < v[i]; ++j) {
      mlen = max(mlen, j);
    }
  }
  cout << bettr(mlen, s) << "\n";
}
signed main() {
  fastio();
  solve();
  return 0;
}
