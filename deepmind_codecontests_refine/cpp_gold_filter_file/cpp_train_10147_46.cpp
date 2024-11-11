#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pii = pair<int, int>;
using pll = pair<lint, lint>;
template <typename T>
using vc = vector<T>;
template <typename T>
using vvc = vector<vector<T>>;
template <typename T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
constexpr lint ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
class DVasyaAndChess {
 public:
  void solve(std::istream& in, std::ostream& out) {
    ios_base::sync_with_stdio(false);
    in.tie(nullptr), out.tie(nullptr);
    int N;
    in >> N;
    if (N % 2 == 0) {
      out << "white\n";
      out << "1 2\n";
    } else {
      out << "black\n";
    }
  }
};
int main() {
  DVasyaAndChess solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
