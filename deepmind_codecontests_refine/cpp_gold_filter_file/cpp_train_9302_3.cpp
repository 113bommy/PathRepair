#include <bits/stdc++.h>
using namespace std;
inline void outarrint1(vector<int>& a, int n, char separator, ostream& out) {
  for (int i = 1; i <= n; i++) out << a[i] << separator;
}
class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int n, d, l;
    in >> n >> d >> l;
    vector<int> seq(n + 1, 1);
    int mnsod = (n + 1) / 2;
    int mxsod = l * ((n + 1) / 2);
    int sumev = n / 2;
    if (d + sumev > mxsod)
      out << -1 << '\n';
    else if (d + sumev * l < mnsod)
      out << -1 << '\n';
    else {
      int sum = d + sumev;
      int ind = 2;
      while (sum < mnsod) {
        seq[ind]++;
        sum++;
        ind += 2;
        if (ind > n) ind = 2;
      }
      ind = 1;
      while (mnsod < sum) {
        seq[ind]++;
        mnsod++;
        ind += 2;
        if (ind > n) ind = 1;
      }
      outarrint1(seq, n, ' ', out);
      out << '\n';
    }
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << fixed << std::setprecision(6);
  Solution solution;
  solution.solve(in, out);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
