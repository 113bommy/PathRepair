#include <bits/stdc++.h>
using namespace std;
const long double PI = 2 * acos(0);
const long long INF = 1e6;
const long double EPS = 1e-5;
long long n, m;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  while (T--) {
    cin >> n >> m;
    if (m == 3) {
      if (n == 3)
        cout << "3 0\n0 0\n0 3\n";
      else if (n == 4)
        cout << "3 0\n0 0\n0 3\n1 1\n";
      else
        cout << "-1\n";
      return 0;
    }
    for (long long i = 0; i < m; i++) {
      long double a = 2 * PI / m * i;
      long long sa = sin(a) * INF, ca = cos(a) * INF;
      cout << sa << ' ' << ca << '\n';
      if (i < n - m) {
        a += EPS;
        sa = sin(a) * INF;
        ca = cos(a) * INF;
        cout << sa / 2 << ' ' << ca / 2 << '\n';
      }
    }
  }
  return 0;
}
