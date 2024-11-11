#include <bits/stdc++.h>
using namespace std;
class TaskG {
 public:
  void solve(istream& in, ostream& out) {
    int res;
    in >> res;
    char op;
    while (in >> op) {
      int x;
      in >> x;
      if (op == '+') {
        res += x;
      } else {
        res -= x;
      }
    }
    string s = to_string(res);
    for (int i = 0; i < (int)s.size(); ++i) {
      int x = s[i];
      for (int j = 0; j < x; ++j) {
        out << '+';
      }
      out << ".>";
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  TaskG solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
