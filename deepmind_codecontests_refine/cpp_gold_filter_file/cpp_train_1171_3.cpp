#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
template <class T>
using vec = std::vector<T>;
bool __hack = std::ios::sync_with_stdio(false);
auto __hack1 = cin.tie(nullptr);
namespace template_util {
constexpr int bytecount(uint64_t x) { return x ? 1 + bytecount(x >> 8) : 0; }
template <int N>
struct bytetype {};
template <uint64_t N>
struct minimal_uint : bytetype<bytecount(N)> {};
}  // namespace template_util
int ni(istream& in) {
  int ret;
  in >> ret;
  return ret;
}
int64_t ni64(istream& in) {
  int64_t ret;
  in >> ret;
  return ret;
}
void solve(istream& in, ostream& out) {
  auto n = ni(in);
  auto h = ni64(in);
  auto m = ni64(in) / 2;
  auto k = ni(in);
  vec<pair<int64_t, int>> ts;
  for (int i = 0; i < (n); ++i) {
    auto hi = ni64(in);
    auto mi = ni64(in);
    ts.push_back({mi % m, i});
    ts.push_back({mi % m + m, i});
  }
  sort(ts.begin(), ts.end());
  pair<int, int> res{n, -1};
  int j = 0;
  for (int i = 0; i < (2 * n); ++i) {
    auto t = ts[i].first;
    while (ts[j].first <= t - k) {
      ++j;
    }
    if (i >= n) {
      res = min(res, {i - j, t % m});
    }
  }
  out << res.first << " " << res.second << "\n";
  for (int i = 0; i < (n * 2); ++i) {
    int64_t r = res.second + m, l = r - k;
    if (l < ts[i].first && ts[i].first < r) {
      out << ts[i].second + 1 << " ";
    }
  }
  out << "\n";
}
int main() {
  solve(cin, cout);
  return 0;
}
