#include <bits/stdc++.h>
using namespace std;
using llong = int64_t;
const int Inf = 2e9;
int t, nr, ng, nb;
void solve();
llong getMin(vector<int> R, vector<int> G, vector<int> B);
int bs_higher(int val, vector<int> v);
int bs_lower(int val, vector<int> v);
llong calc(llong x, llong y, llong z);
llong p2(int x);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
}
void solve() {
  cin >> nr >> ng >> nb;
  vector<int> R(nr), G(ng), B(nb);
  for (int i = 0; i < nr; ++i) {
    cin >> R[i];
  }
  for (int i = 0; i < ng; ++i) {
    cin >> G[i];
  }
  for (int i = 0; i < nb; ++i) {
    cin >> B[i];
  }
  sort(R.begin(), R.end());
  sort(G.begin(), G.end());
  sort(B.begin(), B.end());
  llong ans = LLONG_MAX;
  ans = min(ans, getMin(R, G, B));
  ans = min(ans, getMin(R, B, G));
  ans = min(ans, getMin(G, R, B));
  ans = min(ans, getMin(G, B, R));
  ans = min(ans, getMin(B, R, G));
  ans = min(ans, getMin(B, G, R));
  cout << ans << '\n';
}
llong getMin(vector<int> R, vector<int> G, vector<int> B) {
  llong ret = LLONG_MAX;
  for (auto x : R) {
    auto y = lower_bound(G.begin(), G.end(), x);
    auto z = upper_bound(B.begin(), B.end(), x);
    if (y == G.end() || z == G.begin()) {
      continue;
    }
    --z;
    ret = min(ret, p2(x - *y) + p2(*y - *z) + p2(x - *z));
  }
  return ret;
}
llong p2(int x) { return 1LL * x * x; }
llong calc(llong x, llong y, llong z) {
  if (x == Inf || y == Inf || z == Inf) return LLONG_MAX;
  llong xy = (x - y) * (x - y);
  llong xz = (x - z) * (x - z);
  llong yz = (y - z) * (y - z);
  return xy + xz + yz;
}
int bs_higher(int val, vector<int> v) {
  int l = 0, r = (int)v.size() - 1, mid, sol = Inf;
  while (l <= r) {
    mid = (l + r) / 2;
    if (val <= v[mid]) {
      sol = v[mid];
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return sol;
}
int bs_lower(int val, vector<int> v) {
  int l = 0, r = (int)v.size() - 1, mid, sol = Inf;
  while (l <= r) {
    mid = (l + r) / 2;
    if (val >= v[mid]) {
      sol = v[mid];
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return sol;
}
