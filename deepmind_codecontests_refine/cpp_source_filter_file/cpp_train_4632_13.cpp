#include <bits/stdc++.h>
using std::endl;
using std::istream;
using std::ostream;
static const int MAX_N = 999;
static int marks_array[MAX_N];
class Problem {
 public:
  Problem(istream& in) : sum(0), good_marks(0), marks(marks_array) {
    in >> N >> K >> P >> X >> Y;
    read_arr(in);
  }
  void solve_and_print(ostream&) const;

 private:
  void read_arr(istream&);
  int N, K, P, X, Y;
  int sum;
  int good_marks;
  int* const marks;
};
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  Problem p(std::cin);
  p.solve_and_print(std::cout);
  return 0;
}
void Problem::read_arr(istream& in) {
  for (int ii = 0; ii < K; ++ii) {
    int ai;
    in >> ai;
    sum += ai;
    if (ai >= Y) ++good_marks;
  }
}
void Problem::solve_and_print(ostream& out) const {
  int ii = K;
  int new_sum = sum;
  {
    static const int need_y = (N + 1) / 2;
    const int cnt_y = need_y - good_marks;
    const int end = ii + cnt_y;
    if (end >= N) {
      out << "-1" << endl;
      return;
    }
    while (ii < end) new_sum += (marks[ii++] = Y);
  }
  while (ii < N) {
    marks[ii++] = 1;
    ++new_sum;
  }
  if (new_sum > X) {
    out << "-1" << endl;
    return;
  }
  static const char space[] = " ";
  const char* delim = space + 1;
  for (ii = K; ii < N; ++ii, delim = space) out << delim << marks[ii];
  out << endl;
}
