#include <bits/stdc++.h>
using std::abs;
using std::bitset;
using std::cerr;
using std::cin;
using std::copy;
using std::cout;
using std::deque;
using std::endl;
using std::fill;
using std::fixed;
using std::greater;
using std::istream;
using std::lower_bound;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
using std::multiset;
using std::next_permutation;
using std::nth_element;
using std::ostream;
using std::pair;
using std::priority_queue;
using std::queue;
using std::reverse;
using std::rotate;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::tie;
using std::tuple;
using std::unique;
using std::unordered_map;
using std::unordered_set;
using std::upper_bound;
using std::vector;
int const INF = (int)1e9;
long long const INFL = (long long)1e18;
long double const PI = 3.1415926535897932384626433832795028;
int const A = 890890;
int const AA = 955;
int const L = 35;
int mex[A];
int cnt[A];
int pref[A + 1][L];
int calcR(long long v, int type) {
  int l = 0;
  int r = type == 2 ? A : AA;
  while (r - l > 1) {
    int m = (l + r) / 2;
    long long val = (long long)m * m;
    if (type == 4) val *= val;
    if (val > v || (val == v && type == 4)) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}
int calcMex(long long v) {
  if (v < A) return mex[v];
  int r4 = calcR(v, 4);
  int r2 = calcR(v, 2);
  for (int res = 0; res < L; ++res) {
    if (pref[r4][res] == pref[r2][res]) {
      return res;
    }
  }
  assert(false);
}
void solve() {
  mex[0] = 0;
  int r4 = 0, r2 = 1;
  cnt[0] = 1;
  pref[0][1] = 0;
  for (int i = 1; i < A; ++i) {
    while (r4 * r4 * r4 * r4 < i) {
      --cnt[mex[r4]];
      ++r4;
    }
    while (r2 < i && r2 * r2 <= i) {
      ++cnt[mex[r2]];
      ++r2;
    }
    while (cnt[mex[i]]) {
      ++mex[i];
    }
    copy(pref[i], pref[i] + L, pref[i + 1]);
    ++pref[i + 1][mex[i]];
  }
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    long long x;
    scanf("%lld", &x);
    int cur = calcMex(x);
    ans ^= cur;
  }
  cout << (ans ? "Furlo" : "Rublo") << endl;
}
int main() {
  cout.precision(15);
  cout << fixed;
  cerr.precision(6);
  cerr << fixed;
  srand(1510);
  solve();
}
