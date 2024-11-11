#include <bits/stdc++.h>
template <typename T>
T GCD(T a, T b) {
  return a ? GCD(b % a, a) : b;
}
template <typename T>
T LCM(T a, T b) {
  return (a * b) / GCD(a, b);
}
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  for (auto ob : v) os << ob << " ";
  return os;
}
template <typename T, typename S>
std::ostream &operator<<(std::ostream &os, const std::map<T, S> &v) {
  for (auto ob : v) os << ob.first << " : " << ob.second << std::endl;
  return os;
}
using ld = double;
using ll = long long int;
using ul = unsigned long long int;
using namespace std;
class ADigitGame {
 public:
  void solve(std::istream &in, std::ostream &out) {
    int n;
    string s;
    in >> n >> s;
    if (n & 1) {
      for (int i = 0; i < s.size(); i += 2) {
        if ((s[i] - '0') & 1) {
          out << 1 << endl;
          return;
        }
      }
      out << 2 << endl;
    } else {
      for (int i = 0; i < s.size(); i += 2) {
        if ((s[i] - '0') % 2 == 0) {
          out << 2 << endl;
          return;
        }
      }
      out << 1 << endl;
    }
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ADigitGame solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  int n;
  in >> n;
  for (int i = 0; i < n; ++i) {
    solver.solve(in, out);
  }
  return 0;
}
