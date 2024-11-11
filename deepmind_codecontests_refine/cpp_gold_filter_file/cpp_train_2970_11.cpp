#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
const int maxn = 100005;
double p, r;
void solve() {
  cin >> p >> r;
  double x = r * sin(PI / p) / sin((1.5 * PI) / p);
  printf("%.20f", r * x * p * sin(PI / (2.0 * p)));
}
int main() {
  solve();
  return 0;
}
