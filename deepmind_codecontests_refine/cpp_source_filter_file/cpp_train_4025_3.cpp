#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long M = 1e6 + 5;
const double pi = acos(-1.);
const long long dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
const long long dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, t, u, v, w, x,
    y, z, maxi, mini, ans, mid, low, high, sum, total;
string s1, s2;
int main() {
  double hh, mm, h, d, c, n, in_cost, f_cost, ans;
  cin >> hh >> mm;
  if (mm == 0) mm = 60;
  cin >> h >> d >> c >> n;
  if (hh >= 20) {
    ans = (20 * c * ceil(h / n)) / 100;
  } else {
    in_cost = c * ceil(h / n);
    k += (60 - mm);
    if (mm != 60) hh += 1;
    k += (20 - hh) * 60;
    h += k * d;
    f_cost = (80 * c * ceil(h / n)) / 100;
    ans = min(f_cost, in_cost);
  }
  cout << fixed << setprecision(5);
  cout << ans;
}
