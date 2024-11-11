#include <bits/stdc++.h>
using namespace std;
class AAlarmClock {
 public:
  static void solve(std::istream& cin, std::ostream& cout) {
    int64_t t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
      double a, b, c, d;
      cin >> a >> b >> c >> d;
      int64_t ans = 0;
      ans += b;
      if (a > b) {
        if (d >= c) {
          cout << -1 << endl;
          continue;
        } else {
          ans += c * ceil((a - b) / (c - d));
          printf("%llu\n", ans);
        }
      } else {
        cout << ans << endl;
      }
    }
  }
};
int main() {
  AAlarmClock solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
