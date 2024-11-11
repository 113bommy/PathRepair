#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << '(' << p.first << ',' << p.second << ')';
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  os << '[';
  for (int i = 0; i < (int)(a.size()); i++) os << (i ? " " : "") << a[i];
  return os << ']';
}
class Solver {
  const int INF = 1 << 29;
  const double EPS = 1e-10;
  double zero(double d) { return d < EPS ? 0.0 : d; }
  const int M = 1000000007;

 public:
  Solver() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(8);
    ios_base::sync_with_stdio(false);
  }
  long long make_pair(int t) {
    long long a = 1ll;
    for (int i = 0; i < (int)(t); i++) a *= 10;
    return (long long)a;
  }
  void solve() {
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < (int)(n); i++) cin >> s[i];
    sort(s, s + n);
    int t = 0;
    for (int i = 1; i < (int)(n); i++) {
      if (s[t] * 2 <= s[i]) {
        t++;
      }
    }
    cout << max((int)ceil(n / 2), n - t) << endl;
  }
};
int main() {
  Solver sb;
  sb.solve();
  return 0;
}
