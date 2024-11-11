#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[] = {0, -1, 0, 1, 1, -1, 1, -1};
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long ceil1(long long a, long long b) { return (a + b - 1) / b; }
void read(vector<long long>& arr) {
  for (long long i = 0; i < int(arr.size()); i++) cin >> arr[i];
}
const long long is_query = -(1LL << 62);
struct Line {
  long long m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    long long x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
struct HullDynamic : public multiset<Line> {
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (long double)(x->b - y->b) * (z->m - y->m) >=
           (long double)(y->b - z->b) * (y->m - x->m);
  }
  void insert_line(long long m, long long b) {
    auto y = insert({m, b});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  long long eval(long long x) {
    auto l = *lower_bound((Line){x, is_query});
    return l.m * x + l.b;
  }
};
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  vector<long long> pref(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  pref[0] = arr[0];
  for (long long i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + arr[i];
  }
  long long sum = 0;
  for (long long i = 0; i < n; i++) sum += arr[i] * (i + 1);
  long long ans = sum;
  HullDynamic hd;
  hd.insert_line(n - 1, -pref[n - 1]);
  for (long long i = n - 2; i >= 0; i--) {
    long long alpha = hd.eval(arr[i]);
    long long extra = arr[i] * i - pref[i];
    ans = max(ans, sum + alpha - extra);
    hd.insert_line(i, -pref[i]);
  }
  HullDynamic hd2;
  hd2.insert_line(0, 0);
  for (long long i = 1; i < n; i++) {
    long long alpha = hd2.eval(arr[i]);
    long long extra = pref[i - 1] - arr[i] * i;
    ans = max(ans, sum + alpha + extra);
    hd2.insert_line(i, -pref[i - 1]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
