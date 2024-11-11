#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9, M = 1e3 + 3, MOD = 1e9 + 7, OO = 1e9;
const long long INF = 1e15;
void runtestcase() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  double res = (1.0 * a / b);
  double r = (1 - (1.0 * c / d)) * res;
  res /= (1 - r);
  cout << res;
}
int main() {
  cout << fixed << setprecision(12), ios::sync_with_stdio(false),
      cin.tie(nullptr), cout.tie(nullptr);
  int t = 1, tt = 1;
  while (t--) {
    runtestcase();
    ++tt;
  }
}
