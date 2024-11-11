#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool cmp(long long a, long long b) { return (a > b); }
int main() {
  c_p_c();
  long long n, m;
  long long t;
  double l, h;
  double ans = 0;
  cin >> l >> h;
  double x = l * l;
  double y = h * h;
  double z = 2 * h;
  double w = x - y;
  ans = w / z;
  cout << fixed << setprecision(12) << ans;
  return 0;
}
