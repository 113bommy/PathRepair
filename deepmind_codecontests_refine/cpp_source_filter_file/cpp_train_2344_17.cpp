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
int const N = 1100100;
int MOD;
void add(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}
int mul(int a, int b) { return (long long)a * b % MOD; }
int a[N];
int go(int x, int k, int b, long long cnt) {
  if (cnt == 0) {
    return x;
  }
  if (cnt % 2 == 1) {
    --cnt;
    x = mul(k, x);
    add(x, b);
  }
  int k1 = mul(k, k);
  int b1 = mul(k, b);
  add(b1, b);
  return go(x, k1, b1, cnt / 2);
}
void mul(int& a, int& b, int& c, int& d, int A, int B, int C, int D) {
  int a1 = mul(a, A);
  add(a1, mul(b, C));
  int b1 = mul(a, B);
  add(b1, mul(b, D));
  int c1 = mul(c, A);
  add(c1, mul(d, C));
  int d1 = mul(c, B);
  add(d1, mul(d, D));
  a = a1;
  b = b1;
  c = c1;
  d = d1;
}
int fib(long long x) {
  int a = 1, b = 1, c = 1, d = 0;
  int A = 1, B = 0, C = 0, D = 1;
  for (; x > 0; x /= 2) {
    if (x % 2 == 1) {
      mul(A, B, C, D, a, b, c, d);
    }
    mul(a, b, c, d, a, b, c, d);
  }
  return A;
}
void solve() {
  int n;
  long long x, y;
  scanf(
      "%d"
      "%lld"
      "%lld"
      "%d",
      &n, &x, &y, &MOD);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[i] %= MOD;
    add(sum, a[i]);
  }
  int del = 0;
  add(del, -a[0]);
  add(del, -a[n - 1]);
  int afterX = go(sum, 3, del, x);
  int newMax;
  if (x == 0) {
    newMax = a[n - 1];
  } else {
    newMax = mul(fib(x - 1), a[n - 1]);
    add(newMax, mul(fib(x), a[n - 2]));
  }
  int del1 = 0;
  add(del1, -a[0]);
  add(del1, -newMax);
  int ans = go(afterX, 3, del1, y);
  printf("%d\n", ans);
}
int main() {
  cout.precision(15);
  cout << fixed;
  cerr.precision(6);
  cerr << fixed;
  srand(1510);
  solve();
}
