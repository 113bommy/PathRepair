#include <bits/stdc++.h>
using namespace std;
const double DINF = numeric_limits<double>::infinity();
const long long MOD = 1e9 + 7;
const double EPS = 1e-7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
mt19937 mmtw_(MOD);
uniform_int_distribution<long long> rd_;
long long randomll() { return rd_(mmtw_); }
long long rnd(long long x, long long y) { return rd_(mmtw_) % (y - x + 1) + x; }
template <class T>
T fact(T n) {
  if (n == 1) return 1;
  return n * fact(n - 1);
}
struct poly {
  int x1qwer, y1qwer, x2, y2;
};
const int MAXN = 150005;
int n;
poly a[MAXN];
poly pref[MAXN];
poly suf[MAXN];
poly inter(const poly &a, const poly &b) {
  return {max(a.x1qwer, b.x1qwer), max(a.y1qwer, b.y1qwer), min(a.x2, b.x2),
          min(a.y2, b.y2)};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x1qwer >> a[i].y1qwer >> a[i].x2 >> a[i].y2;
  }
  partial_sum(a, a + n, pref, inter);
  reverse(a, a + n);
  partial_sum(a, a + n, suf, inter);
  reverse(suf, suf + n);
  for (int i = 0; i < n; ++i) {
    poly t;
    if (i == 0)
      t = suf[1];
    else if (i == n - 1)
      t = pref[n - 2];
    else
      t = inter(pref[i - 1], suf[i + 1]);
    if (t.x1qwer <= t.x2 && t.y1qwer <= t.y2) {
      cout << t.x1qwer << ' ' << t.x2 << endl;
      return 0;
    }
  }
  assert(false);
}
