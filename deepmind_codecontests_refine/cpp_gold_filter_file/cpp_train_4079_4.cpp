#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e5;
const int MAX = 2e5 + 10;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int v1 = -INF, v2 = INF, v3 = INF, v4 = -INF;
    int n;
    cin >> n;
    for (int i = (1); i <= (n); ++i) {
      int x, y, a1, a2, a3, a4;
      cin >> x >> y >> a1 >> a2 >> a3 >> a4;
      if (a1 == 0) {
        v1 = max(v1, x);
      }
      if (a2 == 0) {
        v2 = min(v2, y);
      }
      if (a3 == 0) {
        v3 = min(v3, x);
      }
      if (a4 == 0) {
        v4 = max(v4, y);
      }
    }
    if (v3 >= v1 && v4 <= v2) {
      cout << "1 " << v1 << ' ' << v2 << '\n';
    } else
      cout << '0' << '\n';
  }
}
