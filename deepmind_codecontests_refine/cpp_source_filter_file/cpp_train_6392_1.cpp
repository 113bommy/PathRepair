#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 1e-9;
const int N = (int)1e5 + 5;
const int INF = (int)1e9 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cout.flags(ios::fixed);
  cout.precision(13);
  long double m, r;
  cin >> m >> r;
  long double ttt = 2 * r * m;
  for (int i = 1; i < m + 1; i++) {
    ttt += 2 * r *
           (((i - 1) * (i - 2)) / 2 + (m - i) * (m - i - 1) / 2 +
            (i > 1 ? 1 : 0) + (m - i ? 1 : 0));
    ttt += max((long double)(0.0), 2 * (i - 2) * sqrt(2 * r * r));
    ttt += max((long double)(0.0), 2 * (m - i - 1) * sqrt(2 * r * r));
    ttt += ((i - 1) ? sqrt(2 * r * r) : 0);
    ttt += ((m - i) ? sqrt(2 * r * r) : 0);
  }
  cout << ttt / (m * m);
  return 0;
}
