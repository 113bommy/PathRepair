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
using std::iota;
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
long long rnd(long long x, long long y) {
  static auto gen = std::bind(std::uniform_int_distribution<long long>(),
                              std::mt19937(960172));
  return gen() % (y - x + 1) + x;
}
long long gcd(long long a, long long b) {
  while (b > 0) {
    long long t = a % b;
    a = b;
    b = t;
  }
  return a;
}
template <typename T>
T sqr(T const& a) {
  return a * a;
}
int const INF = 100 + (int)1e9;
long long const INFL = 100 + (long long)1e18;
long double const PI = 3.1415926535897932384626433832795028;
void solve() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
      printf("%.9f\n", b == 0 ? 1. : .5);
      continue;
    }
    if (b == 0) {
      printf("1\n");
      continue;
    }
    b *= 4;
    if (a >= b) {
      printf("%.9f\n", 1 - 0.5 * b * b / (2.0 * a * b));
    } else {
      printf("%.9f\n", 1 - 0.5 * a * (b + b - a) / (2.0 * a * b));
    }
  }
}
int main() {
  cout.precision(15);
  cout << fixed;
  cerr.precision(6);
  cerr << fixed;
  solve();
}
