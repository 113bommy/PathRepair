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
  static auto gen =
      std::bind(std::uniform_int_distribution<long long>(), std::mt19937(1510));
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
int const INF = 100 + (int)1e9;
long long const INFL = 100 + (long long)1e18;
long double const PI = 3.1415926535897932384626433832795028;
void solve() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> d(n);
  for (int i = 0; i < n; ++i) {
    d[i].resize(n);
    for (int j = 0; j < n; ++j) {
      scanf("%d", &d[i][j]);
    }
  }
  int qs;
  scanf("%d", &qs);
  for (int q = 0; q < qs; ++q) {
    int a, b, len;
    scanf("%d%d%d", &a, &b, &len);
    --a, --b;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        d[i][j] = min(d[i][j], d[i][a] + len + d[b][j]);
        d[i][j] = min(d[i][j], d[i][b] + len + d[a][j]);
        res += d[i][j];
      }
    }
    printf(
        "%lld"
        "\n",
        res / 2);
  }
}
int main() {
  cout.precision(15);
  cout << fixed;
  cerr.precision(6);
  cerr << fixed;
  solve();
}
