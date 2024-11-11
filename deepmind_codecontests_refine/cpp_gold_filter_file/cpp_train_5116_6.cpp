#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vii = vector<int>;
template <typename T>
int ex(const T& x) {
  return (cout << x), 0;
}
int ex() { return 0; }
int n, k;
vector<int> v;
int check(int id) {
  assert(id != v.size());
  vector<int> t(v.begin(), v.begin() + id + 1);
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  ll h = 0;
  for (int i = 0; i <= id; i += 2) h += t[i];
  return h <= k;
}
int bins(int l, int r) {
  if (r - l < 2) {
    if (check(r)) return r;
    if (check(l)) return l;
    return -1;
  }
  int mid = (l + r) / 2;
  if (check(mid)) return bins(mid, r);
  return bins(l, mid);
}
int main() {
  cin >> n >> k;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int ans = bins(0, n - 1);
  assert(ans != -1);
  cout << ans + 1;
  return 0;
}
