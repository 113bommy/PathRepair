#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void stop() {}
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int n;
double m;
vector<double> a;
bool foo(double s) {
  double sum = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > s) {
      sum += a[i] - s;
      sum -= (a[i] - s) * m;
    } else {
      sum -= (s - a[i]);
    }
  return sum >= 0;
}
int main() {
  fast();
  cout << fixed << setprecision(6);
  cin >> n >> m;
  m /= 100;
  a = vector<double>(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  double lo = 0, hi = 1000, ans = 0;
  while (hi - lo > 1e-9) {
    double mid = (lo + hi) / 2.00;
    if (foo(mid))
      ans = mid, lo = mid;
    else
      hi = mid;
  }
  cout << ans;
  stop();
  return 0;
}
