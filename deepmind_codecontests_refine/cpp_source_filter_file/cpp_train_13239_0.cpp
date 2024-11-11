#include <bits/stdc++.h>
using namespace std;
class ABowWowAndTheTimetable {
 public:
  int N;
  string S;
  void input(std::istream& in, std::ostream& out) {
    ios_base::sync_with_stdio(false);
    in >> S;
    N = (int)(S).size();
  }
  void solve(std::istream& in, std::ostream& out) {
    input(in, out);
    int d = 0;
    for (int(i) = (1); (i) < (N - 1 + 1); ++(i))
      if (S[i] == '1') d++;
    if (d == 0 and N % 2 == 0) d++;
    out << (N - 1) / 2 + d << '\n';
  }
};
int main() {
  ABowWowAndTheTimetable solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
