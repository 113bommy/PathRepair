#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e6;
const long long MOD = 1e9 + 7;
using namespace std;
long long q, z, n, m, a[KL], mn = 1e9, mx = -1e9;
string t;
vector<long long> vec;
set<long long> s;
map<long long, long long> mp;
long double dist(long double x1, long double y1, long double x2,
                 long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  q = 1;
  while (q--) {
    scanf("%lld", &n);
    scanf("%lld", &m);
    if (n == 0) {
      cout << 0 << " " << 1 << endl;
      cout << 0 << " " << m << endl;
      cout << 0 << " " << 0 << endl;
      cout << 0 << " " << m - 1 << endl;
    } else if (m == 0) {
      cout << 1 << " " << 0 << endl;
      cout << n << " " << 0 << endl;
      cout << 0 << " " << 0 << endl;
      cout << n - 1 << " " << 0 << endl;
    } else {
      if (n >= m) {
        long double x = n;
        long double y = m;
        long double ans1 = sqrt(x * x + y * y) + x;
        long double ans2 = 2 * sqrt((y - 1) * (y - 1) + x * x);
        if (ans1 >= ans2) {
          cout << n << " " << m << endl;
          cout << 0 << " " << 0 << endl;
          cout << n << " " << 0 << endl;
          cout << 0 << " " << m << endl;
        } else {
          cout << 0 << " " << 1 << endl;
          cout << n << " " << m << endl;
          cout << 0 << " " << 0 << endl;
          cout << n << " " << m - 1 << endl;
        }
      } else {
        long double x = n;
        long double y = m;
        long double ans1 = sqrt(x * x + y * y) + y;
        long double ans2 = 2.0 * sqrt((x - 1) * (x - 1) + y * y);
        if (ans1 >= ans2) {
          cout << n << " " << m << endl;
          cout << 0 << " " << 0 << endl;
          cout << 0 << " " << m << endl;
          cout << n << " " << 0 << endl;
        } else {
          cout << 1 << " " << 0 << endl;
          cout << n << " " << m << endl;
          cout << 0 << " " << 0 << endl;
          cout << n - 1 << " " << m << endl;
        }
      }
    }
  }
  return 0;
}
