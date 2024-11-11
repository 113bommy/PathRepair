#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int mod = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = 2 * acos(0);
int n, r, v;
int s, f;
double calc(double x, int sig) {
  double l = 0, r = 1e9;
  for (int _ = (0); _ < (100); _++) {
    double m = (l + r) / 2;
    if (m + sig * sin(m) < x)
      l = m;
    else
      r = m;
  }
  return l;
}
void solve() {
  scanf("%d%d%d", &n, &r, &v);
  for (int i = (0); i < (n); i++) {
    scanf("%d%d", &s, &f);
    int d = f - s;
    printf("%0.6f\n", min(calc(1.0 * d / 2 / r, 1), calc(1.0 * d / 2 / r, -1)) *
                          2 * r / v);
  }
}
int main() {
  solve();
  return 0;
}
