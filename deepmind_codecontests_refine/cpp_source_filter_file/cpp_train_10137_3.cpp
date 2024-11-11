#include <bits/stdc++.h>
using namespace std;
class PhoneNumbers {
 public:
  void solve(std::istream &in, std::ostream &out) {
    int n;
    string s;
    in >> n >> s;
    if (n & 1) {
      int limit = (int)n / 2;
      limit = 2 * (limit - 1);
      for (int i = 0; i < limit; i++) {
        if (i & 1) {
          out << s[i] << '-';
        } else
          out << s[i];
      }
      out << s[n - 1] << s[n - 2] << s[n - 3] << endl;
    } else {
      for (int i = 0; i < n; i++) {
        if ((i & 1) && i != n - 1) {
          out << s[i] << '-';
        } else
          out << s[i];
      }
    }
  }
};
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  PhoneNumbers solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);
  return 0;
}
