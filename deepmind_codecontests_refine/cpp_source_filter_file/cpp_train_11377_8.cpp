#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
template <class T>
using vec = std::vector<T>;
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
  string ns() const { return next<string>(); }
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
void solve(istream &inStream, ostream &outStream) {
  in = Input(inStream);
  out = Output(outStream);
  auto n = in.ni();
  auto s = in.ns();
  vec<int> suffLen(n);
  vec<int> maxUntilHere(n);
  suffLen[0] = s[0] == '1' ? 1 : 0;
  for (int i = (1); i < (n); ++i) {
    if (s[i] == '1') {
      suffLen[i] = 1 + suffLen[i - 1];
    } else {
      suffLen[i] = 0;
    }
  }
  vec<int64_t> dp(n);
  dp[0] = suffLen[0];
  vec<pair<int, int>> st;
  if (suffLen[0] == 1) {
    st.push_back({1, 0});
  }
  for (int i = (1); i < (n); ++i) {
    if (s[i] == '0') {
      dp[i] = dp[i - 1];
    } else {
      int len = suffLen[i];
      int64_t cur = (1 + len) * len / 2;
      while (!st.empty() && st.back().first <= len) {
        st.pop_back();
      }
      if (st.empty()) {
        cur += len * (i + 1 - len);
      } else {
        pair<int, int> pp = st.back();
        int j = pp.second;
        cur += len * (i - j);
        cur += (dp[j] - (1 + len) * len / 2);
      }
      st.push_back({len, i});
      dp[i] = cur;
    }
  }
  int64_t sum = accumulate(dp.begin(), dp.end(), int64_t(0));
  out(sum);
}
int main() {
  solve(cin, cout);
  return 0;
}
