#include <bits/stdc++.h>
using namespace std;
class TaskC {
 public:
  void solve(std::istream& in, std::ostream& out) {
    long long int k, d, t;
    in >> k >> d >> t;
    if (k % d == 0) {
      out << t;
      return;
    }
    long long int cycle = (k / d) * d + (k % d == 0 ? 0 : d);
    long double cycle_cook = (long double)k + (long double)(cycle - k) / 2;
    long double res = floor(((long double)t / cycle_cook)) * cycle;
    long double remain = t - cycle_cook * floor(((long double)t / cycle_cook));
    if (remain <= k) {
      res += remain;
    } else {
      res += remain;
      remain -= k;
      res += (remain / 2);
    }
    out << setprecision(9) << fixed;
    out << res;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskC solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
