#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using pii = std::pair<long long, long long>;
using namespace std;
long long t, x;
string s;
class ACutAndPaste {
 public:
  void solve(std::istream& in, std::ostream& out) {
    in >> t;
    for (long long cases = (0); cases < (t); cases++) {
      in >> x >> s;
      long long pos = 0;
      while (s.length() < x) {
        if (pos == s.length() - 1) break;
        string ss = s.substr(pos + 1, s.length() - 1 - pos);
        for (long long i = (0); i < (s[pos] - '1'); i++) s += ss;
        pos++;
      }
      long long ans = s.length();
      for (long long i = (pos); i < (x); i++) {
        long long len = (ans - (i + 1));
        ans += ((len * (s[i] - '1')) % MOD);
        if (ans >= MOD) ans %= MOD;
      }
      out << ans << "\n";
    }
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ACutAndPaste solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
