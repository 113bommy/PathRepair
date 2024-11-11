#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
const long long INF = 1e18 + 5;
const long long mxn = 1e6 + 5;
const int mod = 1e9 + 7, pa = 1e6 + 7;
long long a[mxn], b[mxn];
map<pair<int, int>, int> m;
int x[mxn], y[mxn];
string second[5555];
char u[5555];
int main() {
  int q;
  cin >> q;
  while (q--) {
    double a, b;
    cin >> a >> b;
    double x, y;
    if (b == 0.0) {
      cout << 1.000000000 << endl;
      continue;
    }
    if (a == 0.0) {
      cout << 0.5 << endl;
      continue;
    }
    y = a * b;
    double p = 0.0;
    if (a / 4 > b) p = a - (b * 4), p *= b, a = b * 4;
    x = a;
    x *= a;
    x /= 8;
    x /= y;
    x /= 2;
    x += 0.5;
    p /= 2;
    p /= y;
    x += p;
    cout << fixed << setprecision(9) << x << endl;
  }
  return 0;
}
