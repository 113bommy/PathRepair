#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const int MOD = 1000000007;
const long long INFLL = 1e18;
const int INF = 1e9;
const int NMAX = 2e5 + 5;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n;
array<int, 2> a[NMAX];
struct BIT {
  long long aib[NMAX];
  void update(int pos, int val) {
    for (int i = pos + 1; i <= n; i += (i & (-i))) {
      aib[i] += val;
    }
  }
  long long query(int pos) {
    long long sum = 0;
    for (int i = pos; i >= 1; i -= (i & (-i))) {
      sum += aib[i];
    }
    return sum;
  }
} f0, f1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0];
  }
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    cin >> a[i][1];
    v.push_back(a[i][1]);
  }
  long long ans = 0;
  sort(v.begin(), v.end());
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    int pos = lower_bound(v.begin(), v.end(), a[i][1]) - v.begin();
    ans += f0.query(pos + 1) * a[i][0] - f1.query(pos + 1);
    f0.update(pos, 1);
    f1.update(pos, a[i][0]);
  }
  cout << ans;
  return 0;
}
