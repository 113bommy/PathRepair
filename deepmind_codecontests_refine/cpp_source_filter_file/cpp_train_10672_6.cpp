#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, OO = 0x3f3f3f3f;
class CWetSharkAndFlowers {
 public:
  void solve(istream& cin, ostream& cout) {
    int n, p;
    int divByP[N] = {}, lenOfIntervel[N] = {};
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      divByP[i] = (r / p) - (l - 1) / p;
      lenOfIntervel[i] = r - l + 1;
    }
    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
      int j = (i + 1) % n;
      ans += (double)((divByP[i] * divByP[j]) +
                      (divByP[i] * (lenOfIntervel[j] - divByP[j])) +
                      (divByP[j] * (lenOfIntervel[i] - divByP[i]))) /
             (lenOfIntervel[i] * lenOfIntervel[j]);
    }
    cout << fixed << setprecision(6) << (ans * 2000.0) << '\n';
  }
};
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  CWetSharkAndFlowers solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
