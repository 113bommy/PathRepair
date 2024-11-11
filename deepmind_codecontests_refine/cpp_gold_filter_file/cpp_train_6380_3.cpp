#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
bool __hack = std::ios::sync_with_stdio(false);
auto __hack1 = cin.tie(nullptr);
struct Input {
  Input(istream &in) : in(&in) {}
  template <class T>
  T next() const {
    T x;
    *in >> x;
    return x;
  }
  int ni() const { return next<int>(); }
  int64_t ni64() const { return next<int64_t>(); }
  istream *in;
};
Input in(cin);
class Output {
 private:
  ostream *out;
  template <typename T>
  void printSingle(const T &value) {
    *out << value;
  }

 public:
  Output(ostream &out) : out(&out) {}
  inline void print() {}
  template <typename T, typename... Ts>
  inline void print(const T &f, const Ts &...args) {
    printSingle(f);
    if (sizeof...(args) != 0) {
      *out << ' ';
      print(args...);
    }
  }
  template <typename... Ts>
  inline void println(const Ts &...args) {
    print(args...);
    (*out) << '\n';
  }
  template <typename... Ts>
  inline void operator()(const Ts &...args) {
    println(args...);
  }
};
Output out(cout);
namespace template_util {
constexpr int bytecount(uint64_t x) { return x ? 1 + bytecount(x >> 8) : 0; }
template <int N>
struct bytetype {};
template <uint64_t N>
struct minimal_uint : bytetype<bytecount(N)> {};
}  // namespace template_util
template <class T>
bool isPrime(T x) {
  if (x == 1) {
    return false;
  }
  if (x == 2) {
    return true;
  }
  if (x % 2 == 0) {
    return false;
  }
  for (T i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
vector<pair<int64_t, int>> factorize(int64_t number) {
  vector<pair<int64_t, int>> res;
  if (number % 2 == 0) {
    int power = 0;
    do {
      power++;
      number /= 2;
    } while (number % 2 == 0);
    res.push_back({2, power});
  }
  for (int64_t i = 3; i * i <= number; i += 2) {
    if (number % i == 0) {
      int power = 0;
      do {
        power++;
        number /= i;
      } while (number % i == 0);
      res.push_back({i, power});
    }
  }
  if (number != 1) {
    res.push_back({number, 1});
  }
  return res;
}
void solveOne() {
  auto p = in.ni64();
  auto q = in.ni64();
  if (p % q != 0) {
    out(p);
    return;
  }
  if (isPrime(q)) {
    while (p % q == 0) {
      p /= q;
    }
    out(p);
    return;
  }
  auto qFactor = factorize(q);
  int64_t res = 1;
  for (const auto &f : qFactor) {
    auto P = p;
    while (P % f.first == 0) {
      P /= f.first;
    }
    for (int j = 0; j < (f.second - 1); ++j) {
      P *= f.first;
    }
    res = max(res, P);
  }
  out(res);
}
void solve(istream &inStream, ostream &outStream) {
  in = Input(inStream);
  out = Output(outStream);
  auto tests = in.ni();
  while (tests--) {
    solveOne();
  }
}
int main() {
  solve(cin, cout);
  return 0;
}
