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
int const L = 3;
int const R = 1;
int const dx[] = {0, 1, 0, -1};
int const dy[] = {1, 0, -1, 0};
int const N = 55;
struct state {
  int x, y;
  int dp;
  int cp;
  state& go() const;
};
state where[N][N][4][4];
state& state::go() const { return where[x][y][dp][cp]; }
int n, m;
char s[N][N];
bool is_in(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
pair<int, int> get_first(int i, int j) {
  int c = s[i][j];
  while (i && s[i - 1][j] == c) {
    --i;
  }
  while (j && s[i][j - 1] == c) {
    --j;
  }
  return {i, j};
}
bool is_first(int i, int j) {
  if (!is_in(i, j) || s[i][j] == '0') {
    return false;
  }
  auto f = get_first(i, j);
  return f.first == i && f.second == j;
}
void solve() {
  int steps;
  cin >> n >> steps;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  m = strlen(s[0]);
  for (int dp = 0; dp < 4; ++dp) {
    for (int cp : {L, R}) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (is_first(i, j)) {
            state now = {i, j, dp, cp};
            int x = i, y = j, c = s[i][j];
            while (is_in(x + dx[dp], y + dy[dp]) &&
                   s[x + dx[dp]][y + dy[dp]] == c) {
              x += dx[dp];
              y += dy[dp];
            }
            int dr = (dp + cp) % 4;
            while (is_in(x + dx[dr], y + dy[dr]) &&
                   s[x + dx[dr]][y + dy[dr]] == c) {
              x += dx[dr];
              y += dy[dr];
            }
            int xx = x + dx[dp];
            int yy = y + dy[dp];
            if (is_in(xx, yy) && s[xx][yy] != '0') {
              auto f = get_first(xx, yy);
              now.go() = {f.first, f.second, dp, cp};
            } else {
              if (cp == L) {
                now.go() = {i, j, dp, R};
              } else {
                now.go() = {i, j, (dp + R) % 4, L};
              }
            }
          }
        }
      }
    }
  }
  state v = {0, 0, 0, L};
  for (int i = 0; i < steps; ++i) {
    v = v.go();
  }
  cout << s[v.x][v.y] << endl;
}
int main() {
  cout.precision(15);
  cout << fixed;
  cerr.precision(6);
  cerr << fixed;
  solve();
}
