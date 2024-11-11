#include <bits/stdc++.h>
using namespace std;
inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const long long inf = 2e9;
void solve() {
  long long n;
  cin >> n;
  vector<long long> m(n);
  for (long long i = 0; i < n; ++i) {
    cin >> m[i];
  }
  vector<long long> L(n, -1), R(n, n);
  vector<long long> vec;
  for (long long i = 0; i < n; ++i) {
    while (vec.size() > 0 && m[vec.back()] > m[i]) {
      vec.pop_back();
    }
    if (vec.size() > 0) L[i] = vec.back();
    vec.push_back(i);
  }
  vec.clear();
  for (long long i = n - 1; i >= 0; --i) {
    while (vec.size() > 0 && m[vec.back()] > m[i]) {
      vec.pop_back();
    }
    if (vec.size() > 0) R[i] = vec.back();
    vec.push_back(i);
  }
  vector<long long> l(n, 0), r(n, 0);
  long long min_el = inf;
  for (long long i = 0; i < n; ++i) {
    if (m[i] < min_el) {
      l[i] = (i + 1) * m[i];
      min_el = m[i];
    } else {
      l[i] = l[L[i]] + (i - L[i]) * m[i];
    }
  }
  min_el = inf;
  for (long long i = n - 1; i >= 0; --i) {
    if (m[i] < min_el) {
      r[i] = (n - i) * m[i];
      min_el = m[i];
    } else {
      r[i] = r[R[i]] + (n - i - (n - R[i])) * m[i];
    }
  }
  long long best = 0;
  for (long long i = 0; i < n; ++i) {
    if (l[i] + r[i] - m[i] > l[best] + r[best] - m[best]) {
      best = i;
    }
  }
  vector<long long> ans(n, 0);
  ans[best] = m[best];
  min_el = m[best];
  for (long long i = best + 1; i < n; ++i) {
    if (m[i] > min_el) {
      ans[i] = min_el;
    } else {
      ans[i] = m[i];
      min_el = m[i];
    }
  }
  min_el = m[best];
  for (long long i = best - 1; i >= 0; --i) {
    if (m[i] > min_el) {
      ans[i] = min_el;
    } else {
      ans[i] = m[i];
      min_el = m[i];
    }
  }
  for (auto i : ans) cout << i << ' ';
  cout << '\n';
}
signed main() {
  fastio();
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
