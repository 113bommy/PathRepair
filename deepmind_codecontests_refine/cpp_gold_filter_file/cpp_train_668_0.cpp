#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = (((1 << 30) - 1) << 1) + 1;
const int nINF = 1 << 31;
int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  long long ae = 0, ao = 0, be = 0, bo = 0, e = 0, o = n;
  for (int i = 0; i < (n); i++) {
    if (s[i] == 'a') {
      if (i & 1) {
        e += ae;
        o += ao;
        ++ao;
      } else {
        e += ao;
        o += ae;
        ++ae;
      }
    } else {
      if (i & 1) {
        e += be;
        o += bo;
        ++bo;
      } else {
        e += bo;
        o += be;
        ++be;
      }
    }
  }
  cout << e << ' ' << o << endl;
  return 0;
}
